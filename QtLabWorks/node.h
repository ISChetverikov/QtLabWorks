#pragma once

class Node {
private:
	int _value;

public:

	Node(int v) {
		_value = v;
	}

	int GetValue() {
		return _value;
	}

	bool operator == (const Node & other) {
		return _value == other._value;
	}
};