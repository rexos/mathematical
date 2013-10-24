import matplotlib.pyplot as plt
import numpy as np

times = []

with open('raytime.txt', 'r') as file:
    times = [ float(line.strip()) for line in file ]

x = np.linspace(0,901,901)
plt.plot(x,times,'b.')
plt.xlabel('Ray Number')
plt.ylabel('Ray Time')
plt.title('Grid travel time')
plt.show()
        
