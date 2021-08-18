class Solution {
public:
    bool isPalindrome(string s) {
        
        int st=0;
        int e=s.size()-1;
        
        
    transform(s.begin(), s.end(), s.begin(), ::tolower);
        
        while(st<e)
        {
            if(((s[st]>=48 && s[st]<=57)||(s[st]>=97 && s[e]<=122)) && ((s[e]>=48 && s[e]<=57)||(s[e]>=97 && s[e]<=122)))
            {
                if(s[st]!=s[e])
                    return false;
                else
                {
                    st++;
                    e--;
                }
            }
            else if(!((s[st]>=48 && s[st]<=57)||(s[st]>=97 && s[e]<=122)))
                st++;
            else
                e--;
        }
        
        return true;
        
    }
};