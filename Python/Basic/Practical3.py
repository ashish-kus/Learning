'''to input the value of x and n and print the sum of the series: a. 1+x+x2+x3+x4+…….xn  '''

x= int(input("x = "))
y= int(input("y = "))

result=0
for i in range(x+1):
    result = result + pow(x,y)

print(result)

