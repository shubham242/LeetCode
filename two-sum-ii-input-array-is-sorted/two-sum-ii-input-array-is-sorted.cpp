class Solution {
public:
    vector<int> twoSum(vector<int>& n, int target) {
        
        int s=0,e=n.size()-1;
        while(n[s]+n[e]!=target)
        {
            if(n[s]+n[e]<target)
                s++;
            else
                e--;
        }
        vector<int> rs;
        rs.push_back(s+1);
        rs.push_back(e+1);
        
        return rs;
    }
};