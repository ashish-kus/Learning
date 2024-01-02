import numpy as np
# imported numpy library as np used for numarical calculations 
import matplotlib.pyplot as plt
# import PyPlot from matplotlib as plt for plotting varios data.

x= np.linspace(0,2*np.pi, 100)
# linespace() is a function that return evenly sapareted values in a given range, here
# x=np.linespace() starts from "0", stops at "2*pi" and gives 100 values.
y=np.sin(x)
# above x values is passed to cosine function and y value is generated for each x value.

plt.figure(figsize=(8,6))
#initializing the figure canvas for the plot with size fiven using figsize() function.

plt.plot(x,y,label='Cosine Wave nandu',color='blue')

plt.title('Angle (radians)')
plt.ylabel('Cosine')
plt.legend()
plt.grid(True)
plt.show()
