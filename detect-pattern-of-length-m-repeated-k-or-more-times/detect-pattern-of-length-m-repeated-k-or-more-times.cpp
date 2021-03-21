class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        int count=1;
        for(int i=m;i<arr.size();)
        {
            int f=0;
            for(int j=0;j<m;j++)
            {
                if(arr[i-m+j]!=arr[i+j])
                {
                    f=1;
                    break;
                }
                else
                {
                    f=0;
                }
            }
            if(f==1)
            {
                count=1;
                i++;
            }
            else
            {
                count++;
                if(count>=k)
                    return true;
                i+=m;
            }
            
        }
        return false;
        
    }
};