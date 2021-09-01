class Solution {
public:
    bool containsNearbyDuplicate(vector<int> n, int k)
    {
        unordered_map<int, int> mp;
        int s=n.size();
        for (int i = 0; i < s; i++)
        {
            if (mp[n[i]] > 0)
                if (i + 1 - mp[n[i]] <= k)
                    return true;
                else
                    mp[n[i]] = i + 1;
            else
                mp[n[i]] = i + 1;
        }
        return false;
    }
};