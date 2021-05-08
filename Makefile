#Build object in the future.

CXX=g++
CXXFLAGS= -Wall

btree:
	$(CXX) $(CXXFLAGS) -o $@ lib/Trees/binarytree.cpp src/btree.cpp
	./$@

main:
	$(CXX) $(CXXFLAGS) -o $@ lib/Trees/binarytree.cpp src/main.cpp