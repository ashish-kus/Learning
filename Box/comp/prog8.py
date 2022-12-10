string = input("Enter the Expansion for S: ")
loopStr = string.replace("/", "")
data = {"S": string.split("/")}
i = 0
while i < len(loopStr):
    if loopStr[i] in data:
        i += 1
        continue
    if loopStr[i].isupper():
        string = input(f"Enter Expansion of {loopStr[i]}: ")
        data[loopStr[i]] = string.split("/")
        loopStr += string.replace("/", "")
    i += 1
def checkOperator(data):
    op = ['+','*','/','-']
    for i in data:
        for j in op:
            for d in data[i]:
                if j in d:
                   return True
                return False
if checkOperator(data):
    print("Accepted")
else:
    print("Not Accepted")

