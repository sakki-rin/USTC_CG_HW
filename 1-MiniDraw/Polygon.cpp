#include "Polygon.h"

Poly::Poly()
{

}

Poly::Poly(QVector<QPointF> points)
{
	poly_points = points;
}

Poly::~Poly()
{

}

void Poly::Draw(QPainter& painter)
{
	painter.drawPolygon(poly_points);
}