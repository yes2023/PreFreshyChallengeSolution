import random

def fib(n):
    a, b = 1, 1
    for _ in range(n):
        yield a
        a, b = b, a + b

inp = open("10.in", "w")
ans = open("10.sol", "w")
n = 100000
inp.write(str(n))
inp.write("\n")
temp = list(fib(40))
for i in range (0,n):
    if random.randint(0,1):
        randed = temp[random.randint(0,39)]
    else :
        randed = random.randint(0,1000000)
    inp.write(str(randed))
    inp.write("\n")
    if(randed in temp):
        ans.write("Yes")
    else:
        ans.write("No")
    ans.write("\n")
inp.close()
ans.close()