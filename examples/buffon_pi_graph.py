# This computes 1 / pi by tossing needles

import random
import numpy as np
import matplotlib.pyplot as plt
import time
from decimal import Decimal


N = int(input("How many needles would you like to toss? "))
start_time = time.time()
needle_to_line_ratio = 0.5

iter = np.arange(N) + 1
hits = np.zeros(N)

for n in range(N):
    # theta is the angle of the needle
    theta = 2*np.pi*np.random.random()
    height = abs(needle_to_line_ratio * np.sin(theta))

    # hit, chance 1 in height
    hit = np.random.random() < height

    hits[n] = hit

plt.plot(iter, 1./(np.cumsum(hits)/iter) / (np.pi))
plt.axhline(1.0)

print("{:.2E}".format(Decimal((time.time()-start_time)/N)))
plt.show()

#input('Press enter to exit. ')