# cpp-vcpkg-template | C++ Project Template with vcpkg

![github CI status](https://github.com/ikraduya/cpp-vcpkg-template/actions/workflows/ci.yml/badge.svg)

## Build
```bash
# Populate submodules
git submodule update --init --recursive

# Build program
cmake -S . -B build
cmake --build build -j 2
```
