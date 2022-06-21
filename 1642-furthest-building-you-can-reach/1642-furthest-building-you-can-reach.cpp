class Solution
{
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        int n = heights.size();
        priority_queue<int, vector<int>, greater<int>> q;
        int maxCount = 0;

        for (int i = 1; i < n; i++)
        {
            int diff = heights[i] - heights[i - 1];
            if (diff > 0)
            {
                if (q.size() < ladders)
                    q.push(diff);
                else
                {
                    if (ladders > 0 && diff > q.top())
                    {
                        bricks -= q.top();
                        q.pop();
                        q.push(diff);
                    }
                    else
                        bricks -= diff;
                }
            }
            if (bricks >= 0)
                maxCount = max(maxCount, i);
        }
        return maxCount;
    }
};