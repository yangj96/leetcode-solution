/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 *
 * https://leetcode.cn/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Medium (52.34%)
 * Likes:    2034
 * Dislikes: 0
 * Total Accepted:    595K
 * Total Submissions: 1.1M
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
 * 
 * 请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [100,4,200,1,3,2]
 * 输出：4
 * 解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0,3,7,2,5,8,4,6,0,1]
 * 输出：9
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * -10^9 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        // unordered_map<int, int> tr_left, tr_right;
        // for (auto& x: nums) {
        //     int left = tr_right[x - 1];
        //     int right = tr_left[x + 1];
        //     tr_left[x - left] = max(tr_left[x - left], left + 1 + right);
        //     tr_right[x + right] = max(tr_right[x + right], left + 1 + right);
        //     res = max(res, left + 1 + right);
        // }
        unordered_set<int> set(nums.begin(), nums.end());
        for (auto& x: nums) {
            if (set.find(x-1) != set.end()) continue;
            int cur = 1, curVal = x;
            while (set.find(curVal+1) != set.end()) {
                cur++;
                curVal++;
            }
            res = max(res, cur);
        }
        return res;
    }
};
// @lc code=end

