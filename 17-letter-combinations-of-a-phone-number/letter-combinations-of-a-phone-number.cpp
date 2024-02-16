class Solution {
public:
    void recur(string digits,int size,int index,vector<string> digitHash, string curr, vector<string>& res){
        if(index==size){
            if(curr!="")
                res.push_back(curr);
            return;
        }

        for(auto& ch : digitHash[digits[index]-'2'])
            recur(digits,size,index+1,digitHash,curr+ch,res);    
        return;
    }
    vector<string> letterCombinations(string digits) {
        vector<string> digitHash = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> res;
        recur(digits,digits.size(),0,digitHash ,"",res);

        return res;
    }
};