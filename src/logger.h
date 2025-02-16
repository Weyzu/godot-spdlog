#pragma once

#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/core/class_db.hpp>

#include <memory>
#include <string_view>

namespace spdlog {
class logger;
}

class Logger : public godot::RefCounted {

  GDCLASS(Logger, RefCounted);

public:
  Logger(Logger const&) = delete;
  ~Logger();

  void log_info(std::string_view message);
  void log_error(std::string_view message);
  void log_warning(std::string_view message);
  void log_critical(std::string_view message);
  void log_debug(std::string_view message);

  static Logger* get_instance();

protected:
  static void _bind_methods();

private:
  explicit Logger();

  std::shared_ptr<spdlog::logger> logger;
};
