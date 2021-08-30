/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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
    ListNode* merge2lists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        }
        if (l2 == nullptr) {
            return l1;
        }
        ListNode* tmp = new ListNode(0);
        ListNode* res = tmp;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tmp->next = l1;
                l1 = l1->next;
            } else {
                tmp->next = l2;
                l2 = l2->next;
            }
            tmp = tmp->next;
        }
        if (l1) {
            tmp->next = l1;
        }
        if (l2) {
            tmp->next = l2;
        }
        return res->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return nullptr;
        }
        if (lists.size() == 1) {
            return lists[0];
        }
        if (lists.size() % 2 == 1) {
            lists.push_back(nullptr);
        }
        vector<ListNode*> nt;
        for (int i = 0; i < lists.size(); i+=2) {
            nt.push_back(merge2lists(lists[i], lists[i+1]));
        }
        return mergeKLists(nt);
    }
};
// @lc code=end

