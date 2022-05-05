#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "vector"

struct Vertex
{
    int vertexID;
    int vertexWeight;
};

class Graph
{
public:
    void AddVertex(int weight);
    void AddEdge(int fromVert, int toVert);
private:
    std::vector<Vertex> vertices;
};

#endif