


# Build instructions for C++ examples

## Move into your build folder
cd examples
## Use CMake to build your 'Makefile'
cmake .
## Compile the programs
make


## If you are editing the examples, you will need to re-compile
## Simply repeat the stages above, move into your build folder
cd examples
## Use CMake to build update your 'Makefile' (probably not needed unless you are adding a new program)
cmake .
## Compile the programs
make



# How to run primes in many languages

# C++ (after you've compiled it with insructions above)
./primes.exe 

# Java
java primes.java

# Python
python primes.py

# R
Rscript primes.r

# Julia
julia primes.jil

# Octave (MATLAB)
octave primes.m

# Rust
## Compile
rustc primes.rc
## Run
./primes

# Go
go run primes.go