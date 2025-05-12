g++ -o $1 $1.cpp $(pkg-config opencv4 --libs --cflags)
