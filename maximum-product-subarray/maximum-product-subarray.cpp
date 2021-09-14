class Solution {
public:
   int maxProduct(vector<int> &n)
    {
        int res = n[0];
        int l = n.size();
        for (int i = 1, imax = res, imin = res; i < l; i++)
        {
            int maxTemp = imax;
            imax = max(n[i], max(imax * n[i], imin * n[i]));
            imin = min(n[i], min(maxTemp * n[i], imin * n[i]));

            res = max(res, imax);
        }
        return res;
    }
};