/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (24.80%)
 * Likes:    4553
 * Dislikes: 525
 * Total Accepted:    650.8K
 * Total Submissions: 2.6M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate triplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        if (n < 3) 
            return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i-1]) 
                continue;
            int target = -nums[i];
            for (int j = i + 1, k = n - 1; j < k;) {
                if (nums[j] + nums[k] == target) {
                    vector<int> ans;
                    ans.push_back(nums[j]);
                    ans.push_back(nums[i]);
                    ans.push_back(nums[k]);
                    res.push_back(ans);
                    while (j < k && nums[j] == nums[j+1])
                        j++;
                    while (j < k && nums[k] == nums[k-1])
                        k--;
                    j++;
                    k--;
                }
                else if (nums[j] + nums[k] > target) 
                    k--;
                else 
                    j++;
            }
        }
        return res;
    }
};

