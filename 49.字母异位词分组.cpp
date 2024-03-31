/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 *
 * https://leetcode.cn/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (67.89%)
 * Likes:    1860
 * Dislikes: 0
 * Total Accepted:    665.7K
 * Total Submissions: 979.8K
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * 给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
 * 
 * 字母异位词 是由重新排列源单词的所有字母得到的一个新单词。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
 * 输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
 * 
 * 示例 2:
 * 
 * 
 * 输入: strs = [""]
 * 输出: [[""]]
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: strs = ["a"]
 * 输出: [["a"]]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= strs.length <= 10^4
 * 0 <= strs[i].length <= 100
 * strs[i] 仅包含小写字母
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> umap;
        for (auto &s : strs) {
            string enc = encode(s);
            umap[enc].push_back(s);
        }
        vector<vector<string>> res;
        for (auto &item : umap) {
            res.push_back(item.second);
        }
        return res;
    }

    string encode(string str) {
        vector<char> arr(26, 0);
        for (auto &c : str) {
            arr[c - 'a']++;
        }
        string res(arr.begin(), arr.end());
        return res;
    }
};
// @lc code=end

