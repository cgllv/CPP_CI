#define CATCH_CONFIG_RUNNER
#include "logger.h"
#include <catch.hpp>

int main(int argc, char **argv) {
  using namespace ModernCppCI;
  Logger::level(LogLevel::debug);
  auto result = Catch::Session().run(argc, argv);

  return (result < 0xff ? result : 0xff);
}