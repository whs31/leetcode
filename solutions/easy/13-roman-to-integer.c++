#include <cstdint>
#include <cmath>
#include <string>
#include <unordered_map>

using namespace std;
using i8 = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;
using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;
using usize = size_t;
using isize = int;
using uptr = uintptr_t;
using iptr = ptrdiff_t;
using f32 = float;
using f64 = double;

const unordered_map<char, int> dict =
{
  {'I', 1},
  {'V', 5},
  {'X', 10},
  {'L', 50},
  {'C', 100},
  {'D', 500},
  {'M', 1000}
};

auto romanToInt(string s) -> int
{
  int ret = 0;
  bool cont = false;
  for(int i = s.size() - 1; i >= 0; --i)
  {
    if(cont) {
      cont = false;
      continue;
    }
    int curr = dict.at(s[i]);
    if(i == 0)
    {
      ret += curr;
      break;
    }
    int prev = dict.at(s[i - 1]);
    if(prev < curr)
    {
      ret = ret + curr - prev;
      cont = true;
      continue;
    }
    ret += curr;
  }
  return ret;
}