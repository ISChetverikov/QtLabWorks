#pragma once
#include "graph.h"
#include "edge.h"
#include <vector>
#include <tuple>
#include <queue>
#include <functional>
#include <map>
#include <algorithm>

class PriorityQueue {
	vector<pair<Node, int>> q = vector<pair<Node, int>>();
public:
	bool empty() {
		return q.size() == 0;
	}

	void push(pair<Node, int> e) {
		q.push_back(e);
		
		if (q.size() == 1) {
			return;
		}

		int i = q.size() - 1;
		while (i >= 1 && q[i].second >= q[i - 1].second) {
			swap(q[i], q[i-1]);
			i--;
		}
	}

	pair<Node, int> pop() {
		pair<Node, int> result(q.back());
		
		q.pop_back();

		return result;
	}

};

class Dijkstra {
private:
	map<Node, vector<Edge>> paths;
	map<Node, int> distances;
	map<Node, bool> isVisited;
	Node _start;

public:

	Dijkstra(WeightedDirectedGraph graph, Node node) {
		_start = node;
		auto vertices = graph.GetVertices();

		distances = map<Node, int>();
		isVisited = map<Node, bool>();
		paths = map<Node, vector<Edge>>();
		for (size_t i = 0; i < paths.size(); i++)
		{
			paths[i] = vector<Edge>();
		}

		for (size_t i = 0; i < vertices.size(); i++)
		{
			distances.insert(pair<Node, int>(vertices[i], INT_MAX));
			isVisited.insert(pair<Node, int>(vertices[i], false));
		}

		distances[node] = 0;
		PriorityQueue queue;
		queue.push(pair<Node, int>(node, 0));

		while (!queue.empty())
		{
			auto current = queue.pop();
			auto edges = graph.GetEdges(current.first);

			for (vector<Edge>::iterator it = edges.begin(); it != edges.end(); it++) {

				auto destination = it->GetDestination();
				auto source = it->GetSource();
				int weight = it->GetWeight();

				if (!isVisited[destination] && distances[destination] > distances[source] + weight) {
					distances[destination] = distances[source] + weight;
					paths[destination] = vector<Edge>(paths[source]);
					paths[destination].push_back(*it);
				}

				if (!isVisited[destination]) {
					queue.push(pair<Node, int>(destination, distances[destination]));
				}
			}
			isVisited[current.first] = true;
		}

		for (auto& path : paths) {
			if (distances[path.first] == INT_MAX) {
				path.second.clear();
			}
		}
	}
	
	int GetDistance(Node node) {
		return distances[node];
	}

	vector<Edge> GetPath(Node node) {
		return paths[node];
	}

	Node GetStart() {
		return _start;
	}
};