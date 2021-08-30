/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> t;
        map<char, char> m = {
            {'(', ')'},
            {'[', ']'},
            {'{', '}'}
        };
        for (int i = 0; i < s.size(); ++i) {
            if (t.empty()) {
                if (m.find(s[i]) != m.end()) {
                    t.push(s[i]);
                } else {
                    return false;
                }
            } else {
                if (m[t.top()] == s[i]) {
                    t.pop();
                } else {
                    if (m.find(s[i]) != m.end()) {
                        t.push(s[i]);
                    } else {
                        return false;
                    }  
                }
            }
        }
        return t.empty();
    }
};
// @lc code=end

