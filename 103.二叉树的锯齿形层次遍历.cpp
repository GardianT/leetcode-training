/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层次遍历
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) {
            return res;
        }
        vector<TreeNode*> current;
        vector<TreeNode*> next;
        current.push_back(root);
        bool flag = true;
        while (!current.empty()) {
            vector<int> now;
            for (auto node : current) {
                if (node->left != nullptr) {
                    next.push_back(node->left);
                }
                if (node->right != nullptr) {
                    next.push_back(node->right);
                }
                now.push_back(node->val);
            }
            if (flag) {
                res.push_back(now);
            } else {
                std::reverse(now.begin(), now.end());
                res.push_back(now);
            }
            flag = !flag;
            current = next;
            next.clear();
        } 
        return res;
    }
};
// @lc code=end

