#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/core/memory.hpp>
#include <godot_cpp/godot.hpp>

#include "logger.h"

#include <string>

void initialize_extension(const godot::ModuleInitializationLevel initLevel) {
  if(initLevel != godot::MODULE_INITIALIZATION_LEVEL_CORE) {
    return;
  }

  GDREGISTER_CLASS(Logger);

  auto logger = Logger::get_instance();
  logger->log_info(std::string("spdlog logger initialized"));
  logger->flush();
}

void terminate_extension(godot::ModuleInitializationLevel initLevel) {
  if(initLevel != godot::MODULE_INITIALIZATION_LEVEL_CORE) {
    return;
  }
  godot::memdelete(Logger::get_instance());
}

extern "C"
{
  GDExtensionBool GDE_EXPORT godot_spdlog_init(
    GDExtensionInterfaceGetProcAddress getProcAddressCallback,
    const GDExtensionClassLibraryPtr extensionLibrary,
    GDExtensionInitialization* extensionInitialization) {

    godot::GDExtensionBinding::InitObject initObject{
      getProcAddressCallback, extensionLibrary, extensionInitialization};

    initObject.register_initializer(initialize_extension);
    initObject.register_terminator(terminate_extension);
    initObject.set_minimum_library_initialization_level(godot::MODULE_INITIALIZATION_LEVEL_CORE);

    return initObject.init();
  }
}
