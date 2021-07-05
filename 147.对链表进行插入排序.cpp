/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
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
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        auto res = new ListNode(0);
        res->next = head;
        while (head->next != nullptr) {
            if (head->val <= head->next->val) {
                head = head->next;
                continue;
            }
            auto pre = res;
            while (pre->next->val <= head->next->val) {
                pre = pre->next;
            }
            auto need_insert = head->next;
            head->next = head->next->next;
            need_insert->next = pre->next;
            pre->next = need_insert;
        }
        return res->next;
    }
};
// @lc code=end

