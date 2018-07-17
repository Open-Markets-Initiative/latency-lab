#include <omi/latency/email.hpp>
#include <omi/types/tokenizer.hpp>

// Example emailable latency report for cme tick to trade

struct sbe {
  // Record Fields
    omi::frame frame;              // Pcap frame number
    omi::timestamp timestamp;      // Pcap time in nanoseconds 
    omi::seqnum msgseqnum;         // Sbe message sequence number

    uint32_t line;                 // Record line number in file
    bool processed { false };      // Was record processed correctly?

  // Construct from csv record
    explicit sbe(const std::string &record, uint32_t line = 0) : line{ line } {
        auto parse = omi::tokenizer{ record };
        processed = parse.wireshark(frame) and
                    parse.wireshark(timestamp) and
                    parse.sequence(msgseqnum);
    }

  // Required Methods
    omi::seqnum id() const noexcept { return msgseqnum; }
    omi::timestamp time() const noexcept { return timestamp; }
    omi::frame info() const noexcept { return frame; }
    bool valid() const noexcept { return processed; }
};

struct fix {
  // Record Fields
    omi::frame frame;              // Pcap frame number
    omi::timestamp timestamp;      // Pcap time in nanoseconds 
    omi::seqnum value9717;         // Sbe message sequence number in fix tag 9717

    uint32_t line;                 // Record line number in file
    bool processed { false };      // Was record processed correctly?

  // Construct from csv record
    explicit fix(const std::string &record, uint32_t number = 0) : line{ number } {
        auto parse = omi::tokenizer{ record };
        processed = parse.wireshark(frame) and 
                    parse.wireshark(timestamp) and
                    parse.skip(3) and 
                    parse.sequence(value9717);
    }

  // Required Methods
    omi::seqnum id() const noexcept { return value9717; }
    omi::timestamp time() const noexcept { return timestamp; }
    omi::frame info() const noexcept { return frame; }
    bool valid() const noexcept { return processed; }
};

struct description {
  // Program description
    static constexpr const char * title = "Emailable Latency Report for Cme Tick to Trade";
    static constexpr const char * inbound = "sbe mdp market data events";
    static constexpr const char * outbound = "ilink fix messages";
};

int main(int argc, char *argv[]) {
    try {
        omi::latency::email::of<sbe, fix, description>(argc, argv);
    } catch (std::exception &exception) {
        std::cerr << "Error: " << exception.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "Unknown exception" << std::endl;
        return 1;
    }
}
