/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
vector<int> ret;
vector<TreeNode*> visited;
bool visit(TreeNode* root) {
  if (root == nullptr) {
    return true;
  }
  return std::find(visited.begin(), visited.end(), root) != visited.end();
}

vector<int> postorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return ret;
    }
    
    stack<TreeNode*> tmp;
    tmp.push(root);
    while (!tmp.empty()) {
      TreeNode* current = tmp.top();
      if (visit(current->left) && visit(current->right)) {
        tmp.pop();
        ret.push_back(current->val);
        visited.push_back(current);
      } else {
        if (current->right != nullptr) {
          tmp.push(current->right);
        }
        if (current->left != nullptr) {
          tmp.push(current->left);
        }
      }
    }
    //postorder(root);
    return ret;
}
void postorder(TreeNode* root) {
    if (root != nullptr) {
        postorder(root->left);
        postorder(root->right);
        ret.push_back(root->val);
    }
}
}; 
// @lc code=end

