/*
 * @lc app=leetcode.cn id=355 lang=cpp
 *
 * [355] 设计推特
 */

// @lc code=start
class Twitter {
public:
    unordered_map<int, vector<int>> feeds;
    unordered_map<int, vector<int>> f;
    vector<int> timeline;
    /** Initialize your data structure here. */
    Twitter() {
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        if (feeds.find(userId) == feeds.end()) {
            feeds[userId] = {tweetId};
        } else {
            feeds[userId].push_back(tweetId);
        }
        timeline.push_back(tweetId);
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        res = feeds[userId];
        for (auto& i : f[userId]) {
            res.insert(res.end(), 
                feeds[i].begin(), feeds[i].end());
        }
        std::sort(res.begin(), res.end(), [this](int a, int b) {
            return std::find(timeline.begin(), timeline.end(), a) > std::find(timeline.begin(), timeline.end(), b);
        });
        if (res.size() > 10) {
            res.resize(10);
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (f.find(followerId) == f.end()) {
            f[followerId] = {followeeId};
        } else {
            if (std::find(f[followerId].begin(), 
                f[followerId].end(), followeeId) == f[followerId].end()) {
                f[followerId].push_back(followeeId);
            }
            
        }
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (f.find(followerId) == f.end()) {
            return;
        } 
        auto it = std::find(f[followerId].begin(), 
            f[followerId].end(), followeeId);
        if (it != f[followerId].end()) {
            f[followerId].erase(it);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
// @lc code=end

