class Solution {
public:
    int countPartitions(vector<int>& n) {
        int s=accumulate(n.begin(),n.end(),0);
        int c=0;
        int co=0;
         for(int i=0 ; i<n.size()-1;i++)
         {
           co+=2*n[i];
           if((s-co)%2==0)c++;
         }
         return c;
    }
};