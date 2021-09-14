class Solution {
public:
    string reverseOnlyLetters(string s) {
        int start=0,end=s.size()-1;
        while(start<end)
        {
            bool st=(s[start]>='A'&&s[start]<='Z')||(s[start]>='a'&&s[start]<='z');
            bool en=(s[end]>='A'&&s[end]<='Z')||(s[end]>='a'&&s[end]<='z');
            if(st&&en)
            {
                swap(s[start],s[end]);
                start++;
                end--;
            }
            else if(st)
                end--;
            else 
                start++;
        }
        return s;
    }
};