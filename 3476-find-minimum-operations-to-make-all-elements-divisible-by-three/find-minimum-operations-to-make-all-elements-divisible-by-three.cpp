class Solution {
public:
    int minimumOperations(vector<int>& n) {
        for(int i=0 ; i<n.size();i++)
        {
            n[i]%=3;
        }
        int c=0;
        for(int i=0;i<n.size();i++)
        {
            if(n[i]!=0)
            {
                c++;
            }
        }
        return c;
    }
};