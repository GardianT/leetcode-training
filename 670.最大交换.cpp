/*
 * @lc app=leetcode.cn id=670 lang=cpp
 *
 * [670] 最大交换
 */

// @lc code=start
class Solution {
public:
    int last_idx(vector<int> s, int target) {
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == target) {
                return i;
            }
        }
        return 0;
    }

    int maximumSwap(int num) {
        vector<int> s;
        if (num == 0) {
            return num;
        }
        while (num > 0) {
            s.insert(s.begin(), num % 10);
            num /= 10;
        }
        auto m = s;
        std::sort(m.begin(), m.end(), std::greater<int>());
        int res = 0;
        bool sw = false;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != m[i] && !sw) {
                std::swap(s[i], s[last_idx(s, m[i])]);
                sw = true;
            }
            res = res * 10 + s[i];
        }
        return res;
    }
};
// @lc code=end

