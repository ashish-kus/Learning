# Task
# Given a year, determine whether it is a leap year. If it is a leap year,
# return the Boolean True, otherwise return False.

# Condition:
# A year is a leap year if the following conditions are satisfied: 
# The year is multiple of 400.
# The year is multiple of 4 and not multiple of 100.


def is_leap(year):
    leap = False
    
    if year % 400 == 0:
        leap = True
    if year % 4 == 0 and year % 100 != 0:
        leap = True
    
    return leap

year = int(input())
print(is_leap(year))
