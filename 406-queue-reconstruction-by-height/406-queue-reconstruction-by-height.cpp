class Solution
{
public:
    static bool comp(const vector<int> &v1, const vector<int> &v2)
    {
        if (v1[0] < v2[0])
            return true;
        else
            return v1[0] == v2[0] && v1[1] > v2[1];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        int n = people.size();
        sort(people.begin(), people.end(), comp);
        vector<vector<int>> res;
        for (int i = n - 1; i >= 0; i--)
            res.insert(res.begin() + people[i][1], people[i]);

        return res;
    }
};