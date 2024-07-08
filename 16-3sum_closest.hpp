/*
Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.



Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

Example 2:

Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).



Constraints:

    3 <= nums.length <= 500
    -1000 <= nums[i] <= 1000
    -104 <= target <= 104
*/

#include <stdio.h>
#include <vector>
#include <algorithm>
#ifndef Solution16_H
#define Solution16_H

using namespace std;

class Solution16
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        // right away incorporate for the case when the nums.length is three and the answer would be sum of its three elements
        int len = nums.size();

        if (len == 3)
            return nums[0] + nums[1] + nums[2];

        sort(nums.begin(), nums.end());

        int smallest = nums[0] + nums[1] + nums[2];
        if (smallest >= target)
            return smallest; // because any number after nums[2] is >= the first three thereby not changing or decreasing the sum.

        int max = nums[len - 1] + nums[len - 2] + nums[len - 3];
        if (max <= target)
            return max; // similarly any number before nums[len-3] is <= the last three therby not changing or increasing the sum.

        int perm = nums[0];
        int left, right, sum, num;
        int dist = abs(smallest - target);

        for (int i = 0; i < len - 2; i++)
        {
            if (i && nums[i] == perm)
            {
                continue;
            }
            // update perm when you move forward in the for loop and increase the left and right pointers.
            perm = num = nums[i];
            left = i + 1;
            right = len - 1;
            while (left < right)
            {
                sum = num + nums[left] + nums[right];
                if (sum == target)
                    return sum;
                // if difference between sum and target is lesser than the previous difference between smallest and target, assign perm to the sum variable and also update the dist to the one between the new sum and target
                if (abs(sum - target) < dist)
                {
                    smallest = sum;
                    dist = abs(smallest - target);
                }
                // if sum < target and next number for the left pointer is the same, keep moving forward. (so that we skip redundant cycles)
                if (sum < target)
                {
                    while (left < right && nums[left] == nums[left + 1])
                    {
                        left++;
                    }
                    //after skipping the redundant cycles we can increment the one time we have to.
                    left++;
                }
                // if sum > target and previous number for the right pointer is the same, keep moving backward. (so that we skip redundant cycles)
                else
                {
                    while (left < right && nums[right] == nums[right - 1])
                    {
                        right--;
                    }
                    //after skipping the redundant cycles we can decrement the one time we have to.
                    right--;
                }
            }
            return smallest;
        }
    }
};

#endif
