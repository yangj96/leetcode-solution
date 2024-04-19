/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 *
 * https://leetcode.cn/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (61.62%)
 * Likes:    2442
 * Dislikes: 0
 * Total Accepted:    1M
 * Total Submissions: 1.7M
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * 给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
 * 
 * 请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
 * 
 * 你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: [3,2,1,5,6,4], k = 2
 * 输出: 5
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: [3,2,3,1,2,4,5,5,6], k = 4
 * 输出: 4
 * 
 * 
 * 
 * 提示： 
 * 
 * 
 * 1 <= k <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return quickSelect(nums, 0, n - 1, k - 1);
    }

    // int quickSelect(vector<int>& nums, int l, int r, int k) {
    //     if (l >= r) {
    //         return nums[l];
    //     }
    //     int i = l - 1, j = r + 1;
    //     int x = nums[l + r >> 1];
    //     while (i < j) {
    //         do i++; while(nums[i] > x);
    //         do j--; while(nums[j] < x);
    //         if (i < j) {
    //             int tmp = nums[i];
    //             nums[i] = nums[j];
    //             nums[j] = nums[i];
    //         }
    //     }
    //     int cnt = j - l + 1;
    //     cout << l << " " << r << " " << j << " " << cnt << endl;
    //     if (j - l + 1 >= k) {
    //         return quickSelect(nums, l, j, k);
    //     } else {
    //         return quickSelect(nums, j + 1, r, k - cnt);
    //     }
    // }
    int quickSelect(vector<int>& nums, int l, int r, int k) {
        if (l == r) return nums[k];
        int x = nums[l + r >> 1], i = l - 1, j = r + 1;
        while (i < j) {
            do i ++ ; while (nums[i] > x);
            do j -- ; while (nums[j] < x);
            if (i < j) swap(nums[i], nums[j]);
        }
        if (k <= j) return quickSelect(nums, l, j, k);
        else return quickSelect(nums, j + 1, r, k);
    }
};
// @lc code=end

