/*
 * @lc app=leetcode.cn id=1287 lang=cpp
 *
 * [1287] 有序数组中出现次数超过25%的元素
 */

// @lc code=start
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int res = arr[0];
        int count = 1;
        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i] == res) {
                count++;
            } else {
                if (count > arr.size() / 4) {
                    return res;
                }
                res = arr[i];
                count = 1;
            }
        }
        return res;
    }
};
// @lc code=end

