class Solution:
  def longestCycle(self, edges: List[int]) -> int:
    ans = -1  # Initialize the answer to -1
    time = 1  # Initialize the current time step to 1
    timeVisited = [0] * len(edges)  # Initialize a list to store the time at which each node was first visited

    # Iterate through each node in the graph
    for i, edge in enumerate(edges):
      if timeVisited[i]:  # If the node has already been visited, skip it
        continue
      startTime = time  # Record the start time of the current traversal
      u = i  # Initialize the current node to the ith node
      # Traverse the graph until the end of the path is reached or a visited node is encountered
      while u != -1 and not timeVisited[u]:
        timeVisited[u] = time  # Record the current time step
        time += 1  # Increment time
        u = edges[u]  # Move to the next node in the path
      # If a cycle is found that includes the current node, update the answer
      if u != -1 and timeVisited[u] >= startTime:
        ans = max(ans, time - timeVisited[u])

    return ans  # Return the length of the longest cycle found