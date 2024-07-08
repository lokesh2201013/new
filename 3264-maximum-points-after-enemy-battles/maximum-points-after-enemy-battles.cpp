class Solution {
public:
    long long maximumPoints(vector<int>& e, int c) {
        sort(e.begin(),e.end());
        unsigned long long p=0;
        if(e[0]>c) return 0;
        unsigned long long a=accumulate(e.begin(),e.end(),0ULL);
        a-=e[0];
        a+=c;
        p=a/e[0];
        return p;
    }
};