#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int slow = 0;
        int fast = 0;
        while (true)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
            // 快慢指针相遇时改变成一个从头开始走
            if (slow == fast)
            {
                // 注意现在的快指针也要只走一步了
                slow = 0;
                while (slow != fast)
                {
                    slow = nums[slow];
                    fast = nums[fast];
                }
                return slow;
            }
        }
    }
};

auto main() -> int
{
}
