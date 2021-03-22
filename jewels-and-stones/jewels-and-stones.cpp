class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        sort(stones.begin(),stones.end());
        int count=0;
        for(int i=0;i<jewels.size();i++)
        {
            string::iterator lower,upper;
            lower = lower_bound(stones.begin(),stones.end(),jewels[i]);
            upper = upper_bound(stones.begin(),stones.end(),jewels[i]);
            count+=upper-lower;
        }
        return count;
        
    }
};