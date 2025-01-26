class Solution {
public:
    long long minCost(vector<int>& a, vector<int>& b, long long k) {
        long long r0=0,r1=0;
        for(int i=0 ; i<a.size();i++){
            r0+=abs(a[i]-b[i]);
        }
          sort(a.begin(),a.end());
          sort(b.begin(),b.end());
        for(int i=0 ; i<a.size();i++){
            r1+=abs(a[i]-b[i]);
        }

        return min(r0,r1+k);
    }
};