class Solution {
public:
    string com(string &s1,string &s2){
        int i;
        for(i=0;i<min(s1.size(),s2.size());i++){
            if(s1[i]!=s2[i])
                break;
        }
        return s1.substr(0,i);
    }
    string longestCommonPrefix(vector<string>& strs) {
        
        string ans=strs[0];
        for(int i=1;i<strs.size();i++)
            ans=com(ans,strs[i]);
        return ans;
    }
};