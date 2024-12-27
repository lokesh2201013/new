class Solution {
public:
    vector<int> rearrangeArray(vector<int>& n) {
     vector<int>a(n.size(),0);
     int p=0,ne=1;
     for(int i=0 ; i<n.size();i++){
       if(n[i]>=0){
        a[p]=n[i];
        p+=2;
       }else{
        a[ne]=n[i];
        ne+=2;
       }
     }
     return a;
     }   
};