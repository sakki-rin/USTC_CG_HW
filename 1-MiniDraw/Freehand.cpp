#include "Freehand.h"

Freehand::Freehand()
{

}

Freehand::Freehand(QVector<QPointF> points)
{
	free_points = points;
}

Freehand::~Freehand()
{

}

void Freehand::Draw(QPainter& painter)
{
	painter.drawPolyline (free_points);
}