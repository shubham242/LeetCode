class Solution {
public:
    string convertToTitle(int c) {
        string res;
        while(c>0)
        {
            if(c%26==0)
            {
                res+='Z';
                c=c/26-1;
            }
            else
            {
                res+=c%26+64;
                c/=26;
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};