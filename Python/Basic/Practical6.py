num = int(input("num: "))

w=1
t=num
while t > 0 :
    w = w*t
    t -= 1

print(f"fact = {w}")

def facto(num):
    if num <= 1:
        return 1
    else:
        return num*facto(num-1)

print(f"fact = {facto(num)}")
