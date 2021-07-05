/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) {
            return;
        }
        int idx = nums1.size() - 1;
        int l1 = m - 1;
        int l2 = n - 1;
        while (l1 >= 0 && l2 >= 0) {
            if (nums1[l1] < nums2[l2]) {
                nums1[idx] = nums2[l2];
                l2--;
            } else {
                nums1[idx] = nums1[l1];
                l1--;
            }
            idx--;
        }
        while (l2 >= 0) {
            nums1[idx--] = nums2[l2--]; 
        }
    }
};
// @lc code=end

