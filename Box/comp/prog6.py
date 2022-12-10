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
def getLeftRecur(data):
    haveRecu = []
    for i in data:
        haveRecu.extend(i for j in data[i] if j[0] == i)
    return haveRecu

if res := getLeftRecur(data):
    print(f"Expansion having Left Reccursion: {res}")
else:
   print("No Reccursion not found")

