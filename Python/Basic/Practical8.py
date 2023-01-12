li=input("STRING: ").split()
  # taking input from user

def dublicate(li):
    size=len(li)
    dli=[]
    for i in range(size):
        k=i+1
        for j in range(k,size):
            if li[i]==li[j]:
                dli.append(li[j])
    return dli
        

r=dublicate(li)
print(set(r))



