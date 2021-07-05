/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) {
            return nullptr;
        }
        return buildTree(preorder, 0, preorder.size() - 1, 
                            inorder, 0, inorder.size() - 1);
    }

    TreeNode* buildTree(vector<int>& preorder, int l1, int l2, 
                vector<int>& inorder, int r1, int r2) {
        if (l1 > l2 || r1 > r2) {
            return nullptr;
        }

        auto root = new TreeNode(preorder[l1]);
        auto pos = std::distance(inorder.begin(), 
                    std::find(inorder.begin(), inorder.end(), preorder[l1]));
        auto dis = pos - r1;

        root->left = buildTree(preorder, l1 + 1, l1 + dis, inorder, r1, pos - 1);
        root->right = buildTree(preorder, l1 + dis + 1, l2, inorder, pos + 1, r2);
        return root;
    }
};
// @lc code=end

