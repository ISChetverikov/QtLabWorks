#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtLabWorks.h"
#include "graph.h"
#include "graphwidget.h"

class QtLabWorks : public QMainWindow
{
	Q_OBJECT

public:
	QtLabWorks(WeightedDirectedGraph graph, GraphVisualization * graphVis, QWidget *parent = Q_NULLPTR);

public slots:
	void handleButton();
private:
	Ui::QtLabWorksClass ui;
	WeightedDirectedGraph _graph;
	GraphVisualization* _graphVis;
};
