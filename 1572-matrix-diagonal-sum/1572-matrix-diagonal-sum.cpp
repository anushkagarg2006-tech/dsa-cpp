class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum=0;
        for(int i=0;i<mat.size();i++){
            sum+=mat[i][i];
        }for(int i=mat.size()-1, j=0; i>=0 && j<mat.size(); i--,j++){
        if(mat.size()%2!=0&&i==mat.size()/2&&j==mat.size()/2) continue;
        sum +=mat[i][j];}return sum;
    }
};