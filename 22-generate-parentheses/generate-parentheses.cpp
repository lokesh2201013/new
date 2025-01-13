class Solution {
public:
void give(string a,int o,int c,vector<string>&an,int n){
    if(a.length()==n*2){
        an.push_back(a);
        return ;
    }
    if(o<n)give(a+'(',o+1,c,an,n);
      if(c<o)give(a+')',o,c+1,an,n);
}
    vector<string> generateParenthesis(int n) {
        string a="";
        vector<string>an;
        give(a,0,0,an,n);
      return an;
    }
};