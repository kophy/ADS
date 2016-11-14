#!/usr/bin/env python
from random import randint

"""
Reservoir Sampling by Jeffrey Vitter
"""
def ReservoirSampling(data, k):
    result = data[0:min(len(data), k)];
    for i in range(k, len(data)):
        r = randint(0, i);
        if r < k: result[r] = data[i];        
    return result;

if __name__ == "__main__":
    data = [i for i in range(50)];
    print ReservoirSampling(data, 5);
