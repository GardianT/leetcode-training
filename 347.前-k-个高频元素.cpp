/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      map<int, int> m;
      for (const auto& i : nums) {
        m[i]++;
      }
      
      vector<pair<int, int>> cnt;
      for (const auto& kv : m) {
        auto it = std::lower_bound(cnt.begin(), cnt.end(), kv, [](std::pair<int, int> a, std::pair<int, int>b){
          return a.second < b.second;
        });
        cnt.insert(it, kv);
        if (cnt.size() > k) {
          cnt.erase(cnt.begin());
        }
      }
      vector<int> res;
      for (const auto& kv : cnt) {
        res.push_back(kv.first);
      }
      
      return res;
    }
};
// @lc code=end

