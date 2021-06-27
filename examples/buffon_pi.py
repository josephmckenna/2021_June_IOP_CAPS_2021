# This computes 1 / pi by tossing needles

import numpy as np
import time
from decimal import Decimal


N = int(input("How many needles would you like to toss? "))
start_time = time.time()

hit = np.int(0)

for n in range(N):
    # theta is the angle of the needle
    theta = np.random.uniform(0,2*np.pi)
    height = abs(np.sin(theta))

    # hit, chance 1 in height
    if height > np.random.random():
        hit = hit + 1

stop_time = time.time()

print("Count = "+ str(hit) + " Fractional Error = " + str( 2 * (((N / hit) / (0.5*np.pi)) - 1) ))

print("Time per = {:.2} us/N ".format(Decimal((stop_time-start_time)* 1000000/N)))