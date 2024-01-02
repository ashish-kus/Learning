import matplotlib.pyplot as plt
import numpy as np
x = np.linspace(0, 10, 100)
y1 = np.sin(x)
y2 = np.cos(x)
plt.plot(x, y1, label='Sin(x)', color='blue')
plt.plot(x, y2, label='Cos(x)', color='red')
plt.fill_between(x, y1, y2, color='green', alpha=0.3) # Apply green fill color with transparency
plt.xlabel('X-axis')
plt.ylabel('Y-axis')
plt.title('Area Chart with Fill Color and Transparency')
plt.legend()
plt.show()
