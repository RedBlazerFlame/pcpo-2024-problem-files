from os import system

for i in range(1, 9):
    system(f'pypy ac_sol.py <"{i}.in" >"{i}.out"')