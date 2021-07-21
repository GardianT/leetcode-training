/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] N 叉树的最大深度
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    
    int maxDepth(Node* root) {
        if (root == nullptr) {
            return 0;
        }    
        int mx = 0;
        for (auto* node : root->children) {
            mx = max(maxDepth(node), mx);
        }
        return 1+mx;
    }
};
// @lc code=end

