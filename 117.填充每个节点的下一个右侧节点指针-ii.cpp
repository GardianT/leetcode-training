/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) {
            return root;
        }
        vector<Node*> current;
        vector<Node*> next;
        current.push_back(root);
        while (!current.empty()) {
            Node* pre = nullptr;
            for (const auto node: current) {
                if (node->left != nullptr) {
                    next.push_back(node->left);
                }
                if (node->right != nullptr) {
                    next.push_back(node->right);
                }
                if (pre != nullptr) {
                    pre->next = node;
                }
                pre = node;
            }
            pre->next = nullptr;
            current = next;
            next.clear();
        }
        return root;
    }
};
// @lc code=end

