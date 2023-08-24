def is_grass(N, x, y):
    X = 4 * N
    Y = 3 * N

    if(x > (X / 2)): x = X - x - 1
    if(y > (Y / 2)): y = Y - y - 1
    return (x + y < N) or (x >= N and y >= N)

Q = int(input())

for _ in range(Q):
    N, x, y = map(int, input().split(" "))

    print("-" if is_grass(N, x, y) else "#")