/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 *
 * https://leetcode.cn/problems/partition-equal-subset-sum/description/
 *
 * algorithms
 * Medium (52.38%)
 * Likes:    2045
 * Dislikes: 0
 * Total Accepted:    524.8K
 * Total Submissions: 1M
 * Testcase Example:  '[1,5,11,5]'
 *
 * 给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,5,11,5]
 * 输出：true
 * 解释：数组可以分割成 [1, 5, 5] 和 [11] 。
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,2,3,5]
 * 输出：false
 * 解释：数组不能分割成两个元素和相等的子集。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 1 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if (!n) return false;
        int sum = 0;
        for (int i = 0; i < n; i++) sum += nums[i];
        if (sum % 2) return false;
        int target = sum / 2;
        // // dp[i][j] 表示以i为结尾的数组是否存在和为j的子序列
        // vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        // dp[0][nums[0]] = 1;
        // for (int i = 1; i < n; i++) {
        //     dp[i][0] = 1;
        //     for (int j = 1; j <= target; j++) {
        //         if (j >= nums[i]) {
        //             dp[i][j] = dp[i-1][j] | dp[i-1][j-nums[i]];
        //         } else {
        //             dp[i][j] = dp[i-1][j];
        //         }
        //     }
        // }
        // return dp[n-1][target];
        vector<int> dp(target+1);
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = target; j >= nums[i]; j--) {
                dp[j] |= dp[j - nums[i]];
            }
        }
        return dp[target];
    }
};
// @lc code=end

