n=int(input())
students={}
for i in range(n):
    inp=input().split()
    students[inp[0]]= inp[1:]
target=input()
ll=students.get(target)
for ele in range(3):
    ll[ele]=int(ll[ele])


