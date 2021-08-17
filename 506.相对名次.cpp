/*
 * @lc app=leetcode.cn id=506 lang=cpp
 *
 * [506] 相对名次
 */

// @lc code=start
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<pair<int, int>> tmp;
        for (int i = 0; i < score.size(); ++i) {
            tmp.insert(std::lower_bound(tmp.begin(), tmp.end(),
                    std::pair<int, int>({score[i], i}), [](const pair<int, int>& a, const pair<int, int>& b) {
                        return a.first > b.first;
                    }), std::pair<int, int>({score[i], i}));
        }
        vector<string> res(score.size());
        for (int i = 0; i < tmp.size(); ++i) {
            if (i == 0) {
                res[tmp[i].second] = "Gold Medal";
            } else if (i == 1) {
                res[tmp[i].second] = "Silver Medal";
            } else if (i == 2) {
                res[tmp[i].second] = "Bronze Medal";
            } else {
                res[tmp[i].second] = std::to_string(i+1);
            }
        }
        return res;
    }
};
// @lc code=end

