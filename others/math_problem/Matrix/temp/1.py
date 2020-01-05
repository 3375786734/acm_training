from scipy import linalg
import numpy as np


A = np.array([[1,-1,-2,-1],[2,1,1,1],[1,1,0,-3],[0,1,-1,-7]])
b = np.array([0,0,0])

x = linalg.solve(A,b)
print(x)
