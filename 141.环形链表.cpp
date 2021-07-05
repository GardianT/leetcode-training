/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
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
    bool hasCycle(ListNode *head) {
        auto t1 = head;
        auto t2 = head;
        while (t1 != nullptr && t2 != nullptr) {
            t1 = t1->next;
            t2 = t2->next;
            if (t2 != nullptr) {
                t2 = t2->next;
            } else {
                return false;
            }
            if (t1 == t2) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

