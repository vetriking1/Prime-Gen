package main

import (
	"fmt"
	"math"
	"os"
)

func generatePrime(limit int) []int {
	var primes = make([]bool, limit)
	var primeArr []int = make([]int, 0)

	for i := 0; i < limit; i++ {
		primes[i] = true
	}

	primes[0] = false
	primes[1] = false

	for i := 2; i <= int(math.Sqrt(float64(limit))); i++ {
		if primes[i] {
			for j := i * i; j < limit; j += i {
				primes[j] = false
			}
		}
	}

	for i := 2; i < limit; i++ {
		if primes[i] {
			// fmt.Println(i)
			primeArr = append(primeArr, i)
		}
	}
	return primeArr

}

func main() {
	limit := 1000000000
	var primes []int = generatePrime(limit)
	fmt.Println("Primes are generated")
	file, err := os.Create("primes.txt")
	if err != nil {
		fmt.Println("Error creating the file")
		return
	}
	defer file.Close()
	for _, prime := range primes {
		_, err := file.WriteString(fmt.Sprintf("%d\n", prime))
		if err != nil {
			fmt.Println("Error writing to file")
		}
	}
	fmt.Printf("done!")
}
