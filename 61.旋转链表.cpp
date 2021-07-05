/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
    ListNode* rotateRight(ListNode* head, int k) {
      if (head == nullptr || head->next == nullptr || k == 0) {
        return head;
      }
      int n = 0;
      for (auto tmp = head; tmp != nullptr; tmp = tmp->next) {
        ++n;
      }
      int left_k = k % n;
      if (left_k == 0) {
          return head;
      }
      auto n1 = head;
      while (left_k > 0) {
        n1 = n1->next;
        left_k--;
      }
      auto n2 = head;
      while (n1->next != nullptr) {
        n1 = n1->next;
        n2 = n2->next;
      }
      auto res = n2->next;
      n2->next = nullptr;
      n1->next = head;
      return res;
    }
};
// @lc code=end

