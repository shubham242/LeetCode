static const auto fast =[]()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int> v;
        for(int i=0;i<points.size();i++)
            v.push_back(points[i][0]);
        sort(v.begin(),v.end());
        int max=0;
        for(int i=1;i<points.size();i++)
            if(v[i]-v[i-1]>=max)
                max=v[i]-v[i-1];
        return max;
    }
};