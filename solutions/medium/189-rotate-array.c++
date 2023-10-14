#include <vector>
#include <algorithm>

using namespace std;

void rotate(vector<int>& nums, int k)
{
  if(nums.size() == 1 or k % nums.size() == 0)
    return;
  k %= nums.size();
  std::rotate(nums.rbegin(), next(nums.rbegin(), k), nums.rend());
}
