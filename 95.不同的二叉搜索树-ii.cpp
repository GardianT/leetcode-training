/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        if (n == 0) {
            return res;
        }
        return foo(1, n);
    }
    vector<TreeNode*> foo(int l, int r) {
        vector<TreeNode*> res;
        if (l > r) {
            res.push_back(nullptr);
            return res;
        }

        for (int i = l; i <= r; ++i) {
            auto left = foo(l, i - 1);
            auto right = foo(i + 1, r);
            for (auto lnode : left) {
                for (auto rnode: right) {
                    auto current = new TreeNode(i);
                    current->left = lnode;
                    current->right = rnode;
                    res.push_back(current);
                }
            }
        }
        return res;
    }
};
// @lc code=end

