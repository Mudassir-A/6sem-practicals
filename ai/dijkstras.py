import heapq


def dijkstra(V, adj, S):
    dist = [int(1e9)] * V
    dist[S] = 0
    min_heap = [(0, S)]

    while min_heap:
        dis, node = heapq.heappop(min_heap)

        for neighbor in adj[node]:
            adjNode, edgeW = neighbor[0], neighbor[1]
            if dis + edgeW < dist[adjNode]:
                dist[adjNode] = dis + edgeW
                heapq.heappush(min_heap, (dist[adjNode], adjNode))
    return dist


if __name__ == "__main__":
    V, E, S = map(int, input("Enter number of vertices, edges, and source: ").split())
    adj = [[] for _ in range(V)]

    print(f"Enter {E} edges in the format: u v w")
    for _ in range(E):
        u, v, w = map(int, input().split())
        adj[u].append([v, w])
        adj[v].append([u, w])  # remove this line for directed graph

    res = dijkstra(V, adj, S)
    print("Shortest distances from source:")
    print(" ".join(map(str, res)))
