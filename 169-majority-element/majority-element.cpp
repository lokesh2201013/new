class Solution {
public:
    int majorityElement(vector<int>& n) {
        map<int,int> m;
        for(int i:n)
        {
            m[i]++;
        }
        for(auto i : m)
        {
            if(i.second>n.size()/2)
            {
                return i.first ;
            }
        }
        return -1;
    }
};