/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

// @lc code=start
class Solution {
public:

    bool checkInclusion(string s1, string s2) {
        // 排除异常的边界情况，也限定了模式串的长度
        if(s1.size() > s2.size()) return false;
        
        // 匹配采用的窗口大小为模式串大小
        int windowSize = s1.size();
        
        // 模式串的字典：可以看做一种频率分布
        vector<int> hashmap1(26, 0);
        // 动态更新的匹配窗口字典
        vector<int> hashmap2(26, 0);
        
        // 构建字典
        for(int i = 0; i < windowSize; i++) {
            hashmap1[s1[i] - 'a']++;
            hashmap2[s2[i] - 'a']++;
        }
        
        // 对于每一轮滑窗查询，如果两个字典相等(频率分布一致)，则命中
        for(int i = windowSize; i < s2.size(); i++) {
            // 两个字典相等(频率分布一致)，则命中
            if(hashmap1 == hashmap2) return true;
            
            // 否则，向右滑窗：滑窗对于 hash 表的操作变为对应频率的增减
            hashmap2[s2[i - windowSize] - 'a']--;
            hashmap2[s2[i] - 'a']++;
        }
        
        // 整个算法采用左闭右开区间，因此最后还有一个窗口没有判断
        return hashmap1 == hashmap2;
    }
};
// @lc code=end

