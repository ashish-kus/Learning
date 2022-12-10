start=int(input("Start number :"))

end=int(input("end number :"))

for i in range(start,end):
    flag=True
    for j in range(2,i//2+1):
        if i % j == 0:
            flag=False
    if flag:
        print(i)
