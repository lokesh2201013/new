class Solution {
public:
    bool canAliceWin(vector<int>& n) {
        int a=0,b=0;
        for(int i=0 ; i<n.size();i++)
        {
            if(n[i]<=9)a+=n[i];
            else b+=n[i];
        }
        return a==b?false:true;
    }
};