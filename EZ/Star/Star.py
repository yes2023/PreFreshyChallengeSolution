n = int(input())
p = open("9.in", "w")
p.write(str(n))
f = open("9.sol", "w")
for i in range(0,n):
    for t in range(0,i+1) :
        f.write("*")
    f.write("\n")
p.close()
f.close()