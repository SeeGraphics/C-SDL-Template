# SDL2 Template

Minimal SDL2 C project set up template.

## What’s inside
- CMake build (C11)
- vcpkg manifest for SDL2 (`vcpkg.json`)
- VS Code Code Runner mapping to configure/build/run in one click

## Prereqs
- CMake ≥ 3.16
- vcpkg installed somewhere (e.g. `~/dev/vcpkg`) 
- A C compiler (clang/gcc/MSVC)

## Build and run
```sh
# from repo root
cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE=${VCPKG_ROOT:-$HOME/dev/vcpkg}/scripts/buildsystems/vcpkg.cmake -DCMAKE_BUILD_TYPE=Debug
cmake --build build
./build/game    # on Windows: .\build\game.exe
```

After the first configure, you can just run `cmake --build build` and the binary.

## VS Code one-click run
The Code Runner play button is configured in `.vscode/settings.json` to:
- Configure on first run (with the vcpkg toolchain)
- Build
- Execute `./build/game`

## Notes
- `vcpkg.json` declares SDL2; vcpkg will auto-install it on first configure.
