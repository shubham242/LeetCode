class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;
        int a[26]={0};
        
        for(int i=0;s[i]!='\0';i++)
        {
            a[s[i]-97]++;
            a[t[i]-97]--;
        }
        
        for(int i=0;i<26;i++)
            if(a[i]!=0)
                return false;
        return true;
    }
};