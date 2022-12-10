string=input()
result=""
for i in range(len(string)):
    ch=string[i]
    if string[i].isalpha():
        if string[i].isupper():
            result=result+string[i].lower()
        else:
            result=result+string[i].upper()
    else:
        result+=string[i]
print(result)
