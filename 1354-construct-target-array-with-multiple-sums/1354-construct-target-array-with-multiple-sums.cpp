class Solution
{
public:
    bool isPossible(vector<int> &t)
    {
        long sum = 0;
        priority_queue<int> q;

        for (auto i : t)
        {
            sum += i;
            q.push(i);
        }

        while (q.top() != 1)
        {
            int num = q.top();
            q.pop();
            sum -= num;
            if (num <= sum || sum <= 0)
                return false;

            num = num % sum;
            sum += num;
            q.push(num ? num : sum);
        }
        return true;
    }
};