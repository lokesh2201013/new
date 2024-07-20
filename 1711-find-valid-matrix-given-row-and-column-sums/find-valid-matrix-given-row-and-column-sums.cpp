class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& r, vector<int>& c) {
       int n=r.size(),m=c.size();
        vector<vector<int>>a(n,vector<int>(m,0));
       for(int i=0 ; i<n ; i++)
       {
        for(int j=0 ;j<m; j++)
        {
            a[i][j]=min(r[i],c[j]);
            r[i]-=a[i][j];
            c[j]-=a[i][j];        }
       }
       return a;
    }
};