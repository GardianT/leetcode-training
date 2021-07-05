/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
    ListNode* partition(ListNode* head, int x) {
        auto n1 = new ListNode(0);
        auto n2 = new ListNode(0);
        auto tmp1 = n1;
        auto tmp2 = n2;
        while (head != nullptr) {
            if (head->val < x) {
                tmp1->next = head;
                tmp1 = tmp1->next;
                head = head->next;
                tmp1->next = nullptr;
            } else {
                tmp2->next = head;
                tmp2 = tmp2->next;
                head = head->next;
                tmp2->next = nullptr;
            }
        }
        tmp1->next = n2->next;
        return n1->next;
    }
};
// @lc code=end

