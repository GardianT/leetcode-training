/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int base, count, maxCount;
    vector<int> answer;

    void update(int x) {
        if (x == base) {
            ++count;
        } else {
            count = 1;
            base = x;
        }
        if (count == maxCount) {
            answer.push_back(base);
        }
        if (count > maxCount) {
            maxCount = count;
            answer = vector<int> {base};
        }
    }
    void foo(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        foo(root->left);
        update(root->val);
        foo(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        base = INT_MIN;
        count = 0;
        foo(root);
        return answer;
    }
};

// @lc code=end

