class Solution
{
public:
    string reverseWords(string s)
    {
        string res = "";
        string curr = "";

        for (auto i : s)
        {
            if (i == ' ')
            {
                if (curr != "")
                    res = curr + (res == "" ? "" : " ") + res;
                curr = "";
            }
            else
                curr += i;
        }
        if (curr != "")
            res = curr + (res == "" ? "" : " ") + res;
        return res;
    }
};