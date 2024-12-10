class Solution {
public:
 int give(int a,int j,int m,vector<int>& n){
    j+=a;
    if(j<0){
        if(abs(j)>m){
            j%=m;
        }
        j+=m;
    }
    j%=m;
    return n[j];
 }
    vector<int> constructTransformedArray(vector<int>& n) {
        vector<int> r;
        for(int i=0 ; i<n.size();i++){
            r.push_back(give(n[i],i,n.size(),n));
        }
        return r;
    }
};