/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto t1 = headA;
        auto t2 = headB;
        int l1 = 0;
        int l2 = 0;
        while (t1 != nullptr) {
            ++l1;
            t1 = t1->next;
        }
        while (t2 != nullptr) {
            ++l2;
            t2 = t2->next;
        }
        t1 = headA;
        t2 = headB;
        if (l1 > l2) {
            for (int i = 0; i < l1 - l2; ++i) {
                t1 = t1->next;
            }
        } else {
            for (int i = 0; i < l2 - l1; ++i) {
                t2 = t2->next;
            }
        }
        while (t1 != t2) {
            t1 = t1->next;
            t2 = t2->next;
        }
        return t1;
    }
};
// @lc code=end

