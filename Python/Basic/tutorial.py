print("Ashish")

# print("nandu", "bandu", sep="-", end="*")
# print("bandu")


# PRINT
# value = input("INPUT: ")
# print(f"{value}")

#INT



#Float
# x=float(input("whats x= "))
# y=float(input("whats y= "))
# print(x+y)

# print(round((x+y),2)) # rounding up to 2 digit after the decimal

# # Format output with commas.
# z=(x+y)
# print(f"{z:,}")


# devide and format

# x=float(input("whats x= "))
# y=float(input("whats y= "))
# print(x/y)
# print(round((x/y),2))
# print(f"{(x/y):.2f}")

# functions ----------------------------------------

# def hello():
#     print("Hellow")

# hello()

def main():
    x=int(input("X: "))
    print("x squre: ", squre(x))

def squre(n):
    # return n * n
    # return n ** 2
    return pow(n,2)

main()

