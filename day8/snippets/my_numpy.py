import numpy as np

A = np.arange(12).reshape(4,3)
B = np.arange(12).reshape(3,4)

prod = A.dot(B)

print(prod)
