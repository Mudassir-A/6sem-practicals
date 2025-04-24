from collections import deque


def bfs(adj):
    V = len(adj)
    vis = [0] * V
    vis[0] = 1
    q = deque()
    q.append(0)
    bfs = []

    while q:
        node = q[0]
        q.popleft()
        bfs.append(node)

        for i in adj[node]:
            if not vis[i]:
                vis[i] = 1
                q.append(i)

    return bfs


if __name__ == "__main__":
    tc = int(input())
    for _ in range(tc):
        V, E = map(int, input().split())
        adj = [[] for _ in range(V)]
        for _ in range(E):
            u, v = map(int, input().split())
            adj[u].append(v)
            adj[v].append(u)

        ans = bfs(adj)
        print(" ".join(map(str, ans)))
