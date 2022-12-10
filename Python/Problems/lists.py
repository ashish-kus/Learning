n=int(input())
li=[]
for i in range(n):
    command=input().split()
    match command[0]:
        case "insert":
            li.insert(int(command[1]), int(command[2]))
        case "print":
            print(li)
        case "remove":
            li.remove(int(command[1]))
        case "append":
            li.append(command[1])
        case "sort":
            li.sort()
        case "pop":
            li.pop()
        case "reverse":
            li.reverse()
        case _:
            pass
