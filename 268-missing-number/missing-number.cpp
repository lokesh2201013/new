class Solution {
public:
    int missingNumber(vector<int>& n) {
        int cs=0,as=accumulate(n.begin(),n.end(),0);
        int i=0;
        int m=*max_element(n.begin(),n.end());
        if(m==n.size()+1)return 0;
        if(m==n.size()-1)return m+1;
        for( i=0 ; i<=m;i++){
            cs+=i;
        }
        return  cs-as;
    }
};