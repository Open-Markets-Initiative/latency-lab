#include <omi/latency/email.hpp>
#include <omi/wireshark/tokenizer.hpp>

// Example emailable latency report for cme tick to trade

// Inbound market data events
struct sbe {
   static constexpr char * description = "sbe mdp market data";

  //// Member Variables ///////////

    omi::frame frame;              // Pcap frame number
    omi::timestamp timestamp;      // Pcap time in nanoseconds 
    std::string sequence;          // Sbe message sequence number

    uint32_t line;                 // Record line number in file
    bool processed { false };      // Was record processed correctly?

  //// Construction ///////////////

    // Construct from csv record string
    explicit sbe(const std::string &record, uint32_t number = 0) : line{ number } {
        auto parse = omi::wireshark::tokenizer{ record };
        processed = parse.wireshark(frame) and
                    parse.wireshark(timestamp) and
                    parse.string(sequence);
    }

  //// Methods ////////////////////

    std::string id() const noexcept { return sequence; }
    omi::timestamp time() const noexcept { return timestamp; }
    omi::frame info() const noexcept { return frame; }
    bool valid() const noexcept { return processed; }
};

// Outbound orders events
struct fix {
    static constexpr char * description = "ilink fix message";

  //// Member Variables ///////////

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

    std::string id() const noexcept { return value9717; }
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