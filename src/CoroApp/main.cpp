#include <benchmark/benchmark.h>
#include <cppcoro/generator.hpp>

cppcoro::generator<const std::int64_t> range(const std::int64_t start, const std::int64_t end)
{
  if (start >= end)
  {
    co_return;
  }
  for (auto i = start; i < end; ++i)
  {
    co_yield i;
  }
}

std::vector<std::int64_t> range_vec(const std::int64_t start, const std::int64_t end)
{
  std::vector<std::int64_t> result;
  if (start >= end)
  {
    return result;
  }
  result.reserve(end - start);
  for (auto i = start; i < end; ++i)
  {
    result.push_back(i);
  }
  return result;
}

static void BM_CoroRange(benchmark::State &state)
{
  for (auto _ : state)
  {
    for (auto i : range(0, state.range(0)))
    {
      benchmark::DoNotOptimize(i);
    }
  }
}

static void BM_VectorRange(benchmark::State &state)
{
  for (auto s : state)
  {
    for (auto i : range_vec(0, state.range(0)))
    {
      benchmark::DoNotOptimize(i);
    }
  }
}

BENCHMARK(BM_CoroRange)->RangeMultiplier(10)->Range(1000, 1000000);
BENCHMARK(BM_VectorRange)->RangeMultiplier(10)->Range(1000, 1000000);

BENCHMARK_MAIN();
