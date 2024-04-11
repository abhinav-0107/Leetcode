function findShortestCycle(n: number, edges: number[][]): number {
    const graph: number[][] = Array.from({ length: n }, () => []);

        for (const edge of edges) {
            graph[edge[0]].push(edge[1]);
            graph[edge[1]].push(edge[0]);
        }

        // Initialize the shortest cycle length to the maximum possible value
        let shortestCycle: number = Infinity;

        // Perform BFS from each vertex to find the shortest cycle
        for (let i = 0; i < n; ++i) {
            // Distance from starting node, initialized to -1 (unvisited)
            const distance: number[] = Array(n).fill(-1);
            // Parent of each node in BFS tree, initialized to -1 (no parent)
            const parent: number[] = Array(n).fill(-1);
            // Queue for BFS traversal
            const q: number[] = [];

            // Initialize BFS from vertex i
            q.push(i);
            distance[i] = 0;

            // BFS loop
            while (q.length > 0) {
                const current = q.shift()!;

                // Visit all adjacent vertices
                for (const adj of graph[current]) {
                    // If an adjacent is not visited, enqueue it and update distance and parent
                    if (distance[adj] === -1) {
                        q.push(adj);
                        distance[adj] = distance[current] + 1;
                        parent[adj] = current;
                    }
                    // If an adjacent is visited and is not parent of current, cycle is found
                    else if (parent[current] !== adj) {
                        // Update the shortest cycle length if a shorter cycle is found
                        shortestCycle = Math.min(shortestCycle, distance[current] + distance[adj] + 1);
                    }
                }
            }
        }

        // If no cycle was found, return -1, otherwise return the shortest cycle length
        return shortestCycle === Infinity ? -1 : shortestCycle;
};