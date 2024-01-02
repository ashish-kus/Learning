import matplotlib.pyplot as plt
sizes = [30, 20, 25, 15, 10]
labels = ['A', 'B', 'C', 'D', 'E']
explode = (0.1, 0, 0, 0, 0) # Separation for each section (explode only the first section)
# plt.pie(sizes, labels=labels, explode=explode, autopct='%1.1f%%')
plt.pie(sizes, labels=labels, shadow=True, startangle=90, autopct='%1.1f%%')
plt.title('Pie Chart with Exploded Section')
plt.show()
