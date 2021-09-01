// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long int s=1;
        long int e=n;
        long int ans=n;
        while(s<=e)
        {
            long long int mid=(s+e)/2;
            if(isBadVersion(mid))
            {
                e=mid-1;
                ans=mid;
            }
            else
                s=mid+1;
        }
        return ans;
    }
};