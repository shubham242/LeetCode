class Solution
{
public:
    long hash[51][51][51];
    int M = 1e9 + 7;
    long solve(int m, int n, int maxMove, int startRow, int startColumn)
    {
        if (maxMove >= 0 && (startRow < 0 || startRow >= m || startColumn < 0 || startColumn >= n))
            return 1;
        if (maxMove < 0)
            return 0;
        if (hash[startRow][startColumn][maxMove] != -1)
            return hash[startRow][startColumn][maxMove] % M;
        return hash[startRow][startColumn][maxMove] =
                   solve(m, n, maxMove - 1, startRow - 1, startColumn) % M +
                   solve(m, n, maxMove - 1, startRow + 1, startColumn) % M +
                   solve(m, n, maxMove - 1, startRow, startColumn - 1) % M +
                   solve(m, n, maxMove - 1, startRow, startColumn + 1) % M;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        memset(hash, -1, sizeof(hash));
        return solve(m, n, maxMove, startRow, startColumn) % M;
    }
};