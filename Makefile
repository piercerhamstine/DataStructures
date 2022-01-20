#Build object in the future.

CXX=g++
CXXFLAGS= -Wall
MAKEARGS=$(CXX) $(CXXFLAGS) -o $@

llistDriver:
	$(MAKEARGS) in/Nodes/nodes.hpp	in/Lists/linkedlist.hpp src/llistDriver.cpp
	./$@
