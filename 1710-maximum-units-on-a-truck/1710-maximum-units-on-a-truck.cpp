class Solution
{
public:
    static bool cmp(const vector<int> &v1, const vector<int> &v2)
    {
        return v1[1] > v2[1];
    }
    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
    {
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        int i = 0, res = 0, n = boxTypes.size();
        while (truckSize && i < n)
        {
            if (truckSize - boxTypes[i][0] > 0)
            {
                res += boxTypes[i][1] * boxTypes[i][0];
                truckSize -= boxTypes[i][0];
            }
            else
            {
                res += boxTypes[i][1] * (truckSize);
                truckSize = 0;
            }
            i++;
        }
        return res;
    }
};