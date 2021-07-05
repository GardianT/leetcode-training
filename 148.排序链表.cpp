/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
    ListNode* findMid(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        auto l1 = head;
        auto l2 = head;
        auto res = head;
        while (l2 != nullptr && l2->next != nullptr) {
            res = l1;
            l1 = l1->next;
            l2 = l2->next->next;
        }
        return res;
    }

    ListNode* merge(ListNode* l, ListNode* r) {
        if (l == nullptr) {
            return r;
        }
        if (r == nullptr) {
            return l;
        }
        auto tmp = new ListNode(0);
        auto res = tmp;
        auto left = l;
        auto right = r;
        while (left != nullptr && right != nullptr) {
            if (left->val < right->val) {
                tmp->next = left;
                left = left->next;
            } else {
                tmp->next = right;
                right = right->next;
            }
            tmp = tmp->next;
            tmp->next = nullptr;
        }
        if (left != nullptr) {
            tmp->next = left;
        } else {
            tmp->next = right;
        }
        return res->next;
    }

    ListNode* mergeSort(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        auto tmp = head;
        auto mid = findMid(head);
        auto next = mid->next;
        mid->next = nullptr;
        auto left = mergeSort(tmp);
        auto right = mergeSort(next);
        return merge(left, right);
    }

    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};
// @lc code=end

