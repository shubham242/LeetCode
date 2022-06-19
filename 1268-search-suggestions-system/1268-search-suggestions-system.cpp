class Solution
{
public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
    {
        sort(products.begin(), products.end());
        vector<vector<string>> ans;
        for (int i = 1; i <= searchWord.size(); i++)
        {
            vector<string> temp;

            string s = searchWord.substr(0, i);
            for (int j = 0; j < products.size(); j++)
            {
                if (products[j].compare(0, s.size(), s) == 0)
                    temp.push_back(products[j]);

                if (temp.size() == 3)
                    break;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
