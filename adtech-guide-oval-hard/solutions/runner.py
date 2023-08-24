from os import system

N = 15
res = [f"{2 * N * (N + 1) * (2 * N + 1)}"]
with open("test.in", "w+") as f:
    for i in range(1, N + 1):
        for x in range(4 * i):
            for y in range(3 * i):
                res.append(f"{i} {x} {y}")

    f.write("\n".join(res))
                
            
system(f'./cpp1_ac <"test.in" >"o1.out"')
system(f'pypy py1_tle.py <"test.in" >"o2.out"')
system('diff o1.out o2.out')