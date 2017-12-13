#ifndef OMI_EXAMPLE_INBOUND_EVENT_HPP_
#define OMI_EXAMPLE_INBOUND_EVENT_HPP_

#include <omi/types/tokenizer.hpp>

// Example cme inbound mdp record

namespace cme { 

struct sbe {

  //// Member Variables ///////////

    // Inbound sbe market data event fields from tshark csv
    omi::frame frame;              // Pcap frame number
    omi::timestamp timestamp;      // Pcap time in nanoseconds 
    omi::seqnum sequence;          // Sbe message sequence number

    // Record properties
    uint32_t line;                 // Record line number in file
    bool processed { false };      // Was record processed correctly?

  //// Construction ///////////////

    // Construct from csv record string
    explicit sbe(const std::string &record, uint32_t number = 0) : line{ number } {
        auto parse = omi::tokenizer{ record };
        processed = parse.wireshark(frame) and
                    parse.wireshark(timestamp) and
                    parse.sequence(sequence);
    }

  //// Methods ////////////////////

    // Return event identifier
    auto id() const noexcept {
        return sequence;
    }

    // Return event timestamp
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