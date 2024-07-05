class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size();
        int c= matrix[0].size();
        int sr=0;
        int sc=c-1;
        while(sr<r&&sc>=0){
            int e= matrix[sr][sc];
            if(e==target){
                return 1 ;
            }
            if(e<target){
                sr++;
            }
            else{
                sc--;
            }
        }
        return 0;
    }
};