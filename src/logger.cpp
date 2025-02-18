#include "logger.h"

#include <godot_cpp/core/memory.hpp>
#include <spdlog/async.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/spdlog.h>

#include <string>

Logger* Logger::get_instance() {
  static Logger* instance = memnew(Logger);
  return instance;
}

void Logger::log_info(std::string_view message) { logger->info(message); }

void Logger::log_debug(std::string_view message) { logger->debug(message); }

void Logger::log_warning(std::string_view message) { logger->warn(message); }

void Logger::log_error(std::string_view message) { logger->error(message); }

void Logger::log_critical(std::string_view message) { logger->critical(message); }

void Logger::flush() { logger->flush(); }

void Logger::_bind_methods() {}

Logger::Logger() {
  if(auto existing_logger = spdlog::get("main_logger")) {
    this->logger = existing_logger;
  } else {
    this->logger =
      spdlog::create_async<spdlog::sinks::basic_file_sink_mt>("main_logger", "logs.txt");
    spdlog::set_pattern("[%H:%M:%S %z] [%^%l%$] [thread %t] %v");
  }
}

Logger::~Logger() { spdlog::shutdown(); }
