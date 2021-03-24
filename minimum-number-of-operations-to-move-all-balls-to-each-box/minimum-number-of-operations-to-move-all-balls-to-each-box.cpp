class Solution {
public:
    vector<int> minOperations(string ar) {
        int i,n=ar.size(),rh=0,sm=0,jm;
        vector<int> ans;
        for(i=0;i<n;i++){
            sm+=rh;
            ans.push_back(sm);
            if(ar[i]=='1') rh++;
        }
        rh=sm=0;
        if(ar[n-1]=='1') rh++;
        for(i=n-2;i>=0;i--){
            sm+=rh;
            ans[i]=sm+ans[i];
            if(ar[i]=='1') rh++; 
        }
        return ans;
    }
};