import random
import string

def randomString(stringLength):
    """Generate a random string of fixed length """
    letters = string.ascii_letters
    return ''.join(random.choice(letters) for i in range(stringLength))

def check(st):
    temp = st[::-1]
    if temp==st:
        return True
    return False

for r in range(1,21):
    n = random.randint(1, 1000)
    inp = open(str(r) + ".in", "w")
    ans = open(str(r) + ".sol", "w")
    inp.write(str(n))
    inp.write("\n")
    for t in range(0,n):
        palin = random.randint(0,1)
        if(palin):
            ran = random.randint(1,50) #501
            randed = randomString(ran)
            randed = randed + randed[::-1]
        else:
            ran = random.randint(2,101) #1001
            randed = randomString(ran)
        if(check(randed)):
            ans.write("Yes")
            ans.write("\n")
        else:
            ans.write("No")
            ans.write("\n")
        inp.write(randed)
        inp.write("\n")
    inp.close()
    ans.close()
