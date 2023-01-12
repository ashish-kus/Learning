li=input("STRING: ").split()
d={}
for i in li:
    if i in d:
        d[i] += 1
    else:
        d[i]=1
max=0
maxk=""
for i in d:
    if d[i] > max:
        max = d[i]
        maxk = i
print(maxk)


