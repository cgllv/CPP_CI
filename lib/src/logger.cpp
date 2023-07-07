#include "logger.h"
#include "spdlog/sinks/dist_sink.h"
#include "spdlog/sinks/wincolor_sink.h"

namespace ModernCppCI {
auto create_spdlog() {
  auto color_sink = std::make_shared<spdlog::sinks::wincolor_stdout_sink_mt>();
  auto dist_sink = std::make_shared<spdlog::sinks::dist_sink_st>();
  dist_sink->add_sink(color_sink);
  return spdlog::details::registry::instance().create("console", dist_sink);
}
Logger::Logger(const std::string &section) : section_(section) {
  internal_logger_ = spdlog::get("console");
  if (internal_logger_ == nullptr) {
    internal_logger_ = create_spdlog();
  }
}

} // namespace ModernCppCI
