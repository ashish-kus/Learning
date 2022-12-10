# Given the participants' score sheet for your University Sports Day,
# you are required to find the runner-up score. You are given n scores.
# Store them in a list and find the score of the runner-up. 

n= int(input())
score=list(set(map(int, input().split())))
score.sort()
print(score[-2])


