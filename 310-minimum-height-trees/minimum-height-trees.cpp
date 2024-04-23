#include <iostream>
#include <vector>
#include <list>
#include <queue>

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // Base case: If there is only one node, return it as the root of the minimum height tree.
        if (n == 1) return {0};
    
        // Initialize adjacency list to represent the graph and degree array to store degrees of nodes.
        std::vector<std::list<int>> adjacency_list(n); // Graph represented using adjacency list
        std::vector<int> degree(n, 0); // Array to store degree of each node
        
        // Populate adjacency list and degree array based on input edges.
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adjacency_list[u].push_back(v);
            adjacency_list[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }
        
        // Queue to store leaf nodes initially
        std::queue<int> leaves;
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 1) leaves.push(i); // If node has degree 1, it's a leaf node
        }
        
        int remainingNodes = n; // Counter to keep track of remaining nodes in the graph
        
        // Prune the graph until only one or two nodes are left
        while (remainingNodes > 2) {
            int leavesCount = leaves.size(); // Number of leaf nodes at current level
            remainingNodes -= leavesCount; // Update remaining nodes
            for (int i = 0; i < leavesCount; ++i) {
                int leaf = leaves.front(); // Get the current leaf node
                leaves.pop(); // Remove it from the queue
                for (int neighbor : adjacency_list[leaf]) {
                    if (--degree[neighbor] == 1) {
                        leaves.push(neighbor); // If the neighbor becomes a leaf node, add it to the queue
                    }
                }
            }
        }
        
        // The remaining nodes in 'leaves' are the roots of minimum height trees
        std::vector<int> result;
        while (!leaves.empty()) {
            result.push_back(leaves.front());
            leaves.pop();
        }
        
        return result; // Return roots of minimum height trees
    }
};
