class Solution {
public:
    int duplicateNumbersXOR(vector<int>& n) {
        map<int,int> m;
        for(int i:n)
        {
            m[i]++;
        }
        vector<int> ne;
        int a=0;
        for(const auto& i:m)
        {
          if(i.second==2)
          {
            a^=i.first;
          }
        }
        return a;
    }
};