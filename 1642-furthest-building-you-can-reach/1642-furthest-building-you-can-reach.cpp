class Solution
{
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        int n = heights.size();
        long sum = 0;
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
                        sum += q.top();
                        q.pop();
                        q.push(diff);
                    }
                    else
                        sum += diff;
                }
            }
            if (sum <= bricks)
                maxCount = max(maxCount, i);
        }
        return maxCount;
    }
};