#ifndef OMI_TYPES_FRAME_HPP_
#define OMI_TYPES_FRAME_HPP_

#include <stdint.h>
#include <ostream>

// Capture frame number

namespace omi {

struct frame {

  ///// Construction //////////////

    // Default constructor
    frame() 
      : value{ 0 } {}

	// Standard constructor
	explicit frame(const uint64_t &number)
		: value{ number } {}

  /////////////////////////////////

    bool operator==(const uint64_t &time) const {
        return value == time;
	}

    bool operator==(const frame& number) const {
		return value == number.value;
    }

    bool operator!=(const frame& number) const {
        return value != number.value;
    }

 /////////////////////////////////

    // Less than operator
    bool operator<(const frame& number) const {
        return value < number.value;
    }

    // Less than or equals operator
    bool operator<=(const frame& number) const {
        return value <= number.value;
    }

    // Greater than operator
    bool operator>(const frame& number) const {
        return value > number.value;
    }

    // Greater than or equals operator
    bool operator>=(const frame& number) const {
        return value >= number.value;
    }

  /////////////////////////////////

    explicit operator frame() const {
        return frame(value);
    }

    uint64_t get() const {
        return value;
    }

  /////////////////////////////////

  protected:

    uint64_t value;
};


// Stream operator
inline std::ostream & operator<<(std::ostream &out, const frame &number) {
	return out << number.get();
}

}

#endif