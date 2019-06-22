#pragma once

#include <QtGui>
#include <QPushButton>
#include "graph.h"
#include "Dijkstra.h"
#include "rasterwindow.h"
#include "Node.h"
#include "Edge.h"

class GraphVisualization : public rasterWindow
{
private:
	WeightedDirectedGraph _graph;
	vector<Edge> _edges;
	Node _start;
	Node _end;

	void render(QPainter* p) override;
	void drawArrow(QPainter* p, QPoint x1, QPoint x2, const char * text, bool isHighlighted);
	void handleButton();

public:
	GraphVisualization(WeightedDirectedGraph &gr, vector<Edge> edges, Node start, Node end);
	GraphVisualization();
};
