class Solution
{
public:
    int kadane(vector<int> &a)
    {
        int max_so_far = 0, max_ending_here = 0;
        int i;
        for (i = 0; i < a.size(); i++)
        {
            max_ending_here = max_ending_here + a[i];

            if (max_so_far < max_ending_here)
                max_so_far = max_ending_here;
            if (max_ending_here < 0)
                max_ending_here = 0;
        }
        return max_so_far;
    }
    int maxSubarraySumCircular(vector<int> &a)
    {
        int max_kadane = kadane(a);
        if (max_kadane == 0)
            return *max_element(a.begin(), a.end());
        int max_wrap = 0, i;
        for (i = 0; i < a.size(); i++)
        {
            max_wrap += a[i];
            a[i] = -a[i];
        }

        max_wrap = max_wrap + kadane(a);

        return (max_wrap > max_kadane) ? max_wrap : max_kadane;
    }
};
