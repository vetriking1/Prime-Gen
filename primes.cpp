#include <iostream>
#include <cmath>
#include <fstream> // For file handling

using namespace std;

int main()
{
    int n = 1000000000;
    bool primes[n];
    for (int i = 0; i < n; i++)
    {
        primes[i] = true;
    }
    primes[0] = false;
    primes[1] = false;

    int limit = sqrt(n);

    for (int i = 2; i < limit; i++)
    {
        if (primes[i]) // Only proceed if 'i' is still prime
        {
            for (int j = i * i; j < n; j += i)
            {
                primes[j] = false;
            }
        }
    }

    ofstream outFile("primes.txt"); // Open a file for writing
    if (!outFile)
    {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    for (int i = 2; i < n; i++)
    {
        if (primes[i])
        {
            cout << i << endl;
            outFile << i << endl; // Write the prime number to the file
        }
    }

    outFile.close(); // Close the file
    return 0;
}
