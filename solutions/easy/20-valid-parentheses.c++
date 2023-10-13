#include <cstdint>
#include <cmath>
#include <string>
#include <stack>

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

enum Braces
{
  RoundOpen = '(',
  RoundClose = ')',
  SquareOpen = '[',
  SquareClose = ']',
  CurlyOpen = '{',
  CurlyClose = '}'
};

auto isValid(string s) -> bool
{
  stack<char> last;
  for(const auto& ch : s)
  {
    switch(ch)
    {
      case RoundOpen: last.push(RoundOpen); break;
      case RoundClose: if(last.empty() or last.top() != RoundOpen) return false; last.pop(); break;
      case SquareOpen: last.push(SquareOpen); break;
      case SquareClose: if(last.empty() or last.top() != SquareOpen) return false; last.pop(); break;
      case CurlyOpen: last.push(CurlyOpen); break;
      case CurlyClose: if(last.empty() or last.top() != CurlyOpen) return false; last.pop(); break;
      default: continue;
    }
  }
  return last.empty();
}