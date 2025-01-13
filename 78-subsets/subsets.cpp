class Solution {
public:
void give(int i,vector<vector<int>>&a,vector<int>&p,vector<int>&n){
    if(i==n.size()){
        a.push_back(p);
        return ;
    }
    p.push_back(n[i]);
    give(i+1,a,p,n);
    p.pop_back();
      give(i+1,a,p,n);
}
    vector<vector<int>> subsets(vector<int>& n) {
        vector<vector<int>>a;
        vector<int>p;
        give(0,a,p,n);
        return a;
    }
};