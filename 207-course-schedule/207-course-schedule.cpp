class Solution
{
public:
    bool dfs(vector<vector<int>> &p, vector<int> &vis, vector<bool> &dfsvis, int curr)
    {
        if (vis[curr] != -1)
            return vis[curr];
        dfsvis[curr] = true;
        if (p[curr].size() == 0)
        {
            dfsvis[curr] = false;
            return vis[curr] = false;
        }

        for (int i = 0; i < p[curr].size(); i++)
            if (dfsvis[p[curr][i]] || dfs(p, vis, dfsvis, p[curr][i]))
                return vis[curr] = true;

        dfsvis[curr] = false;
        return vis[curr] = false;
    }
    bool canFinish(int v, vector<vector<int>> &p)
    {
        vector<vector<int>> graph(v, vector<int>());
        for (int i = 0; i < p.size(); i++)
            graph[p[i][0]].push_back(p[i][1]);

        vector<int> vis(v, -1);
        vector<bool> dfsvis(v, false);
        for (int i = 0; i < v; i++)
            if (vis[i] == -1)
                if (dfs(graph, vis, dfsvis, i))
                    return false;
        return true;
    }
};