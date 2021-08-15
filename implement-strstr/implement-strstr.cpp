class Solution
{
public:
    const int D = 26;
    const int M = 1e5 + 7;
    int strStr(string h, string n)
    {
        if(n.size()==0)
            return 0;
        if(h.size()==0||h.size()<n.size())
            return -1;
        int N = 0;
        int H = 0;
        int X = 1;

        for (int i = 0; i < n.size() - 1; i++)
            X = (X * D) % M;

        for (int i = 0; i < n.size(); i++)
        {
            N = (D * N + n[i] - 'a') % M;
            H = (D * H + h[i] - 'a') % M;
        }

        for (int i = 0; i <= h.size() - n.size(); i++)
        {

            if (N == H)
            {
                int j;
                for (j = 0; j < n.size(); j++)
                {
                    if (h[i + j] != n[j])
                        break;
                }

                if (j == n.size())
                    return i;
            }

            if (i < h.size() - n.size())
            {
                H = (D * (H - (h[i] - 'a') * X) + h[i + n.size()] - 'a') % M;

                if (H < 0)
                    H = (H + M);
            }
        }
        return -1;
    }
};