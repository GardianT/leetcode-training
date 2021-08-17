/*
 * @lc app=leetcode.cn id=915 lang=cpp
 *
 * [915] 分割数组
 */

// @lc code=start
class Solution {
public:
    int partitionDisjoint(vector<int>& input) {
        multiset<int> left;
        multiset<int> right;
        for(int i=0;i<input.size();++i) {
            right.insert(input[i]);
        }
        for(int i = 0; i < input.size() ; ++i) {
            left.insert(input[i]);
            //cout<<*left.rbegin()<<"-"<<*right.begin()<<endl;
            right.erase(right.find(input[i]));
            if(*left.rbegin()<=*right.begin()) {
                return i+1;
            }
        }
        return input.size()-1;
    }
};
// @lc code=end

