// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution
{
public:
    void solve(vector<vector<int>> &m, int n, string curr, vector<string> &ans, int x, int y)
    {
        if (x == n - 1 && y == n - 1)
        {
            ans.push_back(curr);
            return;
        }

        if (x - 1 >= 0 && m[x - 1][y] == 1)
        {
            m[x - 1][y] = 0;
            solve(m, n, curr + "U", ans, x - 1, y);
            m[x - 1][y] = 1;
        }
        if (y - 1 >= 0 && m[x][y - 1] == 1)
        {
            m[x][y - 1] = 0;
            solve(m, n, curr + "L", ans, x, y - 1);
            m[x][y - 1] = 1;
        }
        if (x + 1 < n && m[x + 1][y] == 1)
        {
            m[x + 1][y] = 0;
            solve(m, n, curr + "D", ans, x + 1, y);
            m[x + 1][y] = 1;
        }
        if (y + 1 < n && m[x][y + 1] == 1)
        {
            m[x][y + 1] = 0;
            solve(m, n, curr + "R", ans, x, y + 1);
            m[x][y + 1] = 1;
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        vector<string> ans;
        if (m[0][0] == 0)
            return ans;
        m[0][0] = 0;
        solve(m, n, "", ans, 0, 0);
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends