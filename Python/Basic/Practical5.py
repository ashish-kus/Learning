st=input("string :")
d={}

for i in st:
    count = 0
    for j in st:
        if j == i:
            count += 1
    if i in d:
        pass
    else:
        d[i]= count


print(d)
    

