class Solution
{
public:
    bool recurr(vector<int> &m, int i, vector<int> sides, int possibleSide)
    {
        if (i == m.size())
            if ((sides[0] == sides[1]) && (sides[1] == sides[2]) && (sides[2] == sides[3]))
                return true;

        for (int j = 0; j < 4; j++)
        {
            bool check = false;
            int k = j - 1;
            while (k >= 0)
            {
                if (sides[k] == sides[j])
                {
                    check = true;
                    break;
                }
                k--;
            }
            if (!check && sides[j] + m[i] <= possibleSide)
            {
                sides[j] += m[i];
                if (recurr(m, i + 1, sides, possibleSide))
                    return true;
                sides[j] -= m[i];
            }
        }
        return false;
    }
    bool makesquare(vector<int> &m)
    {
        sort(m.begin(), m.end(), greater<int>());
        int sum = accumulate(m.begin(), m.end(), 0);
        if (sum % 4 == 0)
        {
            vector<int> sides(4, 0);
            return recurr(m, 0, sides, sum / 4);
        }
        return false;
    }
};