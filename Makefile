#Build object in the future.

CXX=g++
CXXFLAGS= -Wall
MAKEARGS=$(CXX) $(CXXFLAGS) -o $@

qlist:
	$(MAKEARGS) include/Lists/queuelist.hpp src/qlist.cpp
	./$@

llist:
	$(MAKEARGS) include/Lists/linkedlist.hpp src/llist.cpp
	./$@

bst:
	$(MAKEARGS) include/Trees/binarysearchtree.hpp src/bst.cpp
	./$@

btree:
	$(MAKEARGS) lib/Trees/binarytree.cpp src/btree.cpp
	./$@

main:
	$(MAKEARGS) lib/Trees/binarytree.cpp src/main.cpp