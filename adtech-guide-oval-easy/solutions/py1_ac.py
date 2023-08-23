def is_grass(N, x, y):
    X = 4 * N
    Y = 3 * N

    if(x > (X / 2)): x = X - x - 1
    if(y > (Y / 2)): y = Y - y - 1
    return (x + y < N) or (x >= N and y >= N)

N = int(input())
X = 4 * N
Y = 3 * N

print("\n".join(map(lambda y: "".join(map(lambda x: "-" if is_grass(N, x, y) else "#", range(X))), range(Y))))