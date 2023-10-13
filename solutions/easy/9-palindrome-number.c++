#include <cstdint>
#include <cmath>

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

auto isPalindrome(int x) -> bool
{
  if(x == 0)
    return true;
  if(x < 0 or x % 10 == 0)
    return false;
  int original = x;
  unsigned int reversed = 0;

  while(x > 0)
  {
    i8 mod = x % 10;
    reversed = reversed * 10 + mod;
    x /= 10;
  }
  return original == reversed;
}
