/*
 * @lc app=leetcode.cn id=946 lang=cpp
 *
 * [946] 验证栈序列
 */

// @lc code=start
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> m;
        int i = 0;
        for (int j = 0; j < pushed.size(); ++j) {
            m.push(pushed[j]);
            while (!m.empty() && m.top() == popped[i]) {
                m.pop();
                i++;
            }
        }
        return m.empty();
    }
};
// @lc code=end

