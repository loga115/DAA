n=10
fp = open(f"desc_neg_{n}.txt","w")
fp.write(str(n)+" ")  
for i in range(int(n/2),int(-n/2),-1):
    fp.write(str(i)+" ")
fp.write(str(int(-n/2)))
fp.close()
