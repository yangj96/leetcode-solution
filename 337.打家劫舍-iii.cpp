/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
 *
 * https://leetcode.cn/problems/house-robber-iii/description/
 *
 * algorithms
 * Medium (61.53%)
 * Likes:    1945
 * Dislikes: 0
 * Total Accepted:    330.5K
 * Total Submissions: 537K
 * Testcase Example:  '[3,2,3,null,3,null,1]'
 *
 * 小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为 root 。
 * 
 * 除了 root 之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果
 * 两个直接相连的房子在同一天晚上被打劫 ，房屋将自动报警。
 * 
 * 给定二叉树的 root 。返回 在不触动警报的情况下 ，小偷能够盗取的最高金额 。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 
 * 
 * 输入: root = [3,2,3,null,3,null,1]
 * 输出: 7 
 * 解释: 小偷一晚能够盗取的最高金额 3 + 3 + 1 = 7
 * 
 * 示例 2:
 * 
 * 
 * 
 * 
 * 输入: root = [3,4,5,1,3,null,1]
 * 输出: 9
 * 解释: 小偷一晚能够盗取的最高金额 4 + 5 = 9
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 
 * 
 * 树的节点数在 [1, 10^4] 范围内
 * 0 <= Node.val <= 10^4
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // DP
    // int rob(TreeNode* root) {
    //     vector<int> res = dfs(root);
    //     return max(res[0], res[1]);
    // }

    // vector<int> dfs(TreeNode* root) {
    //     if (!root) return {0, 0};
    //     vector<int> leftRes = dfs(root->left);
    //     vector<int> rightRes = dfs(root->right);
    //     vector<int> res(2);
    //     res[0] = max(leftRes[0], leftRes[1]) + max(rightRes[0], rightRes[1]);
    //     res[1] = root->val + leftRes[0] + rightRes[0];
    //     return res;
    // }
    // Rer
    unordered_map<TreeNode*, int> valMap;
    int rob(TreeNode* root) {
        int res = dfs(root);
        return res;
    }

    int dfs(TreeNode* root) {
        if (!root) {
            return 0;
        }
        if (valMap[root]) return valMap[root];
        int val1 = 0, val2 = 0;
        val1 += root->val;
        
        if (root->left) {
            val1 += dfs(root->left->left) + dfs(root->left->right);
        }
        if (root->right) {
            val1 += dfs(root->right->left) + dfs(root->right->right);
        }
        val2 += dfs(root->left) + dfs(root->right);
        valMap[root] = max(val1, val2);
        return max(val1, val2);
    }
};
// @lc code=end

