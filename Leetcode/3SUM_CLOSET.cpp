#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int closestSum = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; i++) {

            // Skip duplicate first elements
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];

                if (abs(target - currentSum) < abs(target - closestSum))
                    closestSum = currentSum;

                if (currentSum == target)
                    return target;      // Best possible answer

                else if (currentSum < target)
                    left++;

                else
                    right--;
            }
        }

        return closestSum;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;

    cout << obj.threeSumClosest(nums, target);

    return 0;
}