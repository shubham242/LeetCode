class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();
        vector<int> hash(1001,0);
        for(int i=0;i<n;i++){
            for(int j=trips[i][1];j<trips[i][2];j++){
                hash[j]+=trips[i][0];
                if(hash[j]>capacity)
                    return false;
            }
        }

        return true;
    }
};