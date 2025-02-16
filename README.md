# Godot Logger Extension

This project is a small Godot Engine extension that provides asynchronous
logging functionality by integrating the
[spdlog](https://github.com/gabime/spdlog) library. The `Logger` class is
implemented as a singleton using Godot's memory management functions ensuring
that the object is properly registered with Godot and instantiated only once.

## Requirements

- **C++17 (or later):**  
  The project uses C++11 features (e.g., thread-safe initialization for function-local statics) and C++17 features (string views).

- **CMake 3.22 (or later)**

## Building and Integration

1. **Clone this repository:**
    ```bash
    git clone https://github.com/Weyzu/godot-spdlog
    cd godot-spdlog
    git submodule update --init --recursive
    ```

2. **Compile the Project:**
   ```bash
   mkdir build
   cd build
   cmake .. -DCMAKE_BUILD_TYPE=Release 
   cmake --build . --target godot-spdlog --parallel
   ```

3. **Integrate**

Copy `libgodot.so` and `godot-spdlog.gdextension` to your project.

## Usage

After successfully compiling and integrating the extension with Godot, access the Logger singleton from your code as follows:

```cpp
// Retrieve the Logger instance
auto logger{Logger::get_instance()};

// Log an info message
logger->log_info("This is an informational message");
```

## Known Issues / Considerations

This is heavily WIP and will be extended accordingly in time. As time of
writing it was tested only on Linux.

