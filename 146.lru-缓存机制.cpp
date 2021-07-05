/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存机制
 */

// @lc code=start
class LRUCache {
public:
    LRUCache(int capacity) {
      cap_ = capacity;
    }
    
    int get(int key) {
      auto it = cache_.find(key);
      if (it == cache_.end()) {
        return -1;
      }
      cache_list_.splice(cache_list_.begin(), cache_list_, it->second);
      return it->second->second;
    }
    
    void put(int key, int value) {
      auto it = cache_.find(key);
      if (it != cache_.end()) {
        cache_list_.splice(cache_list_.begin(), cache_list_, it->second);
        it->second->second = value;
        return;
      }
      
      if (cache_.size() == cap_) {
        auto it = cache_list_.back();
        auto key = it.first;
        cache_list_.pop_back();
        cache_.erase(key);
      }
      std::pair<int, int> pair({key, value});
      cache_list_.push_front(pair);
      cache_[key] = cache_list_.begin();
    }
    std::list<std::pair<int, int>> cache_list_;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cache_;
    int cap_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

