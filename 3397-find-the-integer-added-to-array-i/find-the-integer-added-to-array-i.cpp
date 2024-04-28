class Solution {
public:
    int addedInteger(vector<int>& n1, vector<int>& n2) {
        sort(n1.begin(),n1.end());
        sort(n2.begin(),n2.end());
        int m1=n1[0];
        int m2=n2[0];
        int a=m2-m1;
        return a;
    }
};