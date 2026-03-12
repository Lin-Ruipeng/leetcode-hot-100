#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int max_area = 0;
        int left = 0;
        int right = height.size() - 1;

        while (left < right)
        {
            int area = min(height[left], height[right]) * (right - left);

            if (area > max_area)
                max_area = area;

            if (height[left] > height[right])
                right--;
            else
                left++;
        }

        return max_area;
    }
};

auto main() -> int
{
}