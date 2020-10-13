#pragma once

#include "Shape.h"

class Freehand : public Shape
{
public:
	Freehand();
	Freehand(QVector<QPointF> points);
	~Freehand();

	void Draw(QPainter& painter);

private:
	QVector<QPointF> free_points;
};