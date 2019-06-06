import random

inp = open("1.in", "w")
ans = open("1.sol", "w")


n = 1

temp = []
miss = random.randint(0,n-1)

if random.randint(0,1):
    inp.write(str(n) + "\n")
    for i in range(0,n):
        temp.append(random.randint(1,100000))
    for i in temp:
        inp.write(str(i)+ " ")
    inp.write("\n")
    inp.write(str(n-1) + "\n")
    for i in range(0,len(temp)):
        if i != miss:
            inp.write(str(temp[i])+ " ")
else:
    for i in range(0,n):
        temp.append(random.randint(1,100000))
    inp.write(str(n-1) + "\n")
    for i in range(0,len(temp)):
        if i != miss:
            inp.write(str(temp[i])+ " ")
    inp.write("\n")
    inp.write(str(n) + "\n")
    for i in temp:
        inp.write(str(i)+ " ")

ans.write(str(temp[miss]))

inp.close()
ans.close()