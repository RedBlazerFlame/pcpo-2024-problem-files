from os import system

for i in range(1, 1000):
    with open("test.in", "w+") as f:
        res = f"{i}\n"
        f.write(res)
    
    system(f'./main_tle <"test.in" >"o1.out"')
    system(f'./main <"test.in" >"o2.out"')
    system('diff o1.out o2.out')