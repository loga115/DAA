n=10
fp = open(f"asc_neg_{n}.txt","w")
fp.write(str(n)+" ")  
for i in range(int(-n/2),int(n/2)):
    fp.write(str(i)+" ") 
fp.write(str(n))
fp.close()
