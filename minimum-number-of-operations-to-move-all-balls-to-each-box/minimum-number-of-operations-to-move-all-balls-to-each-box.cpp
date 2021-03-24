class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> x;
        for(int i=0;i<boxes.size();i++)
        {
            int count=0;
            
            for(int j=i+1;j<boxes.size();j++)
            {
                if(boxes[j]=='1')
                    count+=j-i;
            }
            for(int k=i-1;k>=0;k--)
            {
                if(boxes[k]=='1')
                    count+=i-k;
            }
            x.push_back(count);
        }
        return x;
    }
};