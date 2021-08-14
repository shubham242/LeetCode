static const auto fast = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
class Solution
{
public:
    bool isValid(string a)
    {

        stack<char> s;
        for (int i = 0; i < a.size(); i++)
        {
            if (!s.empty())
            {
                if (s.top() == '(' && a[i] == ')')
                    s.pop();
                else if (s.top() == '[' && a[i] == ']')
                    s.pop();
                else if (s.top() == '{' && a[i] == '}')
                    s.pop();
                else
                    s.push(a[i]);
            }
            else
                s.push(a[i]);
        }

        if (s.empty())
            return true;
        else
            return false;
    }
};