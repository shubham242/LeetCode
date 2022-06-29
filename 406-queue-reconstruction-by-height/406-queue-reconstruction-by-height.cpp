class Solution
{
public:
    static bool comp(const vector<int> &v1, const vector<int> &v2)
    {
        if (v1[0] < v2[0])
            return true;
        else if (v1[0] == v2[0])
            return v1[1] > v2[1];
        else
            return false;
    }
    void putPos(vector<vector<int>> &res, vector<int> val, int pos)
    {
        int curr = 0;

        for (int i = 0; i < res.size(); i++)
        {

            if (res[i].size() == 0)
                curr++;
            if (curr == pos)
            {
                res[i] = val;
                break;
            }
        }
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        int n = people.size();
        sort(people.begin(), people.end(), comp);
        vector<vector<int>> res(n, vector<int>(0));
        for (int i = 0; i < n; i++)
            putPos(res, people[i], people[i][1] + 1);

        return res;
    }
};