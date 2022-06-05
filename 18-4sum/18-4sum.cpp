class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &n, int target)
    {
        vector<vector<int>> ans;
        int l = n.size();
        if (l < 4)
            return ans;
        sort(n.begin(), n.end());
        int i = 0;
        while (i < l)
        {
            int j = i + 1;
            while (j < l)
            {
                int le = j + 1, ri = l - 1;

                while (le < ri)
                {
                    if (n[le] + n[ri] < target - n[i] - n[j])
                        le++;
                    else if (n[le] + n[ri] > target - n[i] - n[j])
                        ri--;
                    else
                    {
                        vector<int> temp;
                        temp.push_back(n[i]);
                        temp.push_back(n[j]);
                        temp.push_back(n[le]);
                        temp.push_back(n[ri]);
                        ans.push_back(temp);
                        while (le < l - 1 && n[le + 1] == n[le])
                            le++;
                        le++;
                        while (ri > 0 && n[ri - 1] == n[ri])
                            ri--;
                        ri--;
                    }
                }

                while (j < l - 1 && n[j + 1] == n[j])
                    j++;
                j++;
            }
            while (i < l - 1 && n[i + 1] == n[i])
                i++;
            i++;
        }
        return ans;
    }
};