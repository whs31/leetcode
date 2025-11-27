#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// also we can just sort nums and return nums[nums.size() / 2];
auto majorityElement(vector<int>& nums) -> int
{
  unordered_map<int, int> dict;
  for(const auto& num : nums)
  {
    if(dict.contains(num)) dict[num]++;
    else dict[num] = 1;
  }

  return std::max_element(dict.cbegin(), dict.cend(), [](const auto& p1, const auto& p2) {
    return p1.second < p2.second;
  })->first;
}