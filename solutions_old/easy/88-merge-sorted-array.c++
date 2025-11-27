#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
  auto it = nums1.end();
  advance(it, -n);
  vector<int> temp;
  std::merge(nums1.begin(), it, nums2.begin(), nums2.end(), back_inserter(temp));
  nums1.clear();
  nums1 = temp;
}