/*
 * @lc app=leetcode.cn id=389 lang=cpp
 *
 * [389] 找不同
 */

// @lc code=start
class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> m;
        for (int i = 0; i < t.size(); i++) {
            m[t[i]]++;
        }
        for (int i = 0; i < s.size(); i++) {
            m[s[i]]--;
        }
        for (const auto& kv : m) {
            if (kv.second == 1) {
                return kv.first;
            }
        }
        return '\0';
    }
};
// @lc code=end

