import numpy as np
import matplotlib.pyplot as plt

# Time from 0s to 5s in 0.2s intervals
t = np.arange(0.0, 5.0, 0.2)
plt.plot(t, t, 'r--', t, t**2, 'b--', t, t**3, 'g--')
