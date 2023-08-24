def solve(N, xt, yt):
    for y in range(N):
        for x in range(N - y):
            if(xt == x and yt == y): return "-"
        for x in range(N - y, 3 * N + y):
            if(xt == x and yt == y): return "#"
        for x in range(3 * N + y, 4 * N):
            if(xt == x and yt == y): return "-"

    for y in range(N, 2 * N):
        for x in range(N):
            if(xt == x and yt == y): return "#"
        for x in range(N, 3 * N):
            if(xt == x and yt == y): return "-"
        for x in range(3 * N, 4 * N):
            if(xt == x and yt == y): return "#"

    for y in range(2 * N, 3 * N):
        for x in range((y - 2 * N) + 1):
            if(xt == x and yt == y): return "-"
        for x in range((y - 2 * N) + 1, 4 * N - ((y - 2 * N) + 1)):
            if(xt == x and yt == y): return "#"
        for x in range(4 * N - ((y - 2 * N) + 1), 4 * N):
            if(xt == x and yt == y): return "-"

Q = int(input())

for _ in range(Q):
    N, x, y = map(int, input().split(" "))

    print(solve(N, x, y))