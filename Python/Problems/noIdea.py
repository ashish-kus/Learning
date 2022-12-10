n, m= map(int,input().split())
arr=list(map(int, input().split()))
A=set(map(int, input().split()))
B=set(map(int, input().split()))

hapns=0

for ele in arr:
    if ele in A:
        hapns += 1
    elif ele in B:
        hapns -= 1
    else:
        pass

print(hapns)


