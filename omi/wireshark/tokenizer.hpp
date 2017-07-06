#ifndef OMI_WIRESHARK_TOKENIZER_HPP_
#define OMI_WIRESHARK_TOKENIZER_HPP_

#include <omi/types/frame.hpp>
#include <omi/types/timestamp.hpp>

#include <iso646.h>

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
    bool frame(omi::frame &field) {
        if (not token()) { return false; }

        uint64_t value = 0;
        for (; *current != delimiter and *current != '\0'; current++) {
            if (*current < '0' or *current > '9') { return false; }
            value = (value * 10) + (*current - '0');
        }
        if (current != nullptr) { current++; }
        field = omi::frame(value);
        return true;
    }

    // Optimized wireshark timestamp parse method
    bool wireshark(omi::timestamp &field) {
        if (not token()) { return false; }

        uint64_t seconds{ 0 };
        for (; *current != delimiter and *current != '\0' and *current != dot; current++) {
            if (*current < '0' or *current > '9') { return false; }
            seconds = (seconds * 10) + (*current - '0');
        }

        uint64_t nanoseconds{ 0 };
        if (*current == dot) {
            auto precision = 0;
            current++;
            for (; *current != delimiter and *current != '\0' ; current++, precision++) {
                if (*current < '0' or *current > '9') { return false; }
                nanoseconds = (nanoseconds * 10) + (*current - '0');
            }

            if (precision < 9) {
                nanoseconds *= 9 - precision;
            } else if (precision > 9) {
                nanoseconds /= precision - 9;
            }
        }

        if (current != nullptr) { current++; }
        
        field = omi::timestamp(seconds, nanoseconds);
        
        return true;
    }

  //// Utility Methods ////////////

    // Does string have another token?
    bool token() const {
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
