#include <vector>
using namespace std;

class Solution {
 public:
  int findPeakElement(vector<int>& nums) {
    int n = nums.size();
    // 处理数组长度为1的特殊情况
    if (n == 1) {
      return 0;
    }
    int l = 0, r = n - 1, m;
    if (nums[0] > nums[1]) {
      return 0;
    } else if (nums[r] > nums[r - 1]) {
      return r;
    } else {
      l += 1;
      r -= 1;
      while (l <= r) {
        m = l + ((r - l) >> 1);
        if (nums[m] > nums[m + 1] && nums[m] > nums[m - 1]) {
          return m;
        } else if (nums[m] < nums[m + 1]) {
          l = m + 1;
        } else {
          r = m - 1;
        }
      }
    }
    return -1;  // 理论上不会执行到此处
  }
};