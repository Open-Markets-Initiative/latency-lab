#ifndef LAB_PROGRAM_ARGS_HPP_
#define LAB_PROGRAM_ARGS_HPP_

// Standard options for program templates

namespace ini { namespace file { static constexpr const char * option = "ini-file"; } }
namespace ini { namespace file { static constexpr const char * note = "Use ini file for program options"; } }

namespace events { namespace directory { static constexpr const char * option = "events-dir"; } }
namespace events { namespace directory { static constexpr const char * note = "Events directory"; } }

namespace inbound { namespace directory { static constexpr const char * option = "inbound-dir"; } }
namespace inbound { namespace directory { static constexpr const char * note = "Inbound events directory"; } }

namespace outbound { namespace directory { static constexpr const char * option = "outbound-dir"; } }
namespace outbound { namespace directory { static constexpr const char * note = "Outbound events directory"; } }

namespace inbound { namespace file { static constexpr const char * option = "inbound-events"; } }
namespace inbound { namespace file { static constexpr const char * note = "Input inbound events csv file"; } }

namespace outbound { namespace file { static constexpr const char * option = "outbound-events"; } }
namespace outbound { namespace file { static constexpr const char * note = "Input outbound events csv file"; } }

namespace matching { namespace file { static constexpr const char * option = "matched-events"; } }
namespace matching { namespace file { static constexpr const char * note = "Output matched events file"; } }

namespace analyzer { namespace file { static constexpr const char * option = "analyzer-results"; } }
namespace analyzer { namespace file { static constexpr const char * note = "Output analyzed results file"; } }

namespace email { namespace file { static constexpr const char * option = "email-file"; } }
namespace email { namespace file { static constexpr const char * note = "Output email friendly html latency report"; } }

namespace html { namespace report { static constexpr const char * option = "html-report"; } }
namespace html { namespace report { static constexpr const char * note = "Output html latency report"; } }

namespace html { namespace title { static constexpr const char * option = "html-title"; } }
namespace html { namespace title { static constexpr const char * note = "Report header (Optional)"; } }

namespace html { namespace header { static constexpr const char * option = "html-header"; } }
namespace html { namespace header { static constexpr const char * note = "Report header (Optional)"; } }

namespace html { namespace copyright { static constexpr const char * option = "html-copyright"; } }
namespace html { namespace copyright { static constexpr const char * note = "Report Copyright (Optional)"; } }

namespace css { namespace file { static constexpr const char * option = "css-file"; } }
namespace css { namespace file { static constexpr const char * note = "Link report to external css file (Optional)"; } }

// Most of these need name changes

#endif