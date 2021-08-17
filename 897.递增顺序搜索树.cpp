/*
 * @lc app=leetcode.cn id=897 lang=cpp
 *
 * [897] 递增顺序搜索树
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
    bool visited(vector<TreeNode*> visited, TreeNode* head) {
        for (const auto& i : visited) {
            if (i == head) {
                return true;
            }
        }
        return false;
    }

    TreeNode* increasingBST(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        TreeNode* res = new TreeNode(0);
        TreeNode* val = res;
        stack<TreeNode*> tmp;
        vector<TreeNode*> visit;
        tmp.push(root);
        while (!tmp.empty()) {
            TreeNode* head = tmp.top();
            if (head->left != nullptr && !visited(visit, head->left)) {
                tmp.push(head->left);
                //cout << head->left->val << endl;
                head->left = nullptr;
            } else {
                tmp.pop();
                if (head->right != nullptr) {
                    tmp.push(head->right);
                    //cout << head->right->val << endl;
                }
                head->right = nullptr;
                res->right = head;
                //cout << head->val << endl;
                res = res->right;
                visit.push_back(res);
            }
        } 
        return val->right;
    }
};
// @lc code=end

