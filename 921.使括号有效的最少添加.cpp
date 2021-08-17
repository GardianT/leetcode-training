/*
 * @lc app=leetcode.cn id=921 lang=cpp
 *
 * [921] 使括号有效的最少添加
 */

// @lc code=start
class Solution {
public:
    int minAddToMakeValid(string s) {
        
        vector<int> nums(s.size(), 1);
        stack<int> tmp;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                tmp.push(i);
            } else {
                if (!tmp.empty()) {
                    nums[i] = 0;
                    nums[tmp.top()] = 0;
                    tmp.pop();
                }
            }
        }
        return std::accumulate(nums.begin(), nums.end(), 0);
    }
};
// @lc code=end

