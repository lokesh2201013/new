class Solution {
public:
    int maxAdjacentDistance(vector<int>& n) {
        int s=0;
        for(int i=0 ; i<n.size()-1;i++){
            s=max(s,abs(n[i]-n[i+1]));
        }
        if(n.size()>=3){
            int ps=abs(n[n.size()-1]-n[0]);
            if(ps>s)return ps;

        }
        return s;
    }
};