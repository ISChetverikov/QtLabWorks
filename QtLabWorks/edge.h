#pragma once
#include "Node.h"

class Edge {
private:
	Node _source;
	Node _destination;
	int _weight;

public:
	Edge(Node source, Node destination, int weight = 0) :
		_source(source), _destination(destination), _weight(weight) {}

	Node GetSource() {
		return _source;
	}

	Node GetDestination() {
		return _destination;
	}

	int GetWeight() {
		return _weight;
	}

	bool operator < (const Edge & other) {
		return _weight < other._weight;
	}

	bool operator > (const Edge & other) {
		return _weight > other._weight;
	}

	bool operator == (const Edge & other) {
		return _weight == other._weight;
	}

	bool operator != (const Edge & other) {
		return _weight != other._weight;
	}
};