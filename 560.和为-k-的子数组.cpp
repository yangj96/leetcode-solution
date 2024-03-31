/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 *
 * https://leetcode.cn/problems/subarray-sum-equals-k/description/
 *
 * algorithms
 * Medium (44.27%)
 * Likes:    2292
 * Dislikes: 0
 * Total Accepted:    431.7K
 * Total Submissions: 978.9K
 * Testcase Example:  '[1,1,1]\n2'
 *
 * 给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的子数组的个数 。
 * 
 * 子数组是数组中元素的连续非空序列。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,1,1], k = 2
 * 输出：2
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,2,3], k = 3
 * 输出：2
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 2 * 10^4
 * -1000 <= nums[i] <= 1000
 * -10^7 <= k <= 10^7
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // 样例存在负数，不能使用滑动窗口
    // int subarraySum(vector<int>& nums, int k) {
    //     int n = nums.size();
    //     vector<int> sum(n, 0);
    //     sum[0] = nums[0];
    //     for (int i = 1; i < n; i++) {
    //         sum[i] = sum[i-1] + nums[i];
    //     }
    //     int res = 0;
    //     for (int i = 0, j = 0; i < n; i++) {
    //         cout << i << " " << j << " ";
    //         while (j < i) {
    //             if ((j > 0 && sum[i] - sum[j-1] > k) || (j == 0 && sum[i] > k)){
    //                 j++;
    //             } else {
    //                 break;
    //             }
    //         }
    //         cout << j << endl;
    //         if (j == 0 && sum[i] == k) {
    //             res++;
    //         } else if (j > 0 && sum[i] - sum[j-1] == k) {
    //             res++;
    //         }
    //     }
    //     return res;
    // }
    int subarraySum(vector<int>& a, int k) {
        int n = a.size();
        vector<int> sum(n+1, 0);
        for (int i = 1; i <= n; i++) {
            sum[i] = sum[i-1] + a[i-1];
        }
        unordered_map<int, int> hash;
        int res = 0;
        hash[0] = 1;
        for (int i = 1; i <= n; i++) {
            res+= hash[sum[i] - k];
            hash[sum[i]]++;
        }
        return res;
    }
};
// @lc code=end

