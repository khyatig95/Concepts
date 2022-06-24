/*
Problem : Given a sorted array of integers nums and an integer target, return the two numbers from the array such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Time Complexity : O(NlogN)
Space Complexity : O(1)
*/

#include <algorithm>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end()); //O(NlogN)
        int size = nums.size();
        int j = size-1, i = 0;
        
        while (i<j) {  //O(N) ; Space O(1)
            if (nums[i] + nums[j] == target)
                return {nums[i], nums[j]};
            if (nums[i] + nums[j] > target)
                j--;
            else 
                i++;
        }
        return {0, 0};
    }
};
