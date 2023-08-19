from os import system
from random import randint

n = 5000
t = 1

for i in range(t):
    with open("test.in", "w+") as f:
        res = f"{n}\n"
        for j in range(n):
            for k in range(n):
                res += f"{randint(0, 1)}{'' if k == n - 1 else ' '}"
            res += "\n"
        f.write(res)
    
    system(f'pypy3 main.py <"test.in" >"o1.out"')
    system(f'./main_solution <"test.in" >"o2.out"')
    system('diff o1.out o2.out')