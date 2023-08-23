from os import system

for i in range(1, 40):
    with open("test.in", "w+") as f:
        res = f"{i}\n"
        f.write(res)
    
    system(f'./cpp1_ac <"test.in" >"o1.out"')
    system(f'pypy py2_ac.py <"test.in" >"o2.out"')
    system('diff o1.out o2.out')