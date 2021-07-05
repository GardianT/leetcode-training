/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] 反转字符串中的单词 III
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
      string res;
      auto idx = s.find(" ");
      auto last_idx = 0;
      std::string substr = "";
      while (idx != string::npos) {
        substr = s.substr(last_idx, idx - last_idx);
        res += reverse(substr);
        res += " ";
        last_idx = idx + 1;
        idx = s.find(" ", last_idx + 1);
      }
      substr = s.substr(last_idx);
      res += reverse(substr);
      return res;
    }
    string reverse(string s) {
      if (s.empty()) {
        return s;
      }
      string res;
      for (int i = s.size() - 1; i >= 0; --i) {
        res += s[i];
      }
      return res;
    }
};
// @lc code=end

