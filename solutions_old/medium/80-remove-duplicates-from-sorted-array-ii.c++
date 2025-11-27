#include <vector>

using namespace std;

using usize = size_t;

struct Occurrence
{
  bool increment()
  {
    if(count++ >= 2)
      return true;
    return false;
  }

  int value;
  int count;
};

auto removeDuplicates2(vector<int>& nums) -> int
{
  Occurrence occurrence = {
      .value = nums.front(),
      .count = 0
  };

  for(usize i = 0; i < nums.size(); ++i)
  {
    if(nums[i] == occurrence.value)
    {
      if(occurrence.increment())
      {
        nums.erase(nums.begin() + i);
        i--;
      }
      continue;
    }
    else
    {
      occurrence = {
          .value = nums[i],
          .count = 1
      };
    }
  }
  return nums.size();
}