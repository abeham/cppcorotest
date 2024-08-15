## cppcorotest

This is a simple project to test the performance of cppcoro library. It compares the performance of a simple coroutine that yields numbers from 0 to 1000000 with a function that returns vector and iterates over that.

### Dependencies
- cppcoro via vcpkg
- Google Benchmark via CPM

You need to have vcpkg set up and the `VCPKG_ROOT` environment variable set to the root directory of vcpkg.
Run `vcpkg install` in the root directory of this repository to install cppcoro dependency.
Google benchmark is pulled in via CPM, because the vcpkg version was broken for me.

### Build and Run

`cmake -B build -S ./src` to generate the build files.

`cmake --build build` to build the project.

`./build/CoroApp/(Release|Debug)/CoroApp.exe` to run the project.
