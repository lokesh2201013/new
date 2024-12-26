class Solution {
public:
    void moveZeroes(vector<int>& n) {
        int c=0;
        for(int i=0 ; i<n.size();i++){
            if(n[i]==0){
                n.erase(n.begin()+i);
                i--;
                c++;
            }
        }
        for(int i=0; i<c;i++){
            n.push_back(0);
        }
    }
};