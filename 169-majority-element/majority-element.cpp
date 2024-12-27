class Solution {
public:
    int majorityElement(vector<int>& n) {
        int c=0,e=n[0];
        for(int i=0 ; i<n.size();i++){
            if(e==n[i])c++;
            else if(e!=n[i]){
                if(c==0)e=n[i];
                else c--;
            }
        }
        return e;
    }
};