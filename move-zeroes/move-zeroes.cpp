class Solution {
public:
    void moveZeroes(vector<int>& n) {
        int s=0;
        int l=n.size();
        bool f=false;
        for(int i=0;i<l;i++)
            if(n[i]==0)
            {
                s=i;
                f=true;
                break;
            }
        if(f)
        {
            for(int i=s+1;i<l;i++)
            {
                if(n[i]!=0)
                {
                    swap(n[i],n[s]);
                    s++;
                }
            }
        }
    }
};