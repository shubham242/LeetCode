class Solution {
public:
    void merge(vector<int>& n1, int m, vector<int>& n2, int n) {
        vector<int> arr=n1;
        n1.clear();
        int i=0,j=0;
        while(i!=m&&j!=n)
        {
            if(arr[i]<n2[j])
            {
                n1.push_back(arr[i]);
                i++;
            }
            else
            {
                n1.push_back(n2[j]);
                j++;
            }
        }
        if(j<n)
            while(j<n)
            {
                n1.push_back(n2[j]);
                j++;
            }
        
        if(i<m)
            while(i<m)
            {
                n1.push_back(arr[i]);
                i++;
            }
    }
};