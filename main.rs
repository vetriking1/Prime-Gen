fn main() {
    let mut primes: [bool; 1000000000] = [true; 1000000000];
    primes[0] = false;
    primes[1] = false;

    for i in 2..1000000000 {
        if primes[i] {
            for j in ((i * i)..1000000000).step_by(i) {
                primes[j] = false;
            }
        }
    }

    for i in 2..1000000000 {
        if primes[i] {
            println!("{}", i);
        }
    }
}
