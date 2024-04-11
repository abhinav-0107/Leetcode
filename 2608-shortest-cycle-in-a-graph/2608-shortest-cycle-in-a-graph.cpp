class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
          // Create an adjacency list for the graph
        std::vector<std::vector<int>> graph(n);
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        // Initialize the shortest cycle length to the maximum possible value
        int shortestCycle = INT_MAX;

        // Perform BFS from each vertex to find the shortest cycle
        for (int i = 0; i < n; ++i) {
            // Distance from starting node, initialized to -1 (unvisited)
            std::vector<int> distance(n, -1);
            // Parent of each node in BFS tree, initialized to -1 (no parent)
            std::vector<int> parent(n, -1);
            // Queue for BFS traversal
            std::queue<int> q;

            // Initialize BFS from vertex i
            q.push(i);
            distance[i] = 0;

            // BFS loop
            while (!q.empty()) {
                int current = q.front();
                q.pop();

                // Visit all adjacent vertices
                for (int adj : graph[current]) {
                    // If an adjacent is not visited, enqueue it and update distance and parent
                    if (distance[adj] == -1) {
                        q.push(adj);
                        distance[adj] = distance[current] + 1;
                        parent[adj] = current;
                    }
                    // If an adjacent is visited and is not parent of current, cycle is found
                    else if (parent[current] != adj) {
                        // Update the shortest cycle length if a shorter cycle is found
                        shortestCycle = std::min(shortestCycle, distance[current] + distance[adj] + 1);
                    }
                }
            }
        }

        // If no cycle was found, return -1, otherwise return the shortest cycle length
        return shortestCycle == INT_MAX ? -1 : shortestCycle;
    }
};