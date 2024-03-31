/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 *
 * https://leetcode.cn/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (45.43%)
 * Likes:    2672
 * Dislikes: 0
 * Total Accepted:    391.8K
 * Total Submissions: 861.7K
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
 * 
 * 求在该柱状图中，能够勾勒出来的矩形的最大面积。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 
 * 
 * 输入：heights = [2,1,5,6,2,3]
 * 输出：10
 * 解释：最大的矩形为图中红色区域，面积为 10
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 
 * 输入： heights = [2,4]
 * 输出： 4
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 0 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        int n = heights.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int t = st.top();
                st.pop();
                if (st.empty()) break;
                res = max(res, (i - st.top() - 1) * heights[t]);
            }
            st.push(i);
        }
        return res;
    }
    // int largestRectangleArea(vector<int>& heights) {
    //     heights.insert(heights.begin(), 0);
    //     heights.push_back(0);
    //     int n = heights.size();
    //     int res = 0;
    //     for (int i = 1; i < n - 1; i++) {
    //         int k = i - 1, j = i + 1;
    //         while (k >= 0 && heights[k] >= heights[i]) {
    //             k--;
    //         }
    //         while (j < n && heights[j] >= heights[i]) {
    //             j++;
    //         }
    //         res = max(res, heights[i] * (j - k - 1));
    //     }
    //     return res;
    // }
};
// @lc code=end

