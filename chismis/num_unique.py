names = """nayeon
momo
jeongyeon
sana
mina
tzuyu
dahyun
chaeyoung
tetia
richeh
aggott
qifrey
olruggio
olly
alaira
tartah
ronron
aron
aaron
emm
em
marie
josette
emma
ray
norman
roy
gilda
don
john
anna
ana
anne
nat
nick
thoma
lannion
b
gabee
gabby
gabbie
gabriel
badeline
madeline
mads
maddie
apple
peach
raven
blondie
goldy
goldie
cerise
goldee
daring
dexter
darling
briar
yuri
yor
loid
anya
franky
bond
sylvia
becky
damian
emile
ewen
twilight
fiona
shrek
donkee
donkey
himawari
mahito
himi
natsuko
jiro
nahoko
kiki
tombo
howl
sophie
suliman
calcifer
shirayuki
zen
obi
mitsuhide
sora
umi
uchuu
reuben
kaze
haku
chihiro
marnie
emily
kazuhiko
nanny
hisako
sayaka
oiwa
sho
arrietty
haru
spiller
niya
shun
yuichiro
sachiko
shirou
ryoko
miki
muta
yuki
humbert
natoru
muge
hinode
nana
lili
mikage
spica
urara
yuuhi
warawara
kiriko
suisei
gura
sheeta
pazu
muska
dola
louis
charles
jiji
cloth
hornet
zote
radiance
quirrel
cornifer
minerva
athena
skye
sky
mary
jane
mj
michael
jackson
monique
jhoienyl
jonel
janelle
mirai
cress
adan
myu
lauren
sarah
sara
sera
aydan
eden
lance
ian
ieuan
sayoowee
bumblebee
mateo
matteo
matt
carlo
carlos
inigo
paolo
paul
amos
talan
marco
polo
kart
bartholomew
henry
allen
barry
bart
iris
eris
basti
hr
harrison
harry
hermione
ron
snape
dumbledore
cedric
diggory
myrtle
luna
cho
molly
percy
annabeth
penelope
grover
neville
clarisse
luke
chiron
cerebus
dionysus
sally
asriel
bratty
catty
tem
tommy
temmy
temmie
chara
frisk
undyne
sans
flowey
ralsei
kris
susie
toriel
asgore
mettaton
toby
papyrus
paps
tobi
tauriel
sussy
sucy
akko
lotte
lotty
ursula
diana
lazurite
lina
doon
alphonso
randy
rainbowdash
pinkiepie
applejack
rarity
twilightsparkle
sparkle
shoko
shoya
natsume
porter
skey
lexi
cob
justine
elarpi
tong
kui
clerk
delro
saryo
vick
tor
yah
ordun
au
lychee
pluto
callisto
io
ganymede
kay
wymari
stella
carl
leen
lian
tera
jard
mansi
nido
tow
bee
lapi
tan
jian
ale
minji
danielle
hanni
hyein
haerin
yunjin
heeseung
jake
jay
jimin
v
rapmonster
gabe
guinevere
rednos
frenshwa
heya
takoyaki
gertrude
jan
coco
orang
boi
gurl
sunde
halpe
cross
ink
gaster
nightmare
"""

tally = dict()
print(len(names.split("\n")))

for name in names.split("\n"):
    if(name not in tally):
        tally[name] = 1
    else:
        tally[name] += 1
        print(name)