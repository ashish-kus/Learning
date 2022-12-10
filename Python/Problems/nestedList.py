# Given the names and grades for each student in a class of students,
# store them in a nested list and print the name(s) of any student(s)
# having the second lowest grade.

n = int(input())
record=[]
marks=[]
for i in range(n):
    name=str(input())
    grade=float(input())
    entry=[name, grade]
    marks.append(grade)
    record.append(entry)


mark = list(set(marks))
mark.sort()
target=mark[1]
record=sorted(record,key=lambda x: x[0])
result=[]
for i in record:
    if i[1] == target:
        print(i[0])

