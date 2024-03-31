/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        dfs(path, 0, s, res);
        return res;
    }

    void dfs(vector<string>& path, int u, string s, vector<vector<string>>& res) {
        if (u == s.size()) {
            res.push_back(path);
            return;
        } 

        for (int i = u; i < s.size(); i++) {
            string ss = s.substr(u, i - u + 1);
            if (ishw(ss)) {
                path.push_back(ss);
                dfs(path, i + 1, s, res);
                path.pop_back();
            } else {
                continue;
            }
        }
    }

    bool ishw(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i] == s[j]) {
                i++; j--;
            } else {
                return false;
            }
        }
        return i >= j;
    }
};
// @lc code=end

