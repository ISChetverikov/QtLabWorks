#include <QCoreApplication>
#include <QPushButton>
#include "graphwidget.h"
#include "rasterwindow.h"
#include "graph.h"
#include "edge.h"
#include "dijkstra.h"
#include <vector>
#include <math.h>
#include <string>
#include <cmath>

#define PI 3.14159265358979323
#define ARROW_ANGLE 0.25
#define ARROW_LENGTH 20
#define R 250
#define r 20
#define Height 600

using namespace std;

GraphVisualization::GraphVisualization(WeightedDirectedGraph &gr, vector<Edge> edges, Node start, Node end)
{
	setTitle("Graph");
	resize(Height, Height);
	_graph = gr;
	_edges = edges;
	_start = start;
	_end = end;
}

void GraphVisualization::render(QPainter* p)
{
	int N = _graph.GetVerticesNumber();
	vector<QPoint> qVertices(N);
	auto vertices = _graph.GetVertices();

	p->translate(width() / 2, height() / 2);

	
	for (int i = 0; i < N; i++)
	{
		qVertices[i] = QPoint(R * cos((2 * PI * i / N)), R * sin((2 * PI * i / N)));
	}

	QFont font = p->font();
	font.setPixelSize(35);
	p->setFont(font);
	p->setBrush(QColor(255, 0, 0));
	p->setPen(QColor(255, 255, 255));

	for (int i = 0; i < N; i++) {
		const QRect rectangle = QRect(qVertices[i].x() - r, qVertices[i].y() - r, 2 * r, 2 * r);

		if (vertices[i] == _start || vertices[i] == _end) {
			p->setBrush(QColor(0,0,255));
		}
		else {
			p->setBrush(QColor(255, 0, 0));
		}
		p->drawEllipse(qVertices[i], r, r);
		p->drawText(rectangle, Qt::AlignCenter, tr(std::to_string(vertices[i].GetValue()).c_str()));
	}

	for (int i = 0; i < N; i++)
	{
		vector<Edge> edges = _graph.GetEdges(vertices[i]);
		for (vector<Edge>::iterator eIt = edges.begin(); eIt != edges.end(); eIt++) {
			for (int j = 0; j < N; j++)
			{
				auto isHighlighted = false;
				for (size_t k = 0; k < _edges.size(); k++)
				{
					if (_edges[k].GetDestination() == eIt->GetDestination()
						&& _edges[k].GetSource() == eIt->GetSource())
						isHighlighted = true;
				}

				if (eIt->GetDestination() == vertices[j])
					drawArrow(p, qVertices[i], qVertices[j], std::to_string(eIt->GetWeight()).c_str(), isHighlighted);
			}
		}
	}
}
void GraphVisualization::drawArrow(QPainter *p, QPoint s, QPoint d, const char * text, bool isHighlighted)
{
	if (isHighlighted) {
		p->setBrush(QColor(0, 0, 255));
	}
	else {
		p->setBrush(QColor(255, 0, 0));
	}

	QPoint line = d - s;
	float angle = atan2(line.y(), line.x());

	QPoint delta((r + 1) * cos(angle), (r + 1) * sin(angle));
	QPoint newS = s + delta;
	QPoint newD = d - delta;

	p->drawLine(newS, newD);

	QPoint arr[3] = {
			newD,
			newD - QPoint(ARROW_LENGTH * cos(angle - ARROW_ANGLE), ARROW_LENGTH * sin(angle - ARROW_ANGLE)),
			newD - QPoint(ARROW_LENGTH * cos(angle + ARROW_ANGLE), ARROW_LENGTH * sin(angle + ARROW_ANGLE))
	};

	p->drawConvexPolygon(arr, 3);

	const QRect rectangle = QRect((newS + newD) / 2, QSize(40, 40));
	QFont font = p->font();
	font.setPixelSize(25);
	p->setFont(font);
	p->drawText(rectangle, Qt::AlignCenter, tr(text));
}