/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) {
            return head;
        }
        if (head->next == nullptr) {
            return nullptr;
        }
        ListNode* pre = new ListNode(0);
        pre->next = head;
        ListNode* l1 = pre;
        for (int i = 0; i < n; ++i) {
            l1 = l1->next;
        }
        ListNode* l2 = pre;
        while (l1->next) {
            l2 = l2->next;
            l1 = l1->next;
        }
        l2->next = l2->next->next;
        return pre->next;
    }
};
// @lc code=end

