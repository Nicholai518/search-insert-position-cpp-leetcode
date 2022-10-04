#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // first index of the array
        int left = 0;
        // last index of array
        int right = nums.size() - 1;

        while (left <= right) {
            // find middle
            int mid = left + (right - left) / 2;

            // if target = middle, return mid
            if (nums[mid] == target) 
            {
                return mid;
            }

            // if mid is less than target, the target must be on the "right side"
            // set left to the first index of the "right side"
            if (nums[mid] < target) 
            {
                left = mid + 1;
            }
            // if mid is greater than target, the target must be on the "left side"
            // set right to the last index of the "left side"
            if (nums[mid] > target) 
            {
                right = mid - 1;
            }
        }
        // return left
        return left;
    }
};

int main()
{
    Solution solution;

    vector<int> example_one{ 1, 3, 5, 6 };
    int target_one = 5;

    vector<int> example_two{ 1, 3, 5, 6 };
    int target_two = 2;

    vector<int> example_three{ 1, 3, 5, 6 };
    int target_three = 7;

    cout << "Example one : " << solution.searchInsert(example_one, target_one) << endl;
    cout << "Example one : " << solution.searchInsert(example_two, target_two) << endl;
    cout << "Example one : " << solution.searchInsert(example_three, target_three) << endl;

	return 0;
}
