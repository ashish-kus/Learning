number = int(input())
li   = input().split()
t     = tuple(map(int, li))
print(hash(t))
