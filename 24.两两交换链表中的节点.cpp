/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 *
 * https://leetcode.cn/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (72.13%)
 * Likes:    2191
 * Dislikes: 0
 * Total Accepted:    826.3K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：head = [1,2,3,4]
 * 输出：[2,1,4,3]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：head = []
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：head = [1]
 * 输出：[1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中节点的数目在范围 [0, 100] 内
 * 0 <= Node.val <= 100
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        // if (head == NULL || head->next == NULL) return head;
        // ListNode* pre = dummy;
        // ListNode*cur = pre->next;
        // while (pre && cur) {
        //     ListNode* nxt = cur->next;
        //     if (nxt == NULL) break;
        //     pre->next = nxt;
        //     ListNode* tmp = nxt->next;
        //     nxt->next = cur;
        //     // 注意三个指针的next都需要修改
        //     cur->next = tmp;
        //     pre = cur;
        //     cur = tmp;
        // }
        ListNode* pre = dummy;
        while (pre->next && pre->next->next) {
            auto a = pre->next, b = a->next;
            pre->next = b;
            a->next = b->next;
            b->next = a;
            pre = a;
        }
        return dummy->next;
    }
};
// @lc code=end

