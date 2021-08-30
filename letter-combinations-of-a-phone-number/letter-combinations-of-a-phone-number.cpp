class Solution {
public:
    void compare(string str, int i, string n, vector<string> &num, vector<string> &apt){
        if(i==n.size()) {
            apt.push_back(str);
            return;
        }
        for(int j=0; j<num[n[i] - '2'].size(); j++){
            str.push_back(num[n[i] - '2'][j]);
            compare(str, i+1, n, num, apt);
            str.pop_back();
        }
    }
    vector<string> letterCombinations(string d) {
        vector<string> data;
        data.push_back("abc");
        data.push_back("def");
        data.push_back("ghi");
        data.push_back("jkl");
        data.push_back("mno");
        data.push_back("pqrs");
        data.push_back("tuv");
        data.push_back("wxyz");
        
        vector<string> res;
        
        if(d.size()==0)
            return res;
        
        compare("",0,d,data,res);
        return res;
    }
};