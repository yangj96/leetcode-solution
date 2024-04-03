/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 *
 * https://leetcode.cn/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (38.11%)
 * Likes:    7125
 * Dislikes: 0
 * Total Accepted:    1.7M
 * Total Submissions: 4.3M
 * Testcase Example:  '"babad"'
 *
 * 给你一个字符串 s，找到 s 中最长的回文子串。
 * 
 * 如果字符串的反序与原始字符串相同，则该字符串称为回文字符串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "babad"
 * 输出："bab"
 * 解释："aba" 同样是符合题意的答案。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "cbbd"
 * 输出："bb"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 1000
 * s 仅由数字和英文字母组成
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // string longestPalindrome(string s) {
    //     int n = s.length();
    //     int res = 0;
    //     string str = "";
    //     for (int i = 0; i < n; i++) {
    //         for (int j = n - 1; j >= i; j--) {
    //             int slen = j - i + 1;
    //             string sstr = s.substr(i, slen);
    //             if (ishw(sstr)) {
    //                 if (slen > res) {
    //                     res = slen;
    //                     str = sstr;
    //                 }
    //                 break;
    //             }
    //         }
    //     }
    //     return str;
    // }

    // bool ishw(string s) {
    //     int i = 0, j = s.length() - 1;
    //     while (i <= j) {
    //         if (s[i] == s[j]) {
    //             i++; j--;
    //         } else {
    //             break;
    //         }
    //     }
    //     return i > j;
    // }

    string longestPalindrome(string s) {
        string str = "";
        int n = s.length();
        if (!n) return str;
        if (n == 1) return s;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int mlen = 0;
        // dp[i][j] = dp[i+1][j-1] if s[i] == s[j]
        // dp[i][i] 和 dp[i][i+1] & s[i] == s[i+1]需要初始化为1
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i <= 1 || dp[i+1][j-1] == 1)) {
                    if (j - i <= 1) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = dp[i+1][j-1];
                    }
                    if (j - i + 1 > mlen) {
                        mlen = j - i + 1;
                        str = s.substr(i, j - i + 1);
                    }
                }
            }
        }
        return str;
    }
};
// @lc code=end

