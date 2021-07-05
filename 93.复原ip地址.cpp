/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原IP地址
 */

// @lc code=start
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if (s.size() < 4 || s.size() > 12) {
            return res;
        }
        vector<string> split;
        set<string> tmp;
        foo(s, 0, split, tmp);
        for (auto& s : tmp) {
            res.push_back(s);
        }
        return res;
    }
    void foo(string s, int current, vector<string> split,
                set<string>& res) {
        if (current >= s.size()) {
            if (split.size() == 4) {
                string ip;
                for (auto& str : split) {
                    ip += ".";
                    ip += str;
                }
                if (ip.size() == s.size() + 4) {
                    res.insert(ip.substr(1));
                }
            }
            return;
        }

        for (int i = 1; i < 4; ++i) {
            string splited = s.substr(current, i);
            int num = std::atoi(splited.c_str());
            if (num <= 255) {
                auto next = split;
                next.push_back(std::to_string(num));
                foo(s, current + i, next, res);
            }
        }
    }
};
// @lc code=end

