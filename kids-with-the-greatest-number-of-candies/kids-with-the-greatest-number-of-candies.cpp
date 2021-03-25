static const auto fast = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& c, int eC) {
        int max=*max_element(c.begin(),c.end());
        vector<bool> x;
        for(int i=0;i<c.size();i++)
        {
            if(c[i]+eC>=max)
                x.push_back(true);
            else
                x.push_back(false);
        }
        return x;
    }
};