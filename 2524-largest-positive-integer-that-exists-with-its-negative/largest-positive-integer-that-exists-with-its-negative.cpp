class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int hash[2001]={0}, largest=-1;

        for(int i : nums)
            hash[i+1000]++;
        
        for(int i : nums)
            if(i>0 && hash[1000-i]>0)
                largest=max(largest,i);

        return largest;
    }
};