'''
Given a set of cities and the distance between every pair of cities as an adjacency matrix,
the problem is to find the shortest possible route that visits every city exactly once
and returns to the starting point
'''
'''
brute force approach:
- city 1 is starting and ending point
- generate the (n-1)! permutations of citites
- calculate the cost of each permutation and keep track of
  minimum cost permutation
- return the permutation in minimum cost
'''
import numpy as np
import itertools

cities = ["A", "B", "C", "D"]
distances = np.array([
    [ 0, 10, 15, 20],
    [10,  0, 35, 25],
    [15, 35,  0, 30],
    [20, 25, 30,  0]
])

def cost_distance(path):
    cost=0
    for i in range(len(path)-1):
        cost+=distances[path[i],path[i+1]]
    return cost

# path = [0,1,3,2]
# costs = cost_distance(path)
# print(distances)
# print("The cost of path:",costs)

shortest_distance = float("inf")
shortes_path = None

for path in itertools.permutations(range(len(cities))):
    distance = cost_distance(path)
    if distance < shortest_distance:
        shortest_distance = distance
        shortest_path = path

shortest_path = [cities[i] for i in shortest_path]

print("Shortest Path:", shortest_path)
print("Shortest Distance:", shortest_distance)
