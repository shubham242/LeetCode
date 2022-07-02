class Solution
{
public:
    int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts)
    {
        int M = 10e8 + 7;
        int a = horizontalCuts.size();
        int b = verticalCuts.size();
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int maxh = horizontalCuts[0], maxv = verticalCuts[0];
        for (int i = 0; i < a - 1; i++)
            maxh = max(maxh, horizontalCuts[i + 1] - horizontalCuts[i]);
        maxh = max(maxh, h - horizontalCuts[a - 1]);
        for (int i = 0; i < b - 1; i++)
            maxv = max(maxv, verticalCuts[i + 1] - verticalCuts[i]);
        maxv = max(maxv, w - verticalCuts[b - 1]);

        return ((long)(maxh % M) * (long)(maxv % M)) % M;
    }
};