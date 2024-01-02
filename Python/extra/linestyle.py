import numpy as np
import matplotlib.pyplot as plt

x=[1,2,3,4,5]
y=[2,4,6,8,10]

plt.figure()

plt.plot(x,y,label="solid", linestyle='-')
plt.plot(x,[i * 1.5 for i in y ],label="dashes", linestyle='--')
plt.plot(x,[i * 1.5 for i in y ],label="solid", linestyle=':')
plt.plot(x,[i * 1.5 for i in y ],label="solid", linestyle='-.')
plt.plot(x, [i * 3 for i in y], label='Custom Dashes', linestyle=(0, (3, 5, 1, 5)))

plt.xlabel('x-axis')
plt.ylabel('y-axis')
plt.title('Diffrent line typrs')
plt.legend()
plt.grid(True)
plt.show()

