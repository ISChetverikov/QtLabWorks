#pragma once
#include <vector>
#include "edge.h"
#include "node.h"

using namespace std;

class WeightedDirectedGraph {

private:
	vector<Node> _vertices;
	vector<Edge> _edges;

public:

	WeightedDirectedGraph() {
		_vertices = vector<Node>();
		_edges = vector<Edge>();
	}

	WeightedDirectedGraph(vector<Node> vertices, vector<Edge> edges) : 
		_vertices(vertices), _edges(edges) 
	{
	}

	int GetVerticesNumber() {
		return _vertices.size();
	}

	void AddEdge(Edge edge) {
		_edges.push_back(edge);

	}

	void AddVertex(Node vertex) {
		_vertices.push_back(vertex);
	}
	
	vector<Node> GetVertices() {
		return _vertices;
	}

	vector<Edge> GetEdges(Node node) {
		vector<Edge> result;

		for (size_t i = 0; i < _edges.size(); i++)
		{
			if (_edges[i].GetSource() == node)
				result.push_back(_edges[i]);
		}

		return result;
	}

};