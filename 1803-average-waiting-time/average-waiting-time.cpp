class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& c) {
        long long tt=c[0][0]+c[0][1];
        vector<long long> s;
         s.push_back(tt-c[0][0]);
        for(int i=1 ; i<c.size();i++)
        {
            if(tt<c[i][0])tt=c[i][0];
            tt+=c[i][1];
            s.push_back(tt-c[i][0]);
        }
      double a = (double)accumulate(s.begin(), s.end(), 0ULL) / c.size();
        return a;
    }
};