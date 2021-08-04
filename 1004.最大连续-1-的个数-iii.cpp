/*
 * @lc app=leetcode.cn id=1004 lang=cpp
 *
 * [1004] 最大连续1的个数 III
 */

// @lc code=start
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int result = 0;
        int slow = 0;
        int cur = 0;
        for (int fast = 0; fast < nums.size(); fast++) {
            if (nums[fast] == 0) //检测为0，目前零数+1
                cur += 1;
            while (cur > k) { //当不符合条件了就缩小窗口
                if (nums[slow] == 0)
                    cur -= 1;
                slow++;
            }
            result = max(result, fast - slow + 1); //取得最优解
        }
        return result;
    }
};
// @lc code=end

