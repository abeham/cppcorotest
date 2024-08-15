# Find cppcoro package via vcpkg
find_package(cppcoro CONFIG REQUIRED)

CPMAddPackage(
    NAME benchmark
    GIT_REPOSITORY https://github.com/google/benchmark.git
    GIT_TAG v1.8.5  # Use a specific tag or branch
    OPTIONS
        "BENCHMARK_ENABLE_TESTING Off"
  )

# Add the executable target
add_executable(CoroApp main.cpp)

# Link the cppcoro library, which also adds include directories automatically
target_link_libraries(CoroApp PRIVATE cppcoro benchmark::benchmark benchmark::benchmark_main)