class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        
        long int prev = 1;
        res.push_back(prev);
 
        for (int i = 1; i <= rowIndex; i++) {
            long int curr = (prev * (rowIndex - i + 1))/i;
            res.push_back(curr);
            prev = curr;
        }
        
        return res;
        
    }
};