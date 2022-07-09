class Solution
{
public:
    unordered_map<int, int> mp;
    bool canReach(vector<int> &arr, int start)
    {
        if (arr[start] == 0)
            return true;
        mp[start] = 1;

        if (start - arr[start] >= 0 && mp[start - arr[start]] == 0 && canReach(arr, start - arr[start]))
            return true;

        if (start + arr[start] < arr.size() && mp[start + arr[start]] == 0 && canReach(arr, start + arr[start]))
            return true;

        return false;
    }
};