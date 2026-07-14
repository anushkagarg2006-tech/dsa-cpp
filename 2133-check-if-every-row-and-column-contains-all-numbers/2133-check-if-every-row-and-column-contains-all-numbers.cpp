class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        for(int i = 0; i < n; i++){          // diagonal traverse
            unordered_set<int> rowSet, colSet;
            
            for(int j = 0; j < n; j++){
                // Row i check
                if(rowSet.count(matrix[i][j])) return false;
                rowSet.insert(matrix[i][j]);
                
                // Column i check
                if(colSet.count(matrix[j][i])) return false;
                colSet.insert(matrix[j][i]);
            }
        }
        return true;
    }
};