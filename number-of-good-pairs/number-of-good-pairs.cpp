class Solution {
public:
    int numIdenticalPairs(vector<int>& n) {
        int count=0;
        for(int i=0;i<n.size()-1;i++)
            for(int j=i+1;j<n.size();j++)
                if(n[i]==n[j])
                    count++;
    return count;
    }
};