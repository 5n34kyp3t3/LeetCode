#include <iostream>
#include <vector>
#include <unordered_map>
#ifndef Solution1_H
#define Solution1_H

/*
Key Concepts:

1.Hash Map: A hash map is a data structure that stores key-value pairs and allows for fast retrieval of values based on their keys. In C++, unordered_map is used for this purpose.

2.Complement Calculation: For each number in the array, we calculate its complement, which is the difference between the target and the current number. The idea is to check if this complement has already been encountered in the array.

3.Single Pass Solution: By making a single pass through the array and storing indices of the numbers in the hash map, we can check in constant time (O(1)) if the complement exists in the hash map. This makes the overall time complexity O(n).

*/

using namespace std;

class Solution1
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> num_map;
        for (int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];
            if (num_map.find(complement) != num_map.end())
            {
                return {i, num_map[complement]};
            }
            num_map[nums[i]] = i;
        }
        return {};
    }
};

#endif