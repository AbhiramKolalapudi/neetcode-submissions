class Twitter {
public:
    int time;
    unordered_map<int, vector<pair<int,int>>> tweetMap; //<userid, <time, tweetid>>
    unordered_map<int, unordered_set<int>> followMap; //<userid, following>
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) 
    {
        tweetMap[userId].push_back({time, tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) 
    {
        vector<int> res;

        // User should always see their own tweets
        followMap[userId].insert(userId);

        // {time, tweetId, userId, nextIndex}
        priority_queue<vector<int>> maxHeap;

        // Push the latest tweet of every followed user
        for (int user : followMap[userId])
        {
            if (tweetMap[user].empty())
                continue;

            int idx = tweetMap[user].size() - 1;

            maxHeap.push({
                tweetMap[user][idx].first,
                tweetMap[user][idx].second,
                user,
                idx - 1
            });
        }

        while (!maxHeap.empty() && res.size() < 10)
        {
            vector<int> cur = maxHeap.top();
            maxHeap.pop();

            int tweetId = cur[1];
            int user = cur[2];
            int nextIdx = cur[3];

            res.push_back(tweetId);

            // Push the next older tweet from the same user
            if (nextIdx >= 0)
            {
                maxHeap.push({
                    tweetMap[user][nextIdx].first,
                    tweetMap[user][nextIdx].second,
                    user,
                    nextIdx - 1
                });
            }
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) 
    {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) 
    {
        if (followMap[followerId].count(followeeId))
            followMap[followerId].erase(followeeId);
    }
};
