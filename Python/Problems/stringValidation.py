s = input()

num=alpha= digit=lowercase = uppercase = False 

for i in s:
    if i.isalnum():
        num= True
    if i.isalpha():
        alpha = True 
    if i.isdigit():
        digit= True
    if i.islower():
        lowercase= True
    if i.isupper():
        uppercase= True
print(num, alpha,digit,lowercase,uppercase,sep='\n')

