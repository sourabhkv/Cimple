import numpy as np
import matplotlib.pyplot as plt
from sympy import symbols, lambdify

x = [1, 3, 4, 6, 8, 9, 11, 14]
y = [1, 2, 4, 4, 5, 7, 8, 9]
n = len(x)
meanx = sum(x) / n
meany = sum(y) / n
devx = [i - meanx for i in x]
devy = [i - meany for i in y]
sdx = np.sqrt(sum([i**2 for i in devx]) / n)
sdy = np.sqrt(sum([i**2 for i in devy]) / n)
covxy = sum([devx[i] * devy[i] for i in range(n)]) / n
r = covxy / (sdx * sdy)

myx = r * sdy / sdx
mxy = r * sdx / sdy

X1, Y2 = symbols("X1 Y2")

Y1_expr = myx * X1 - myx * meanx + meany
Y1_func = lambdify(X1, Y1_expr, "numpy")

X2_expr = mxy * Y2 - mxy * meany + meanx
X2_func = lambdify(Y2, X2_expr, "numpy")

X1_values = np.linspace(0, 15, 100)
plt.plot(X1_values, Y1_func(X1_values))
Y2_values = np.linspace(0, 15, 100)
plt.plot(Y2_values, X2_func(Y2_values))
plt.scatter(x, y)
plt.show()
