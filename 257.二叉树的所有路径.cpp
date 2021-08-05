/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    vector<string> res;
    void foo(TreeNode* root, string s) {
        if (root == nullptr) {
            return;
        }
        if (root->left == nullptr && root->right == nullptr) {
            if (!s.empty()) {
                res.push_back(s + "->" + std::to_string(root->val));
            } else {
                res.push_back(std::to_string(root->val));
            }
            return;
        }
        string nxt = s;
        if (!nxt.empty()) {
            nxt += "->";
        }
        nxt += std::to_string(root->val);
        foo(root->left, nxt);
        foo(root->right, nxt);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        foo(root, "");
        return res;
    }
};
// @lc code=end

