class Solution
{
public:
    int myAtoi(string s)
    {
        if(s.size()==0)
            return 0;
    long long int res = 0;
    int indicator = 1;

    int i = s.find_first_not_of(' ');
        if(i>=s.size())
            return 0;
    if(s[i] == '-' || s[i] == '+')
        indicator = (s[i++] == '-')? -1 : 1;
        
    while('0'<= s[i] && s[i] <= '9') 
    {
        res = res*10 + (s[i++]-'0');
        if(res*indicator >= INT_MAX) return INT_MAX;
        if(res*indicator <= INT_MIN) return INT_MIN;                
    }
        
    return res*indicator;
    }
};