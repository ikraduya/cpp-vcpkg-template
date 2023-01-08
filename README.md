# cpp-vcpkg-template | C++ Project Template with vcpkg

## Build
```bash
# Populate submodules
git submodule update --init --recursive

# Build program
cmake -S . -B build
cmake --build build -j 2
```
