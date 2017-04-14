#ifndef OMI_WIRESHARK_TOKENIZER_HPP_
#define OMI_WIRESHARK_TOKENIZER_HPP_

#include <omi/wireshark/frame.hpp>

// Optimized wireshark tokenizer

namespace omi {
namespace wireshark {

class tokenizer {

  //// Member Variables ///////////

    char *current = nullptr;   // Pointer to start of current token
    char delimiter;            // Token delimiter

public:
  //// Construction ///////////

    static constexpr char comma = ',';
    static constexpr char dot = '.';

    // Parse c++ string
    explicit tokenizer(const std::string &source, char delimiter = comma)
      : current{const_cast<char *>(source.c_str())}, delimiter{ delimiter } {}

    // Parse c string
    explicit tokenizer(char *source, char delimiter = comma)
      : current{ source }, delimiter{ delimiter } {}

  //// Parse Methods //////////////

    // Generic parse token from source to field
    bool string(std::string &field) {
        if (not token()) { return false; }

        auto next = find(current, delimiter);
        if (next) {
            field.assign(current, next);
            current = ++next;
            return true;
        }

        field.assign(current);
        current = nullptr;
        return true;
    }

    // Optimized wireshark frame number parse method
    bool frame(frame::number &field) {
        if (not token()) { return false; }

        auto value = 0;
        for (; *current != delimiter and *current != '\0'; current++) {
            if (*current < '0' or *current > '9') { return false; }
            value = (value * 10) + (*current - '0');
        }
        if (current != nullptr) { current++; }
        field = value;
        return true;
    }

    // Optimized wireshark timestamp parse method
    bool timestamp(frame::time &field) {
        if (not token()) { return false; }

        auto value = 0.0;
        for (; *current != delimiter and *current != '\0' and *current != dot; current++) {
            if (*current < '0' or *current > '9') { return false; }
            value = (value * 10) + (*current - '0');
        }

        if (*current == dot) {
            auto decimal = 0.0;
            auto precision = 0;
            current++;
            for (; *current != delimiter and *current != '\0' ; current++, precision++) {
                if (*current < '0' or *current > '9') { return false; }
                decimal = (decimal * 10) + (*current - '0');
            }
            value += decimal / std::pow(10.0, precision);
        }

        if (current != nullptr) { current++; }
        
        field = value;
        
        return true;
    }

  //// Utility Methods ////////////

    // Does string have another token?
    bool token() const { // rename
        return current != nullptr;
    }

    // Search for next token
    static char *find(const char *s, const char c) {
        for (; *s != c; s++) {
            if (*s == '\0') { return nullptr; }
        }
        
        return const_cast<char *>(s);
    }
};

} }

#endif
