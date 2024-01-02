import matplotlib.pyplot as plt
x_values = [1, 2, 3, 4, 5] # x-axis values
y_values = [10, 15, 7, 10, 5] # y-axis values
plt.bar(x_values, y_values, align='edge', color='blue', edgecolor='black')
plt.xlabel('X-axis Label')
plt.ylabel('Y-axis Label')
plt.title('Vertical Bar Chart')
plt.show()
