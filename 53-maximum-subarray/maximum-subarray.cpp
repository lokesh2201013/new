class Solution {
public:
    int maxSubArray(vector<int>& n) {
        int m=INT_MIN,s=0;
        for(int i=0 ; i<n.size();i++){
            s+=n[i];
            m=max(m,s);
            if(s<0)s=0;
        }
        return m;
    }
};