
import matplotlib.pyplot as plt
import numpy as np

# Generate random data for the histogram
data = np.random.randn(1000)

# Create a histogram with specific color, edge color, and line width
plt.hist(data, bins=60, color='skyblue', edgecolor='black', linewidth=1.2)

# Customize the chart
plt.xlabel('Values')
plt.ylabel('Frequency')
plt.title('Histogram with Customization')
plt.grid(axis='y', linestyle='--', alpha=0.5)

# Show the plot
plt.show()
