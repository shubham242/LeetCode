class KthLargest
{
public:
    priority_queue<long> q;
    int K;
    KthLargest(int k, vector<int> &nums)
    {
        K = k;
        int l = nums.size();
        for (int i = 0; i < l; i++)
            q.push(-nums[i]);
        while (q.size() > k)
            q.pop();
    }

    int add(int val)
    {
        q.push(-val);
        while (q.size() > K)
            q.pop();
        return -q.top();
    }
};