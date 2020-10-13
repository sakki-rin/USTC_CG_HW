#pragma once
#include "Shape.h"

class Poly : public Shape
{
public:
	Poly();
	Poly(QVector<QPointF> points);
	~Poly();

	void Draw(QPainter& painter);

private:
	QVector<QPointF> poly_points;
};