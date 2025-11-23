#include <stdio.h>
#include <math.h>
#define N 1000000000

int main()
{
    printf("The primes program\n");
    static _Bool primes[N]; // Use static to avoid stack overflow
    for (int i = 0; i < N; i++)
    {
        primes[i] = 1;
    }
    primes[0] = 0;
    primes[1] = 0;
    int limit = sqrt(N);

    for (int i = 2; i <= limit; i++)
    {
        if (primes[i]) // Only proceed if 'i' is still prime
        {
            for (int j = i * i; j < N; j += i)
            {
                primes[j] = 0;
            }
        }
    }

    FILE *file = fopen("primes.txt", "w"); // Open a file for writing
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }

    int l = 0;
    for (int i = 2; i < N; i++)
    {
        if (primes[i])
        {
            l = i;
            // printf("%d\n", i);
            fprintf(file, "%d\n", i); // Write the prime number to the file
        }
    }
    printf("The largest prime is %d\n", l);
    fclose(file); // Close the file
    return 0;
}
