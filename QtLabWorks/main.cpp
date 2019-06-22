#include "Graph.h"
#include "Dijkstra.h"
#include "Node.h"
#include "Edge.h"
#include <iostream>
#include <QPoint>
#include <QtGui>
#include <QtLabWorks.h>
#include "graphwidget.h"
#include "graphwidget.cpp"
#include "rasterwindow.h"

int main(int argc, char *argv[])
{
	WeightedDirectedGraph graph;
	for (size_t i = 0; i < 7; i++)
	{
		graph.AddVertex(Node(i+1));
	}
	
	graph.AddEdge(Edge(Node(1), Node(7), 1));
	graph.AddEdge(Edge(Node(7), Node(6), 2));
	graph.AddEdge(Edge(Node(6), Node(5), 3));
	graph.AddEdge(Edge(Node(4), Node(5), 3));
	graph.AddEdge(Edge(Node(4), Node(3), 9));
	graph.AddEdge(Edge(Node(1), Node(3), 18));
	graph.AddEdge(Edge(Node(1), Node(4), 5));
	graph.AddEdge(Edge(Node(1), Node(5), 10));
	graph.AddEdge(Edge(Node(5), Node(7), 4));

	QApplication app(argc, argv);

	QtLabWorks mainWin(graph, nullptr);
	mainWin.show();

	return app.exec();
}