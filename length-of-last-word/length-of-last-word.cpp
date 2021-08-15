class Solution {
public:
    int lengthOfLastWord(string s) {
        bool flag=false;
        int len=0;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(!flag)
            {
                if(s[i]!=' ')
                {
                    flag=true;
                    len++;
                }
            }
            else
            {
                if(s[i]!=' ')
                    len++;
                else
                    return len;
            }
        }
        return len;
    }
};