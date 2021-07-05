/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr) {
            return head;
        }
        auto l1 = head;
        auto l2 = head;
        bool has_cycle = false;
        while (l1 != nullptr && l2 != nullptr) {
            l1 = l1->next;
            l2 = l2->next;
            if (l2 != nullptr) {
                l2 = l2->next;
            } else {
                return nullptr;
            }
            if (l1 == l2) {
                has_cycle = true;
                break;
            }
        }
        if (has_cycle) {
            auto res = head;
            while (l1 != res) {
                l1 = l1->next;
                res = res->next;
            }
            return res;
        }
        return nullptr;
    }
};
// @lc code=end

