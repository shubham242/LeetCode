class Solution {
public:
    static bool sortcol( const vector<int>& v1,const vector<int>& v2 ) {
        return v1[0] < v2[0];
    }
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        
        sort(points.begin(),points.end(),sortcol);
        int max=0;
        for(int i=1;i<points.size();i++)
            if(points[i][0]-points[i-1][0]>=max)
                max=points[i][0]-points[i-1][0];
        return max;
    }
};