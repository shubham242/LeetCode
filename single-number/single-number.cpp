class Solution
{
public:
    int singleNumber(vector<int> &n)
    {
        map<int, int> mp;

        for (int i = 0; i < n.size(); i++)
            if (mp[n[i]])
                mp.erase(n[i]);
            else
                mp[n[i]]++;

        return mp.begin()->first;
    }
};