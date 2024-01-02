import matplotlib.pyplot as plt
import numpy as np

# Sample data
data = np.random.normal(0, 1, 1000)  # Generating random data (normal distribution)

# Calculate percentiles
percentiles = [25, 50, 75]
percentile_values = np.percentile(data, percentiles)

# Create a horizontal bar chart
plt.barh(['25th Percentile', '50th Percentile (Median)', '75th Percentile'], percentile_values, color='skyblue')

# Add labels and title
plt.xlabel('Data Value')
plt.title('Percentiles on a Horizontal Bar Chart')

# Show the plot
plt.show()
