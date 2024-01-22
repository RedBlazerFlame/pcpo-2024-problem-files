from os import system

for i in range(1, 1000):
    for k in range(0, 5):
        with open("test.in", "w+") as f:
            res = f"{i} {k}\n"
            f.write(res)
        
        system(f'pypy ac_sol.py <"test.in" >"o1.out"')
        system(f'pypy tle_sol.py <"test.in" >"o2.out"')
        with open("o1.out", "r+") as f1, open("o2.out", "r+") as f2:
            if(f1.read().strip() != f2.read().strip()):
                print(f"{i} {k}")
                exit(1)