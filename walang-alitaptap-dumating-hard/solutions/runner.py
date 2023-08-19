from os import system

n = 3

for i in range(1 << (n * n)):
    with open("test.in", "w+") as f:
        res = f"{n}\n"
        for j in range(n):
            for k in range(n):
                res += f"{(i >> (k + (j << 2))) & 0b1}{'' if k == n - 1 else ' '}"
            res += "\n"
        f.write(res)
    
    system(f'pypy3 brute_forcer.py <"test.in" >"o1.out"')
    system(f'./main_solution <"test.in" >"o2.out"')
    system('diff o1.out o2.out')