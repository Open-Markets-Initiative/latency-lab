#ifndef OMI_EXAMPLE_OUTBOUND_EVENT_HPP_
#define OMI_EXAMPLE_OUTBOUND_EVENT_HPP_

#include <omi/wireshark/tokenizer.hpp>

// Example cme outbound order record

namespace cme {

struct fix {

  //// Member Variables ///////////

    // Event description
    static constexpr char * description = "ilink fix message";

    // Outbound triggered event fields (cme fix)
    omi::frame frame;
    omi::timestamp timestamp;
    std::string tag9702;
    std::string tag9717;
    std::string value9702;
    std::string value9717;

    uint32_t line;
    bool processed { false };

  //// Construction ///////////////

    // Construct from csv record string
    explicit fix(const std::string &record, uint32_t number = 0) : line{ number } {
        auto parse = omi::wireshark::tokenizer{ record };
        processed = parse.wireshark(frame) and 
                    parse.wireshark(timestamp) and
                    parse.string(tag9702) and
                    parse.string(tag9717) and
                    parse.string(value9702) and
                    parse.string(value9717);
    }

  //// Methods ////////////////////

    // Return event id
    std::string id() const noexcept {
        return value9717;
    }

    // Return record timestamp
    omi::timestamp time() const noexcept {
        return timestamp;
    }

    // Return event info
    omi::frame info() const noexcept {
        return frame;
    }

    // Is record valid?
    bool valid() const noexcept {
        return processed;
    }
};

}

#endif