class Solution {
public:
    bool comp(int a,int b)
    {
        return(a<b);
    }
    int minPartitions(string n) {
        char max='0';
        for(int i=0;i<n.size();i++)
        {
            if(n[i]>=max)
                max=n[i];
            if(n[i]=='9')
                break;
        }
        return (int)max-48;
    }
};