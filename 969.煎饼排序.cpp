/*
 * @lc app=leetcode.cn id=969 lang=cpp
 *
 * [969] 煎饼排序
 */

// @lc code=start
class Solution {
public:
    
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> res;
        int cur = arr.size();
        while (cur != 1) {
            if (arr[cur-1] != cur) {
                for (int j = 0; j < cur - 1; j++) {
                    if (arr[j] == cur) {
                        if (j != 0) {
                            res.push_back(j+1);
                            reverse(arr.begin(), arr.begin() + j + 1);
                        }
                        res.push_back(cur);
                        reverse(arr.begin(), arr.begin() + cur);
                        break;
                    }
                }
            }
            cur--;
        }
        return res;
    }
};



// @lc code=end

