class Solution {
public:
    int numberOfPairs(vector<int>& n1, vector<int>& n2, int k) {
        int a=0;
        for(int i=0 ; i<n1.size();i++)
        {
            for(int j=0 ; j<n2.size();j++)
            {
             if(n1[i]%(n2[j]*k)==0)
             {
                a++;
             }
            }
        }
        return a;
    }
};