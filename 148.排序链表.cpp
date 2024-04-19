/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
 *
 * https://leetcode.cn/problems/sort-list/description/
 *
 * algorithms
 * Medium (65.56%)
 * Likes:    2285
 * Dislikes: 0
 * Total Accepted:    496.2K
 * Total Submissions: 756.9K
 * Testcase Example:  '[4,2,1,3]'
 *
 * 给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：head = [4,2,1,3]
 * 输出：[1,2,3,4]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：head = [-1,5,3,4,0]
 * 输出：[-1,0,3,4,5]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：head = []
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中节点的数目在范围 [0, 5 * 10^4] 内
 * -10^5 <= Node.val <= 10^5
 * 
 * 
 * 
 * 
 * 进阶：你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？
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
    ListNode* sortList(ListNode* head) {
        if (head == NULL && head->next == NULL) return head;
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow;
        slow = slow->next;
        fast->next = NULL;
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);
        return mergeTwoSortedList(l1, l2);
    }

    ListNode* mergeTwoSortedList(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                cur->next = l1;
                l1 = l1->next;
                cur = cur->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
                cur = cur->next;
            }
        }
        if (l1) {
            cur->next = l1;
        }
        if (l2) {
            cur->next = l2;
        }
        return dummy->next;
    }
};
// @lc code=end

