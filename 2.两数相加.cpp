/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0);
        ListNode* head = res;
        int carry = 0;
        while (l1 != nullptr && l2 != nullptr) {
            auto val = l1->val + l2->val + carry;
            carry = val / 10;
            val %= 10;
            head->next = new ListNode(val);
            head = head->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != nullptr) {
            auto val = l1->val + carry;
            carry = val / 10;
            val %= 10;
            head->next = new ListNode(val);
            l1 = l1->next;
            head = head->next;
        }
        while (l2 != nullptr) {
            auto val = l2->val + carry;
            carry = val / 10;
            val %= 10;
            head->next = new ListNode(val);
            l2 = l2->next;
            head = head->next;
        }
        if (carry) {
            auto val = carry;
            head->next = new ListNode(carry);
            head = head->next;
            carry = 0;
        }
        return res->next;
    }
};
// @lc code=end

