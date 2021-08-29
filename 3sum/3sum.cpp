class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &n)
    {
        sort(n.begin(),n.end());
        vector<vector<int>> res;
        for (int i = 0; i < n.size(); i++)
        {
            if(i>0&&n[i]==n[i-1])
                continue;
            unordered_set<int> s;
            for (int j = i + 1; j < n.size(); j++)
            {
                int temp = -n[i] - n[j];

                if (s.find(temp) != s.end())
                {
                    vector<int> temp;
                    temp.push_back(n[i]);
                    temp.push_back(n[j]);
                    temp.push_back(-n[i] - n[j]);
                    res.push_back(temp);
                    while(j<n.size()-1&&n[j]==n[j+1])
                        j++;
                }

                s.insert(n[j]);
            }
        }
        return res;
    }
};