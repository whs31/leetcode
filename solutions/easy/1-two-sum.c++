#include <vector>
#include <unordered_map>
#include <cstdint>

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

// my best by runtime
class Solution
{
  public:
    auto twoSum(vector<int>& nums, int target) -> vector<int>
    {
      unordered_map<int, int> dict;
      for(isize i = 0; i < nums.size(); ++i)
        dict[target-nums[i]] = i;
      for(isize i = 0; i < nums.size(); ++i)
        if(dict.contains(nums[i]) and dict[nums[i]] != i)
          return { i, dict[nums[i]] };
      return {};
    }
};

// balanced
class Solution1
{
  public:
    auto twoSum(vector<int>& nums, int target) -> vector<int>
    {
      for(usize i = 0; i < nums.size() - 1; ++i)
        for(usize j = i + 1; j < nums.size(); ++j)
          if(nums[i] + nums[j] == target)
            return { static_cast<int>(i), static_cast<int>(j) };
      return {};
    }
};

// my best by memory
class Solution2
{
  public:
    auto twoSum(vector<int>& nums, int target) -> vector<int>
    {
      for(isize i = 0; i < nums.size(); ++i)
      {
        for(isize j = 0; j < nums.size(); ++j)
        {
          if(j == i)
            continue;
          if(nums[i] + nums[j] == target)
            return { i, j };
        }
      }
      return {};
    }
};