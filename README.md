# DirWalk

The DirWalk Library is a C-based utility designed for efficient traversal of file directories in an iterator style. It provides context management for walking through directories, handling both files and folders seamlessly across different operating systems. This README outlines the functionality of the library and guides you through using its core functions.

## Features

- Cross-platform support for Windows and Unix/Linux.
- Manage directory traversal using a structured context.
- Retrieve absolute and relative paths.
- Clean up resources efficiently with context deinitialization functions.

## Getting Started

## Requirements

- **Windows**: Requires MinGW or similar to compile.
- **Compiler**: GCC or any C99 compatible compiler.
- **CMake** (optional): For build automation, recommended for easier setup.

### Building Instructions

To build the library, include `dirwalk.c` in your project:

```sh
gcc -o your_program your_program.c dirwalk.c
```

### Build Instructions for CMake Projects

If you have Dir-walk included in your project's source tree, you can add it as a subdirectory in your CMakeLists.txt.

**Directory Structure Example:**

```
your_project/
├── CMakeLists.txt
├── src/
│   ├── main.c
├── dirwalk/
│   ├── CMakeLists.txt
│   ├── dirwalk.c
│   ├── dirwalk.h
```

**Your Project’s `CMakeLists.txt`:**

```cmake
cmake_minimum_required(VERSION 3.9.2)
project(YourProject LANGUAGES C)

# Add the DirWalk subdirectory
add_subdirectory(dirwalk)

# Add your executable or library
add_executable(your_executable src/main.c)

# Link against the shared or static version of DirWalk based on your preference
target_link_libraries(your_executable PRIVATE dirwalk)

# Set include directories if required
target_include_directories(your_executable PRIVATE dirwalk)
```

### Example

Here’s a complete example demonstrating the basic usage:

```c
#include <stdio.h>
#include <stdlib.h>

#include "dirwalk.h"

int main() {
walk_ctx pctx = init_walk_ctx(".");
while (walk_next(&pctx)) {
  char *p = walk_get_absolute_path(&pctx, -1, 0);
  printf("%s\n", p);
  free(p);
}
deinit_walk_ctx(&pctx);
}
```

## API Reference

#### 1. `walk_ctx init_walk_ctx(char *root_path)`

Initializes a `walk_ctx` structure, setting up the traversal context for the specified root path.

- **Parameters**:
  - `char *root_path`: The root path from which traversal starts.
- **Returns**: An initialized `walk_ctx` object.

#### 2. `void deinit_walk_ctx(walk_ctx *ctx)`

Cleans up and deallocates resources used by the walk context.

- **Parameters**:
  - `walk_ctx *ctx`: The traversal context to deinitialize.

#### 3. `int walk_next(walk_ctx *ctx)`

Advances to the next directory entry (file or folder) in the traversal sequence.

- **Parameters**:
  - `walk_ctx *ctx`: The traversal context.
- **Returns**: A status code indicating success or failure. A positive value for successful traversal, zero or negative for failure or end of traversal.

#### 4. `char *walk_get_absolute_path(walk_ctx *pathCtx, int index, int only_relative_path)`

Retrieves the absolute path of a segment at a specified index.

- **Parameters**:
  - `walk_ctx *pathCtx`: The traversal context.
  - `int index`: Index of the segment in the stack.
  - `int only_relative_path`: Flag to determine whether to return only the relative path.
- **Returns**: A string representing the path.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.

## Contributing

Contributions are welcome! Feel free to submit issues, feature requests, or pull requests.