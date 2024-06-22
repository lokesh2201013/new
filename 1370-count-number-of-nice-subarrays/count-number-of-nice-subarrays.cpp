class Solution {
public:
    int numberOfSubarrays(vector<int>& n, int k) {
        for(int i=0 ; i<n.size();i++)
        {
            n[i]%=2;
        }
        int s=0,a=0;
        vector<int>cnt(n.size()+1,0);
        cnt[0]=1;
        for(int i:n)
        {
            s+=i;
            a+=(s>=k)?cnt[s-k]:0;
            cnt[s]++;
        }
        return a;
    }
};