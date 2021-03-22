class Solution {
public:
    string defangIPaddr(string a) {
        string j="[.]";
        for(int i=0;i<a.size();i++)
        {
            if(a[i]=='.')
            {
                a.replace(i,1,j);
                i+=2;
            }
        }
        return a;
    }
};