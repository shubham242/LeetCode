class Solution
{
public:
    bool hasAllCodes(string s, int k)
    {
        int l1 = (int)pow(2, k);
        int arr[l1];
        for (int i = 0; i < l1; i++)
            arr[i] = 0;
        int l2 = s.size();
        for (int i = 0; i <= l2 - k; i++)
        {
            int x = stoi(s.substr(i, k), 0, 2);
            arr[x] = 1;
        }
        for (int i = 0; i < l1; i++)
            if (!arr[i])
                return false;
        return true;
    }
};
