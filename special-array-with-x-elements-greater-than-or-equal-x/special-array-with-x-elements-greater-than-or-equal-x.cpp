class Solution {
public:
    int specialArray(vector<int>& nums) 
    {
        int n=nums.size();
        int start=0;
        int end= nums.size()+1;
      
        
        while(start<=end)
        {
            int middle=(start+end)/2;
            int cnt = 0;
            for(int i=0;i<n;i++)
                if(nums[i]>=middle)
                    cnt++;
            if(cnt==middle)
            {
                return middle;
            }
            else if(cnt>middle)
            {
                start = middle+1;
            }
            else end = middle-1;
        }
        
        return -1;
        
    }
};