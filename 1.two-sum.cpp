/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (44.55%)
 * Likes:    12153
 * Dislikes: 423
 * Total Accepted:    2.2M
 * Total Submissions: 5M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers, return indices of the two numbers such that they
 * add up to a specific target.
 * 
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 * 
 * Example:
 * 
 * 
 * Given nums = [2, 7, 11, 15], target = 9,
 * 
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 * 
 * 
 */
class Solution {
public:
    // Solution 1: hash
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     unordered_map<int, int> hash;
    //     int n = nums.size();
    //     vector<int> res;
    //     for (int i = 0; i < n; i++) {
    //         int bu = target - nums[i];
    //         auto it = hash.find(bu);
    //         if (it != hash.end()) {
    //             res.push_back(it->second);
    //             res.push_back(i);
    //             return res;
    //         } else {
    //             hash.emplace(nums[i], i);
    //         }
    //     }
    //     return res;
    // }

    // Solution 2: two pointer
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        multimap<int, int> hash;
        for (int i = 0; i < n; i++) {
            hash.emplace(nums[i], i);
        }
        sort(nums.begin(), nums.end());
        vector<int> res;
        for (int i = 0, j = n - 1; i < n; i++) {
            while (j >= 0 && nums[i] + nums[j] > target) 
                j--;
            if (j != i && nums[i] + nums[j] == target) {
                auto it = hash.find(nums[i]);
                res.push_back(hash.find(nums[i])->second);
                hash.erase(it); // erase (nums[i], i) to find j in multimap when nums[i] == nums[j] 
                res.push_back(hash[nums[j]]);
                return res;
            }
        }
        return res;
    }
};
