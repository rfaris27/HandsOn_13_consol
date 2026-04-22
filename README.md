# HandsOn 13 - Console Application Tooling

A simple C++ hello-world console application with a complete development tooling pipeline.

## Project Structure

```
├── .editorconfig          # Editor conventions (indent, charset, EOL)
├── .clang-format          # Code formatting rules (linter)
├── .github/workflows/     # GitHub Actions CI/CD
│   └── ci.yml
├── CMakeLists.txt         # Root CMake build configuration
├── Doxyfile               # Doxygen documentation config
├── build.sh               # Bash build script (runs full pipeline)
├── src/
│   ├── CMakeLists.txt
│   ├── main.cpp           # Entry point
│   └── greeter.h          # Greeter class with Doxygen comments
└── tests/
    ├── CMakeLists.txt
    └── greeter_test.cpp   # Unit tests (Google Test)
```



## Building Locally

### Prerequisites

- C++17 compiler (GCC, Clang, or MSVC)
- CMake 3.14+
- cppcheck
- clang-format
- Doxygen



This will:
1. Check code formatting with clang-format
2. Run static analysis with cppcheck
3. Build in Debug mode
4. Build in Release mode
5. Run unit tests
6. Generate Doxygen documentation into `docs/html/`

### Build manually

```bash
cmake -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
ctest --test-dir build --output-on-failure
```

## CI/CD

Every push and pull request triggers the GitHub Actions workflow which runs the full `build.sh` pipeline. The generated Doxygen documentation is uploaded as a downloadable build artifact.
