#Build object in the future.

CXX=g++
CXXFLAGS= -Wall
MAKEARGS=$(CXX) $(CXXFLAGS) -o $@

qlist:
	$(MAKEARGS) include/Lists/queuelist.hpp src/qlist.cpp
	./$@

llistDriver:
	$(MAKEARGS)	include/Nodes/nodes.hpp	include/Lists/linkedlist.hpp src/llistDriver.cpp
	./$@

bst:
	$(MAKEARGS) include/Trees/binarysearchtree.hpp src/bst.cpp
	./$@

btree:
	$(MAKEARGS) lib/Trees/binarytree.cpp src/btree.cpp
	./$@

main:
	$(MAKEARGS) lib/Trees/binarytree.cpp src/main.cpp