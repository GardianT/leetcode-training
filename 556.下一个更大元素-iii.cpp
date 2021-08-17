/*
 * @lc app=leetcode.cn id=556 lang=cpp
 *
 * [556] 下一个更大元素 III
 */

// @lc code=start
class Solution {
public:
    bool foo(vector<int>& res) {
        int i = res.size() - 1;
        while (i > 0 && res[i] < res[i - 1]) {
            i--;
        }

        if (i == 0) {
            return false;
        } 
        i = i - 1;
        for (int j = res.size() - 1; j >= i; j--) {
            if (res[j] > res[i]) {
                swap(res[j], res[i]);
                std::sort(res.begin() + i + 1, res.end());
                return true;
            }
        }
        return false;
    }
    int nextGreaterElement(int n) {
        // vector<int> tmp;
        // while (n > 0) {
        //     tmp.insert(tmp.begin(), n % 10);
        //     n /= 10;
        // }
        // if (!foo(tmp)) {
        //     return -1;
        // }
        // int res = 0;
        // for (int i = 0; i < tmp.size(); ++i) {
        //     res *= 10;
        //     res += tmp[i];
        // }
        // return res;

        if(n < 10) return -1;
        string str = to_string(n);
        next_permutation(str.begin(), str.end());
        long val = stol(str);
        if(val > INT_MAX || val <= n) return -1;
        return val;
    }
};
// @lc code=end

