class Solution {
public:
    vector<int> decode(vector<int>& e, int first) {
        vector<int> res;
        res.push_back(first);
        int l=e.size();
        int curr=first;
        for(int i=0;i<l;i++)
        {
            res.push_back(curr^e[i]);
                curr=curr^e[i];
        }
        return res;
    }
};