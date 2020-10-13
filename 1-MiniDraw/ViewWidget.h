#pragma once

#include "ui_Viewwidget.h"

#include "Shape.h"
#include "Line.h"
#include "Rect.h"
#include "Ellipse.h"
#include "Polygon.h"
#include "Freehand.h"

#include <qevent.h>
#include <qpainter.h>
#include <QWidget>

#include <vector>

class ViewWidget : public QWidget
{
	Q_OBJECT

public:
	ViewWidget(QWidget* parent = 0);
	~ViewWidget();

private:
	Ui::ViewWidget ui;

private:
	bool draw_status_;
	QPoint start_point_;
	QPoint end_point_;
	Shape::Type type_;
	Shape* shape_;
	std::vector<Shape*> shape_list_;
	QVector<QPointF> poly_points;
	QVector<QPointF> free_points;


public:
	void mousePressEvent(QMouseEvent* event);
	void mouseMoveEvent(QMouseEvent* event);
	void mouseReleaseEvent(QMouseEvent* event);

public:
	void paintEvent(QPaintEvent*);
signals:
public slots:
	void setLine();
	void setRect();
	void setEllipse();
	void setPolygon();
	void setFreehand();
	void Undo();
};