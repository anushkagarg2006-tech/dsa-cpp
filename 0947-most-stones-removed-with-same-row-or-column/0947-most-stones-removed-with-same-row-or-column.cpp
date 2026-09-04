class Solution {
public:
    unordered_map<int, int> parent;
    unordered_map<int, int> rank_;
    
    void makeSet(int node) {
        if (parent.find(node) == parent.end()) {
            parent[node] = node;
            rank_[node] = 0;
        }
    }
    
    int findParent(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findParent(parent[node]); // path compression
    }
    
    void unionSet(int u, int v) {
        int parU = findParent(u);
        int parV = findParent(v);
        
        if (parU == parV) return;
        
        // union by rank
        if (rank_[parU] < rank_[parV]) {
            parent[parU] = parV;
        } else if (rank_[parV] < rank_[parU]) {
            parent[parV] = parU;
        } else {
            parent[parV] = parU;
            rank_[parU]++;
        }
    }
    
    int removeStones(vector<vector<int>>& stones) {
        for (auto& s : stones) {
            int row = s[0];
            int col = s[1] + 10001; // column ko row se differentiate karne ke liye offset diya
            
            makeSet(row);
            makeSet(col);
            unionSet(row, col);
        }
        
        unordered_set<int> uniqueRoots;
        for (auto& s : stones) {
            int row = s[0];
            uniqueRoots.insert(findParent(row));
        }
        
        int components = uniqueRoots.size();
        return stones.size() - components;
    }
};