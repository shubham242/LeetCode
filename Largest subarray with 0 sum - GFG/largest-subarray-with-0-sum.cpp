// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution
{
public:
    int maxLen(vector<int> &A, int n)
    {
        int maxLen = 0;
        unordered_map<int, int> mp;
        mp[A[0]] = 0;

        for (int i = 0; i < n; i++)
        {
            if (i)
                A[i] += A[i - 1];
            if (A[i] == 0)
                maxLen = max(maxLen, i + 1);
            if (mp.find(A[i]) != mp.end())
                maxLen = max(maxLen, i - mp[A[i]]);
            else
                mp[A[i]] = i;
        }
        return maxLen;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends