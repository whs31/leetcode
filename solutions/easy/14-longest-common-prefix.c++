#include <cstdint>
#include <cmath>
#include <string>
#include <vector>

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

auto longestCommonPrefix(vector<string>& strs) -> string
{
  const auto& first = strs.front();
  auto end = first.cend();
  for(auto i = strs.cbegin() + 1; i != strs.cend(); i++)
  {
    auto mm = mismatch(first.cbegin(), first.cend(), i->cbegin(), i->cend());
    if(distance(mm.first, end) > 0)
      end = mm.first;
  }
  return { first.cbegin(), end };
}
