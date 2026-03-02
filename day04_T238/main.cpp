#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> prefix_product{nums[0]};     // 前缀乘积
        vector<int> suffix_product{nums.back()}; // 后缀乘积

        // 前缀乘积(最后一个元素不用乘)
        for (int i = 1; i < nums.size() - 1; i++)
        {
            prefix_product.push_back(
                prefix_product[i - 1] * nums[i]);
        }

        // 后缀乘积(不需要求到第一个元素)
        // 由于头部追加性能太差,所以采用尾部追加之后再反转的策略
        for (int i = 1; i < nums.size() - 1; i++)
        {
            suffix_product.push_back(
                suffix_product[i - 1] * nums[nums.size() - i - 1]);
        }
        reverse(suffix_product.begin(), suffix_product.end());

        // 计算结果
        // 注意第一个元素和最后一个元素不需要乘法!!!
        nums[0] = suffix_product[0];
        nums[nums.size() - 1] = prefix_product.back();
        for (int i = 1; i < nums.size() - 1; i++)
        {
            nums[i] = prefix_product[i - 1] * suffix_product[i];
        }

        return nums;
    }
};

int main()
{
    // vector<int> nums = {1, 2, 3, 4};
    vector<int> nums = {-1, 1, 0, -3, 3};

    Solution sol;
    sol.productExceptSelf(nums);

    cout << endl;
    for (auto num : nums)
    {
        cout << num << ",";
    }
    cout << endl;

    return 0;
}