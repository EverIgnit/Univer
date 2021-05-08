import numpy as np
import matplotlib.pyplot as plt

x = np.array([-3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7])
y = np.array([-2.6, -0.3, -2, -2.3, -1.5, 0.7, 3.2, 4.0, 5.1, 6.4, 6.8])
plt.plot(x, y, 'o')

a, b = np.linalg.lstsq(np.vstack([x, np.ones(len(x))]).T, y, rcond=None)[0]
print('y =', round(a, 3), '*x +', round(b, 3))
plt.plot(x, a * x + b, color='green')

k = np.polyfit(x, y, 2)
print('y =', round(k[0], 3), 'x**2 +', round(k[1], 3), '*x+', round(k[2], 3))
plt.plot(x, k[0] * x ** 2 + k[1] * x + k[2], color='red')

k = np.polyfit(x, y, 3)
print('y =', round(k[0], 3), 'x**3 + ', round(k[1], 3), 'x**2 +', round(k[2], 3), '*x+', round(k[3], 3))
plt.plot(x, k[0]*x**3+k[1] * x ** 2 + k[2] * x + k[3], color='blue')

plt.show()
