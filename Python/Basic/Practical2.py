n=int(input("n = "))
m=int(input("m = "))

print("with for loop")
result = n
for i in range(1,m):
    result = result * n
print(result)


print("with method")
print(pow(n,m))
    
