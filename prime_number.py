import math
def primeNumber(n):
    bool_list = [True] * (n+1)
    bool_list[0],bool_list[1] = False,False # 0,1 set to not prime
    for i in range(2,int(math.sqrt(n))):
        if bool_list[i]:
            for j in range(i*i,n+1,i):# the multiple of primes set to false
                bool_list[j] = False
    return [prime for prime,flag in enumerate(bool_list) if flag]

# print(primeNumber(100))
    
from numba import cuda
import numpy as np
import math
import time
import pandas as pd

@cuda.jit
def sieve_kernel(prime_array, n):
    idx = cuda.grid(1)
    if idx > 1 and idx * idx <= n:
        if prime_array[idx]:
            for j in range(idx * idx, n + 1, idx):
                prime_array[j] = False

def sieve_of_eratosthenes_gpu(limit):
    prime_array = np.ones(limit + 1, dtype=bool)
    prime_array[:2] = False

    threads_per_block = 256
    blocks_per_grid = (limit + (threads_per_block - 1)) // threads_per_block

    # Move the prime array to GPU
    d_prime_array = cuda.to_device(prime_array)

    # Launch the GPU kernel
    sieve_kernel[blocks_per_grid, threads_per_block](d_prime_array, limit)

    # Copy the result back to CPU
    d_prime_array.copy_to_host(prime_array)
    
    # Return the indices of prime numbers
    return np.nonzero(prime_array)[0]

# Example usage
limit = 10**9  # 10**10 makes out of memoery error
start = time.time()
prime_numbers = sieve_of_eratosthenes_gpu(limit)
prime_numbers = np.array(prime_numbers)
print(time.time() - start) #15 seconds
print(len(prime_numbers))
df = pd.DataFrame(prime_numbers)
df.to_csv("primesList.cvs",index=False)
print("Done")
