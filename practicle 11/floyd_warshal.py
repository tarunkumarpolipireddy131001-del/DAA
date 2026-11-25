n = int(input("Enter number of vertices: "))
graph = []

for i in range(n):
    row = list(map(int, input().split()))
    graph.append(row)

for k in range(n):
    for i in range(n):
        for j in range(n):
            graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j])

print("Shortest distance matrix:")
for row in graph:
    print(*row)
