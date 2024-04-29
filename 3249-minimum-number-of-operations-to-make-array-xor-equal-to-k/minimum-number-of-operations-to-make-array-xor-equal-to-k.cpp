class Solution {
public:
    int minOperations(vector<int>& n, int k) {
        for(int a:n)
        {
            k^=a;
        }
        return __builtin_popcount(k);
    }
};