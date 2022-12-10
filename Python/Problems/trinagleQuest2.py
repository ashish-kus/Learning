height=int(input())

for i in range(1,height+1):
    for ele in range(1, i+1):
        print(ele, end="")
    num=i
    while num > 1 :
        print(num-1, end="")
        num-=1
        pass
    print()

