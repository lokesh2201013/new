class Solution {
public:
    int heightChecker(vector<int>& h) {
        vector<int>n=h;
        sort(n.begin(),n.end());
        int c=0;
        for(int i=0 ; i<h.size();i++)
        {
         if(n[i]!=h[i])
         {
            c++;
         }
        }
       return c;      
    }
};