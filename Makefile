#Build object in the future.

CXX=g++
CXXFLAGS= -Wall
MAKEARGS=$(CXX) $(CXXFLAGS) -o $@

bst:
	$(MAKEARGS) lib/Trees/binarysearchtree.cpp src/bst.cpp
	./$@

btree:
	$(MAKEARGS) lib/Trees/binarytree.cpp src/btree.cpp
	./$@

main:
	$(MAKEARGS) lib/Trees/binarytree.cpp src/main.cpp