import random
import math
n = int(input())
inp = open("6.in", "w")
ans = open("6.sol", "w")
ansNum = 0
inp.write(str(n))
inp.write("\n")
gcd = random.randint(1,100000)
for i in range(1,n+1):
    multi = random.randint(3,math.floor(1000000/gcd))
    while(multi*gcd>1000000):
        multi = random.randint(3,math.floor(1000000/gcd))
    ansNum += multi
    inp.write(str(multi*gcd))
    inp.write("\n")
ans.write(str(ansNum))
ans.close()
inp.close()