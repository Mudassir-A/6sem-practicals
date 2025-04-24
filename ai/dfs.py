def dfsOfGraph(V, adj):
    def dfs(node):
        if vis[node]:
            return
        vis[node] = True
        res.append(node)
        for neighbour in adj[node]:
            if not vis[neighbour]:
                dfs(neighbour)

    vis = [False] * V
    res = []
    for i in range(V):
        if not vis[i]:
            dfs(i)
    return res


if __name__ == "__main__":
    tc = int(input())
    for _ in range(tc):
        V, E = map(int, input().split())
        adj = [[] for _ in range(V)]
        for _ in range(E):
            u, v = map(int, input().split())
            adj[u].append(v)
            adj[v].append(u)

        ans = dfsOfGraph(V, adj)
        print(" ".join(map(str, ans)))
