#include "QtLabWorks.h"
#include <QMessageBox>
#include "graphwidget.h"
#include "graph.h"
#include <QWidget>

QtLabWorks::QtLabWorks(WeightedDirectedGraph graph, GraphVisualization* graphVis,  QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(handleButton()));
	_graphVis = graphVis;
	_graph = graph;
}

void QtLabWorks::handleButton()
{
	Dijkstra d = Dijkstra(_graph, Node(ui.spinBox->value()));
	
	if (_graphVis != nullptr) {
		_graphVis->destroy();
		delete _graphVis;
	}
	_graphVis = new GraphVisualization(_graph, d.GetPath(Node(ui.spinBox_2->value())), Node(ui.spinBox->value()), Node(ui.spinBox_2->value()));
	_graphVis->show();
}