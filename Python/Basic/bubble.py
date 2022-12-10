li=[1, 3, 5, 3, 8, 2, 6 ]

for i in range(len(li)):
    for j in range(len(li) - i -1):
        if li[j] > li[j+1]:
            var=li[j]
            li[j]=li[j+1]
            li[j+1]=var

print(li)

