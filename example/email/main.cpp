#include <omi/latency/email.hpp>
#include <omi/wireshark/tokenizer.hpp>

// Example emailable latency report for cme tick to trade

struct sbe {
   static constexpr char * description = "sbe mdp market data";

  // Record Fields //
    omi::frame frame;              // Pcap frame number
    omi::timestamp timestamp;      // Pcap time in nanoseconds 
    omi::sequence msgseqnum;       // Sbe message sequence number

    uint32_t line;                 // Record line number in file
    bool processed { false };      // Was record processed correctly?

  // Construct from csv record string
    explicit sbe(const std::string &record, uint32_t line = 0) : line{ line } {
        auto parse = omi::wireshark::tokenizer{ record };
        processed = parse.wireshark(frame) and
                    parse.wireshark(timestamp) and
                    parse.sequence(msgseqnum);
    }

  // Required Methods //
    omi::sequence id() const noexcept { return msgseqnum; }
    omi::timestamp time() const noexcept { return timestamp; }
    omi::frame info() const noexcept { return frame; }
    bool valid() const noexcept { return processed; }
};

struct fix {
    static constexpr char * description = "ilink fix message";

  // Record Fields //
    omi::frame frame;              // Pcap frame number
    omi::timestamp timestamp;      // Pcap time in nanoseconds 
    omi::sequence value9717;       // Sbe message sequence number in fix tag 9717

    uint32_t line;                 // Record line number in file
    bool processed { false };      // Was record processed correctly?

  // Construct from csv record string
    explicit fix(const std::string &record, uint32_t number = 0) : line{ number } {
        auto parse = omi::wireshark::tokenizer{ record };
        processed = parse.wireshark(frame) and 
                    parse.wireshark(timestamp) and
                    parse.skip() and 
                    parse.skip() and 
                    parse.skip() and
                    parse.sequence(value9717);
    }

  // Required Methods //
    omi::sequence id() const noexcept { return value9717; }
    omi::timestamp time() const noexcept { return timestamp; }
    omi::frame info() const noexcept { return frame; }
    bool valid() const noexcept { return processed; }
};

int main(int argc, char *argv[]) {
    try {
        omi::latency::email::of<sbe, fix>(argc, argv);
    } catch (std::exception &exception) {
        std::cerr << "Error: " << exception.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "Unknown exception" << std::endl;
        return 1;
    }
}