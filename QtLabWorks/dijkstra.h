#pragma once
#include "graph.h"
#include "edge.h"
#include <vector>
#include <tuple>
#include <queue>
#include <map>

struct Container {
	Node Node;
	int Mark;
};

class Dijkstra {
private:
	map<Node, vector<Edge>> paths;
	map<Node, int> distances;
	map<Node, bool> isVisited;

public:

	Dijkstra(WeightedDirectedGraph graph, Node node) {

		auto vertices = graph.GetVertices();

		distances = map<Node, int>();
		isVisited = map<Node, bool>();
		for (size_t i = 0; i < vertices.size(); i++)
		{
			distances.insert(pair<Node, int>(vertices[i], INT_MAX));
			isVisited.insert(pair<Node, int>(vertices[i], false));
		}

		distances[node] = 0;
		isVisited[node] = true;
		auto Compare = [](pair<Node, int> left, pair<Node, int> right) -> bool{
			return left.second < right.second;
		};
		std::priority_queue<pair<Node, int>, vector<pair<Node, int>>, bool(*)(pair<Node, int>, pair<Node, int>)> queue(Compare);
		queue.push(pair<Node, int>(node, 0));
		isVisited[node] = true;

		while (!queue.empty())
		{
			auto current = queue.top();
			auto edges = graph.GetEdges(current.first);
			queue.pop();

			for (vector<Edge>::iterator it = edges.begin(); it != edges.end(); it++) {

				auto destination = it->GetDestination();
				auto source = it->GetSource();
				int weight = it->GetWeight();

				if (distances[destination] > distances[source] + weight) {
					distances[destination] = distances[source] + weight;
				}

				if (!isVisited[destination]) {
					queue.push(pair<Node, int>(destination, distances[destination]));
					isVisited[destination] = true;
				}
			}
		}
	}
	
	int GetDistance(Node node) {
		return distances[node];
	}
};