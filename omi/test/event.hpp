#ifndef OMI_TEST_EVENT_HPP_
#define OMI_TEST_EVENT_HPP_

#include <omi/types/seqnum.hpp>
#include <omi/types/timestamp.hpp>
#include <omi/types/frame.hpp>

// Example event for testing template classes

namespace test {

struct event {

    omi::frame frame;              // Pcap frame number
    omi::timestamp timestamp;      // Pcap time in nanoseconds 
    omi::seqnum sequence;          // Sbe message sequence number
    bool processed;                //

  //// Methods ////////////////////

    auto id() const noexcept { return sequence; }
    auto time() const noexcept { return timestamp; }
    auto info() const noexcept { return frame; }
    auto valid() const noexcept { return processed; }
};

}

#endif