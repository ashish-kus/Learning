# https://www.hackerrank.com/challenges/list-comprehensions/problem?isFullScreen=false

x = int(input())
y = int(input())
z = int(input())
n = int(input())
result=[]
for i in range(0, x+1):
    for j in range(0, y+1):
        for k in range(0, z+1):
            if i+j+k != n:
                list=[i,j,k]
                result.append(list)

print(result)
            
        

