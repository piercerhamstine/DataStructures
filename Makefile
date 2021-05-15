#Build object in the future.

CXX=g++
CXXFLAGS= -Wall
MAKEARGS=$(CXX) $(CXXFLAGS) -o $@

bst:
	$(MAKEARGS) include/Trees/binarysearchtree.hpp src/bst.cpp
	./$@

btree:
	$(MAKEARGS) lib/Trees/binarytree.cpp src/btree.cpp
	./$@

main:
	$(MAKEARGS) lib/Trees/binarytree.cpp src/main.cpp