class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();
        vector<int> hash(1001,0);
        for(int i=0;i<n;i++){
            hash[trips[i][1]]+=trips[i][0];
            hash[trips[i][2]]-=trips[i][0];
        }
        int count=0;
        for(int i=0;i<=1000;i++)
        {
            count+=hash[i];
            if(count>capacity)
                return false;
        }

        return true;
    }
};