class Solution
{
public:
    static bool comp(vector<int> v1, vector<int> v2)
    {
        return (v1[0] * v1[0]) + (v1[1] * v1[1]) < (v2[0] * v2[0]) + (v2[1] * v2[1]);
    }
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        sort(points.begin(), points.end(), comp);
        vector<vector<int>> res;
        for (int i = 0; i < k; i++)
            res.push_back(points[i]);
        return res;
    }
};