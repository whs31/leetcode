#include <vector>
#include <algorithm>

using namespace std;

auto removeElement(vector<int>& nums, int val) -> int
{
  nums.erase(remove(nums.begin(), nums.end(), val), nums.end());
  return nums.size();
}