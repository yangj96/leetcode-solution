/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 *
 * https://leetcode.cn/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (50.19%)
 * Likes:    1607
 * Dislikes: 0
 * Total Accepted:    462.5K
 * Total Submissions: 919.7K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * 输出：[1,2,3,6,9,8,7,4,5]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
 * 输出：[1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 
 * -100 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size();
        if (m <= 0) return res;
        int n = matrix[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int i = 0, j = 0, k = 0;
        for (int l = 0; l < n * m; l++) {
            res.push_back(matrix[i][j]);
            visited[i][j] = true;
            int a = i + dx[k], b = j + dy[k];
            if (a >= m || a < 0 || b >= n || b < 0 || visited[a][b]) {
                k = (k + 1) % 4;
                a = i + dx[k];
                b = j + dy[k];
            }
            i = a;
            j = b;
        }
    
        return res;
    }
};
// @lc code=end

