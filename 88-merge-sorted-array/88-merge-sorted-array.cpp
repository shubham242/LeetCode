class Solution {
public:
    void merge(vector<int>& n1, int m, vector<int>& n2, int n) {
        int i=m-1,j=n-1,k=m+n-1;
        while(j>=0)
        {
            if(i>=0&&n1[i]>n2[j])
            {
                n1[k]=n1[i];
                i--;
                k--;
            }
            else
            {
                n1[k]=n2[j];
                j--;
                k--;
            }
        }
    }
};