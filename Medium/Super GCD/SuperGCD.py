import random
import math

def gcd(a, b):
  while b:
    a, b = b, a % b
  return a

inp = open("4.in", "w")
ans = open("4.sol", "w")

randed = random.randint(1000000,100000000)

multi = random.randint(1,math.floor(100000000/randed))
num1 = multi*randed
inp.write(str(num1) + "\n")

multi = random.randint(1,math.floor(100000000/randed))
num2 = multi*randed
inp.write(str(num2))

ans.write(str(gcd(num1,num2)))

ans.close()
inp.close()