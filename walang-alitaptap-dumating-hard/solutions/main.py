n = int(input())

grid = []

for i in range(n):
    grid.append(list(map(lambda x: bool(int(x)), input().split(" "))))

for i in range(n):
    for j in range(n):
        if((i + j) & 0b1):
            grid[i][j] = not grid[i][j]

def def_access(g, i, j, dv):
    return dv if(i < 0 or i >= len(g) or j < 0 or j >= len(g[0])) else g[i][j]

largest_square = list(map(lambda _1: list(map(lambda _2: 0, range(n))), range(n)))
def get_max_square(g, flip):
    global largest_square

    ans = 0
    for i in range(n):
        for j in range(n):
            largest_square[i][j] = 0 if(g[i][j] != flip) else (min(def_access(largest_square, i - 1, j, 0), def_access(largest_square, i, j - 1, 0), def_access(largest_square, i - 1, j - 1, 0)) + 1)
            ans = max(ans, largest_square[i][j])
    return ans

print(max(get_max_square(grid, False), get_max_square(grid, True)))