#ifndef OMI_EXAMPLE_OUTBOUND_EVENT_HPP_
#define OMI_EXAMPLE_OUTBOUND_EVENT_HPP_

#include <omi/wireshark/tokenizer.hpp>

// Example tshark filtered outbound event

namespace example {

class outbound {

    // Outbound triggered event (cme fix fields)
    omi::frame frame;
    omi::timestamp timestamp;
    std::string tag9702;
    std::string tag9717;
    std::string value9702;
    std::string value9717;

    uint32_t line;
    bool processed { false };

  public:

    // Identifier type
    using identifier = std::string;

    // Event description
    static constexpr char * description = "ilink fix message";

    // Construct from record
    explicit outbound(const std::string &record, uint32_t number = 0) : line{ number } {
        auto tokenize = omi::wireshark::tokenizer{ record };
        processed = tokenize.frame(frame) and 
                    tokenize.wireshark(timestamp) and
                    tokenize.string(tag9702) and
                    tokenize.string(tag9717) and
                    tokenize.string(value9702) and
                    tokenize.string(value9717);
    }

  //// Interface //////////////////

    // Return event id
    identifier id() const noexcept {
        return value9717;
    }

    // Return record timestamp
    omi::timestamp time() const noexcept {
        return timestamp;
    }

    // Is record valid?
    bool valid() const noexcept {
        return processed;
    }
};

}

#endif
