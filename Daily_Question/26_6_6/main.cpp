#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> leftRightDifference(vector<int>& nums) {
    vector<int> left(nums.size());
    vector<int> right(nums.size());
    vector<int> answer(nums.size());

    left[0] = nums[0];
    for (size_t i = 1; i < nums.size(); ++i) {
      left[i] = left[i - 1] + nums[i];
    }

    right[nums.size() - 1] = nums[nums.size() - 1];
    for (int j = nums.size() - 2; j >= 0; --j) {
      right[j] = right[j + 1] + nums[j];
    }

    for (size_t k = 0; k < nums.size(); ++k) {
      answer[k] = abs(left[k] - right[k]);
    }

    return answer;
  }
};

auto main() -> int {
  Solution sol;

  vector<int> nums{10, 4, 8, 3};

  auto answer = sol.leftRightDifference(nums);

  std::cout << "size: " << answer.size() << std::endl;

  std::cout << "answer = ";
  for (auto num : answer) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  return 0;
}
