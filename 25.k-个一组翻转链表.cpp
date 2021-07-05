/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
int len(ListNode* root) {
  int res = 0;
  auto tmp = root;
  while (tmp != nullptr) {
    ++res;
    tmp = tmp->next;
  }
  return res;
}

ListNode* reverseKGroup(ListNode* head, int k) {
  if (len(head) < k) {
    return head;
  }
  ListNode* n1 = head;
  ListNode* n2 = head;
  for (int i = 1; i < k; ++i) {
      n2 = n2->next;
  }
  ListNode* next = reverseKGroup(n2->next, k);
  n2->next = nullptr;
  ListNode* pre = nullptr;
  while (n1 != nullptr) {
      ListNode* n = n1->next;
      n1->next = pre;
      pre = n1;
      n1 = n;
  }
  n2 = pre;
  while (n2->next != nullptr) {
    n2 = n2->next;
  }
  n2->next = next;
  return pre; 
}
};
// @lc code=end

