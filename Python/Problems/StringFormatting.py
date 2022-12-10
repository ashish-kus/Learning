number=int(input())

x = len(format(number, 'b'))
    
for i in range(1,number+1):
      print(
           format(i).rjust(x),  # number
           format(i, 'o').rjust(x),  # octal 
           format(i, 'X').rjust(x),  # hex
           format(i, 'b').rjust(x)   # binary
            )
