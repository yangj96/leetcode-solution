/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
 *
 * https://leetcode.cn/problems/same-tree/description/
 *
 * algorithms
 * Easy (61.35%)
 * Likes:    1151
 * Dislikes: 0
 * Total Accepted:    567.6K
 * Total Submissions: 925.1K
 * Testcase Example:  '[1,2,3]\n[1,2,3]'
 *
 * 给你两棵二叉树的根节点 p 和 q ，编写一个函数来检验这两棵树是否相同。
 * 
 * 如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：p = [1,2,3], q = [1,2,3]
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：p = [1,2], q = [1,null,2]
 * 输出：false
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：p = [1,2,1], q = [1,1,2]
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 两棵树上的节点数目都在范围 [0, 100] 内
 * -10^4 
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
    bool flag;
    // 非递归
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> que1;
        queue<TreeNode*> que2;
        que1.push(p);
        que2.push(q);
        while (!que1.empty() || !que2.empty()) {
            for (int i = 0; i < que1.size(); i++) {
                auto p = que1.front(); que1.pop();
                auto q = que2.front(); que2.pop();
                if (!p && !q) continue;
                if (!p || !q || p->val != q->val) return false;
                que1.push(p->left);
                que1.push(p->right);
                que2.push(q->left);
                que2.push(q->right);
            }
        }
        return true;
    }

    // // 递归版本
    // bool isSameTree(TreeNode* p, TreeNode* q) {
    //     flag = true;
    //     dfs(p, q);
    //     return flag;
    // }

    // void dfs(TreeNode* p, TreeNode* q) {
    //     if (!p && !q) return;
    //     if (!p || !q || p->val != q->val) {
    //         flag = false;
    //         return;
    //     }
    //     dfs(p->left, q->left);
    //     dfs(p->right, q->right);
    // }
};
// @lc code=end

