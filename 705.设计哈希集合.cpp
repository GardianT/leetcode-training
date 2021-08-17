/*
 * @lc app=leetcode.cn id=705 lang=cpp
 *
 * [705] 设计哈希集合
 */

// @lc code=start
class MyHashSet {
public:
    vector<bool> m;
    /** Initialize your data structure here. */
    MyHashSet() {
        m = std::vector<bool>(1000001);
    }
    
    void add(int key) {
        m[key] = true;
    }
    
    void remove(int key) {
        m[key] = false;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return m[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// @lc code=end

