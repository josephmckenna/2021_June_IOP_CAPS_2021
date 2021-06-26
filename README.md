


Build instructions for C++ examples

#Create your build folder
mkdir build
# Move into your build folder
cd build
# Use CMake to build your 'Makefile'
cmake ../
# Compile the programs
make


# If you are editing the examples, you will need to re-compile
# Simply repeat the stages above, move into your build folder
cd build
# Use CMake to build update your 'Makefile' (probably not needed unless you are adding a new program)
cmake ../
# Compile the programs
make
