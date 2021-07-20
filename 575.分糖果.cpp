/*
 * @lc app=leetcode.cn id=575 lang=cpp
 *
 * [575] 分糖果
 */

// @lc code=start
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        set<int> res;
        for (const auto& i : candyType) {
            res.insert(i);
        }
        return min(res.size(), candyType.size() / 2);
    }
};
// @lc code=end

