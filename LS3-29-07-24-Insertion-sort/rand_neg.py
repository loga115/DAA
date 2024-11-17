n=10
import random
# generate n random negative and positive numbers
fp = open(f"rand_neg_{n}.txt","w")
fp.write(str(n)+" ")
for i in range(n):
    fp.write(str(random.randint(-n,n))+" ")
fp.close()