def binary(li,end,start,key):
    if end >= start :
        mid= (end - start)//2 + start

        if li[mid]== key:
            return key

        elif key > li[mid]:
            binary(li,end,mid,key )
        else:
            binary(li,mid -1,start,key)
    else:
        return -1

li=[ 12,1, 4, 3, 78, 11, 100, 8, 99 ]
print(li)
start=0
end=len(li)-1
key=int(input("key to search: "))

result=binary(li,end,start,key)
print(result)
