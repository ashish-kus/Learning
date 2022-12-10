s=input()
n=int(input())
start=0
while start<len(s):
    end=start+n
    print(s[start:end]) 
    start=end
    
