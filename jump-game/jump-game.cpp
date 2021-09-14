static const auto fast = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
class Solution {
public:
    bool canJump(vector<int> &A)
    {
        int i = 0,n=A.size();
        for (int reach = 0; i < n && i <= reach; ++i)
        {
            reach = max(i + A[i], reach);
            if(reach>=n-1)
                return true;
        }
        return false;
    }
};