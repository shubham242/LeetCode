class Solution {
public:
    int threeSumClosest(vector<int> n, int target)
    {
        sort(n.begin(), n.end());
        int res = n[0] + n[1] + n[2];
        for (int i = 0; i < n.size() - 1; i++)
        {
            int s = i + 1;
            int e = n.size() - 1;
            while (s < e)
            {
                res = abs(target - res) > abs(target - n[i] - n[s] - n[e]) ? n[i] + n[s] + n[e] : res;
                if (n[s] + n[e] + n[i] == target)
                    return target;
                else if (n[s] + n[e] + n[i] < target)
                    s++;
                else
                    e--;
            }
        }
        return res;
    }
};