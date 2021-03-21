class Solution {
public:
    vector<string> summaryRanges(vector<int>& n) {
        vector<string> str={};
        if(n.size()==0)
            return str;
        int l=n[0],u=n[0];
        for(int i=0;i<n.size()-1;i++)
        {
            if(n[i]+1==n[i+1])
                u=n[i+1];    
            else
            {
                if(l==u)
                    str.push_back(to_string(l));
                else
                    str.push_back(to_string(l)+"->"+to_string(u));
                l=n[i+1];
                u=n[i+1];    
            }
        }
        if(l==u)
                    str.push_back(to_string(l));
                else
                    str.push_back(to_string(l)+"->"+to_string(u));
        return str;
    }
};