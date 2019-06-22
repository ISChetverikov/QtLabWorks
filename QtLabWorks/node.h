#pragma once

class Node {
private:
	int _value;

public:

	Node() {
		_value = 0;
	}

	Node(int v) {
		_value = v;
	}

	Node(const Node & other) {
		_value = other._value;
	}

	int GetValue() {
		return _value;
	}

	bool operator == (const Node & other) {
		return _value == other._value;
	}

	bool operator < (const Node & n) const {
		return _value < n._value;
	}
};