import matplotlib.pyplot as plt
import numpy as np

# Generate sample data
x = np.linspace(0, 10, 100)
y = np.sin(x)

# Plot the data
plt.plot(x, y, label='Sin(x)')

# Add gridlines
plt.grid(True, linestyle='--', linewidth=0.5,which='minor', color='red', alpha=0.7)

# Add labels and legend
plt.xlabel('X-axis')
plt.ylabel('Y-axis')
plt.title('Plot with Gridlines')
plt.legend()

# Show the plot
plt.show()
