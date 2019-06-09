#pragma once

#include <QtGui>
#include "graph.h"
#include "Dijkstra.h"
#include "rasterwindow.h"

class GraphVisualization : public rasterWindow
{
private:
	WeightedDirectedGraph graph;

	void render(QPainter* p) override;
	void drawArrow(QPainter* p, QPoint x1, QPoint x2, const char * text);

public:
	GraphVisualization(WeightedDirectedGraph &gr);
};
