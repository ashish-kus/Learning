n=int(input())
arr=input().split()
s= sum(list(set(map(int, arr))))
result= s/n
print(result)
