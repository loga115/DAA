n=3
fp = open(f"desc_chr_{26*n}.txt","w")
# generate a file of n ascending characters, one character on each line
# n : number of times per character
alphabet = "abcdefghijklmnopqrstuvwxyz"
j = len(alphabet)-1
fp.write(str(26*n)+" ")
for i in range(1,26):
    fp.write((alphabet[j]+" ")*n)
    j -= 1

fp.close()

