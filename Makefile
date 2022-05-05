#Build object in the future.

CXX=g++
CXXFLAGS= -Wall
MAKEARGS=$(CXX) $(CXXFLAGS) -o $@

llistDriver:
	$(MAKEARGS) include/Nodes/nodes.hpp	include/Lists/linkedlist.hpp drivers/llistDriver.cpp
	./$@
