poss_cores = ["chem", "phys", "bio"]
poss_elecs = ["cs", "chem", "phys", "tech", "engg", "agri", "bio"]
core_pref = dict()
elec_pref = dict()

cores = input().split(" ")
elecs = input().split(" ")
for i, core in enumerate(cores):
    core_pref[core] = - i * 200

for i, elec in enumerate(elecs):
    elec_pref[elec] = - i * 150

bff, bfn = map(int, input().split(" "))
for _ in range(bfn):
    name, core, elec = input().split(" ")
    core_pref[core] += bff
    elec_pref[elec] += bff

ff, fn = map(int, input().split(" "))
for _ in range(fn):
    name, core, elec = input().split(" ")
    core_pref[core] += ff
    elec_pref[elec] += ff

cff = int(input())
crushie_name, crushie_core, crushie_elec = input().split(" ")
core_pref[crushie_core] += cff
elec_pref[crushie_elec] += cff

cores.sort(key=lambda c: core_pref[c], reverse = True)
elecs.sort(key=lambda e: elec_pref[e], reverse = True)

print(cores[0])
print(elecs[1] if cores[0] == elecs[0] else elecs[0])