#!/usr/bin/env bash
set -e

echo "===== Step 1: Check formatting (clang-format) ====="
find src tests -name '*.cpp' -o -name '*.h' | xargs clang-format --dry-run --Werror
echo "Formatting check passed."

echo ""
echo "===== Step 2: Static analysis (cppcheck) ====="
cppcheck --enable=all --suppress=missingIncludeSystem --error-exitcode=1 src/
echo "Static analysis passed."

echo ""
echo "===== Step 3: Build in Debug mode ====="
cmake -B build/debug -DCMAKE_BUILD_TYPE=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
cmake --build build/debug
echo "Debug build succeeded."

echo ""
echo "===== Step 4: Build in Release mode ====="
cmake -B build/release -DCMAKE_BUILD_TYPE=Release
cmake --build build/release
echo "Release build succeeded."

echo ""
echo "===== Step 5: Run unit tests ====="
ctest --test-dir build/debug --output-on-failure
echo "All tests passed."

echo ""
echo "===== Step 6: Generate documentation (Doxygen) ====="
doxygen Doxyfile
echo "Documentation generated in docs/html/"

echo ""
echo "===== All steps completed successfully! ====="
