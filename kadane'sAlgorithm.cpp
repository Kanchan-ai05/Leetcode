#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:
    struct Result {
        int maxSum;
        int startIndex;
        int endIndex;
    };

    Result kadane(const vector<int>& nums) {
        int currentSum = nums[0];
        int maxSum = nums[0];

        int start = 0;
        int end = 0;
        int tempStart = 0;

        for (int i = 1; i < nums.size(); i++) {

            if (currentSum + nums[i] < nums[i]) {
                currentSum = nums[i];
                tempStart = i;
            } else {
                currentSum += nums[i];
            }

            if (currentSum > maxSum) {
                maxSum = currentSum;
                start = tempStart;
                end = i;
            }
        }

        return {maxSum, start, end};
    }
};

int main() {
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    Solution obj;
    Solution::Result ans = obj.kadane(arr);

    cout << "Maximum Sum : " << ans.maxSum << endl;
    cout << "Starting Index : " << ans.startIndex << endl;
    cout << "Ending Index : " << ans.endIndex << endl;

    cout << "Subarray : ";
    for (int i = ans.startIndex; i <= ans.endIndex; i++)
        cout << arr[i] << " ";

    return 0;
}