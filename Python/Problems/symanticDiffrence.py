n=int(input())
ln=set(map(int, input().split()))
m=int(input())
lm=set(map(int, input().split()))

com=ln.intersection(lm)
uni=ln.union(lm)
for elem in com:
    uni.discard(elem)
result=sorted(uni, key=int)
print(*uni, sep="\n")
