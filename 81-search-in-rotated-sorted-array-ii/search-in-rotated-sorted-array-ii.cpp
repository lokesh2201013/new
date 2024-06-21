class Solution {
public:
    int search(vector<int>& n, int t) {
        int l=0,r=n.size()-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            
            if(n[mid]==t||n[l]==t||n[r]==t)return true;
            if(n[l]==n[mid]&&n[mid]==n[r])
            {
                l++;r--;continue;
            }
            if(n[l]<=n[mid])
            {
                if(n[l]<=t&&t<=n[mid])r=mid-1;
                else l=mid+1;
            }
            else
            {
                if(n[mid]<=t&&t<=n[r])l=mid+1;
                else r=mid-1;
            }
        }
        return false;
    }
};