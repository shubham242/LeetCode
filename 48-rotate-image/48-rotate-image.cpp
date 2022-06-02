class Solution
{
public:
    void rotate(vector<vector<int>> &m)
    {
        int l = m.size();
        for (int i = 0; i < l / 2; i++)
        {
            for (int j = i; j < l - i - 1; j++)
            {
                int t = m[i][j];
                m[i][j] = m[l - 1 - j][i];
                m[l - 1 - j][i] = m[l - 1 - i][l - 1 - j];
                m[l - 1 - i][l - 1 - j] = m[j][l - 1 - i];
                m[j][l - 1 - i] = t;
            }
        }
    }
};