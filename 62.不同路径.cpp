/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 * 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
 * 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。
 * 问总共有多少条不同的路径？
 */

// @lc code=start
class Solution {
public:
    int N = 101;
    int uniquePaths(int m, int n) {
        int a[N][N];
        a[0][0] = 1;
        for (int i = 1; i < m; i++) {
            a[i][0] = 1;
        }
        for (int j = 1; j < n; j++) {
            a[0][j] = 1;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                a[i][j] = a[i-1][j] + a[i][j-1];
            }
        }
        return a[m-1][n-1];
    }

    int dp(int m, int n) {
        if (m == 0 && n == 0) {
            return 1;
        }
        if (m < 0 || n < 0) {
            return 0;
        }
        return dp(m-1, n) + dp(m, n-1);
    }
};
// @lc code=end

