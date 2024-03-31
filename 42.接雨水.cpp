/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 *
 * https://leetcode.cn/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (63.24%)
 * Likes:    5018
 * Dislikes: 0
 * Total Accepted:    863.6K
 * Total Submissions: 1.4M
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * 输出：6
 * 解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：height = [4,2,0,3,2,5]
 * 输出：9
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == height.length
 * 1 <= n <= 2 * 10^4
 * 0 <= height[i] <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // 双指针
    // int trap(vector<int>& height) {
    //     int n = height.size();
    //     if (n <= 2) return 0;
    //     vector<int> lh(n);
    //     vector<int> rh(n);
    //     lh[0] = height[0];
    //     for (int i = 1; i < n; i++) {
    //         lh[i] = max(lh[i-1], height[i]);
    //     }

    //     rh[n-1] = height[n-1];
    //     for (int i = n - 2; i >= 0; i--) {
    //         rh[i] = max(rh[i+1], height[i]);
    //     }
    //     int res = 0;
    //     for (int i = 1; i < n - 1; i++) {
    //         res += min(lh[i], rh[i]) - height[i];
    //     }
    //     return res;
    // }
    int trap(vector<int>& height) {
        int n = height.size();
        if (n <= 2) return 0;
        int res = 0;
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && height[i] >= height[st.top()]) {
                int t = st.top();
                st.pop();
                if (st.empty()) break;
                res += (min(height[i], height[st.top()]) - height[t]) * (i - st.top() - 1);
            }
            st.push(i);      
        }
        return res;
    }

};
// @lc code=end

