class Solution
{
public:
    void recurr(vector<vector<int>> &image, vector<vector<bool>> &set, int sr, int sc, int color)
    {

        int n = image.size();
        int m = image[0].size();

        int temp = image[sr][sc];
        set[sr][sc] = true;
        image[sr][sc] = color;
        if (sr - 1 >= 0 && !set[sr - 1][sc] && temp == image[sr - 1][sc])
            recurr(image, set, sr - 1, sc, color);
        if (sr + 1 < n && !set[sr + 1][sc] && temp == image[sr + 1][sc])
            recurr(image, set, sr + 1, sc, color);
        if (sc - 1 >= 0 && !set[sr][sc - 1] && temp == image[sr][sc - 1])
            recurr(image, set, sr, sc - 1, color);
        if (sc + 1 < m && !set[sr][sc + 1] && temp == image[sr][sc + 1])
            recurr(image, set, sr, sc + 1, color);
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        vector<vector<bool>> set(image.size(), vector<bool>(image[0].size(), false));
        recurr(image, set, sr, sc, color);
        return image;
    }
};
