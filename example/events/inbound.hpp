#ifndef OMI_EXAMPLE_INBOUND_EVENT_HPP_
#define OMI_EXAMPLE_INBOUND_EVENT_HPP_

#include <omi/wireshark/event.hpp>
#include <omi/wireshark/tokenizer.hpp>

// Example tshark filtered inbound event

namespace example { 

class inbound {

    // Inbound trigger event record fields
    omi::wireshark::frame::number frame;
    omi::wireshark::frame::time timestamp;
    std::string sequence;

    // Record properties
    uint32_t line;                 // tshark csv record number
    bool processed { false };      // Was record processed correctly?

  public:

    using identifier = std::string;

    // Event description
    static constexpr char * description = "sbe packet";

    // Construct from csv record
    explicit inbound(const std::string &record, uint32_t number = 0) : line{ number } {
        auto tokenize = omi::wireshark::tokenizer{ record };
        processed = tokenize.frame(frame) and
                    tokenize.timestamp(timestamp) and
                    tokenize.string(sequence);
    }

  //// Interface //////////////////

    // Return event identifier
    identifier id() const noexcept {
        return sequence;
    }

    // Return record timestamp in microseconds
    double microseconds() const noexcept {
        return timestamp * 1000000;
    }

    // Is record valid?
    bool valid() const noexcept {
        return processed;
    }
};

}

#endif
