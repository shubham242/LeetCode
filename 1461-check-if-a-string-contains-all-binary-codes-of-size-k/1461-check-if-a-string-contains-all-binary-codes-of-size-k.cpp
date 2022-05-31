class Solution
{
public:
    bool hasAllCodes(string s, int k)
    {
        int res = 0;
        int l1 = (int)pow(2, k);
        int arr[l1];
        for (int i = 0; i < l1; i++)
            arr[i] = 0;
        int l2 = s.size();
        for (int i = 0; i <= l2 - k; i++)
        {
            int x = stoi(s.substr(i, k), 0, 2);
            if (!arr[x])
            {
                arr[x] = 1;
                res++;
            }
        }
        return l1 == res;
    }
};