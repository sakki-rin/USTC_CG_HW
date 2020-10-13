#include "ViewWidget.h"

ViewWidget::ViewWidget(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	draw_status_ = false;
	shape_ = NULL;
	type_ = Shape::kDefault;
}

ViewWidget::~ViewWidget()
{
	for (size_t i = 0; i < shape_list_.size(); i++)
	{
		if (shape_list_[i] != NULL)
		{
			delete shape_list_[i];
			shape_list_[i] = NULL;
		}
	}
}

void ViewWidget::setLine()
{
	type_ = Shape::kLine;
}

void ViewWidget::setRect()
{
	type_ = Shape::kRect;
}

void ViewWidget::setEllipse()
{
	type_ = Shape::kEllipse;
}

void ViewWidget::setPolygon()
{
	type_ = Shape::kPolygon;
}

void ViewWidget::setFreehand()
{
	type_ = Shape::kFreehand;
}

void ViewWidget::Undo()
{
	if (shape_list_.size()!=0)
	{
		delete shape_list_.back();
		shape_list_.back() = NULL;
		shape_list_.pop_back();
	}
	update();
}

void ViewWidget::mousePressEvent(QMouseEvent* event)
{
	if (Qt::LeftButton == event->button())
	{
		switch (type_)
		{
		case Shape::kLine:
			shape_ = new Line();
			break;
		case Shape::kDefault:
			break;

		case Shape::kRect:
			shape_ = new Rect();
			break;

		case Shape::kEllipse:
			shape_ = new Ellip();
			break;

		case Shape::kPolygon:
			draw_status_ = true;
			//shape_ = new Poly(poly_points); //每次press都会new一个
			start_point_ = end_point_ = event->pos();
			poly_points.push_back(event->pos());
			break;

		case Shape::kFreehand:
			draw_status_ = true;
			//shape_ = new Freehand(free_points);
			start_point_ = end_point_ = event->pos();
			free_points.push_back(event->pos());
			break;

		default:
			break;
		}

		if (shape_ != NULL)
		{
			draw_status_ = true;
			start_point_ = end_point_ = event->pos();
			shape_->set_start(start_point_);
			shape_->set_end(end_point_);
		}
	}
	update();
}

void ViewWidget::mouseMoveEvent(QMouseEvent* event)
{
	if (draw_status_ && shape_ != NULL)
	{
		end_point_ = event->pos();
		shape_->set_end(end_point_);
	}
	if (draw_status_ && type_ == Shape::kPolygon)
	{
		setMouseTracking(true);
		end_point_ = event->pos();
	}
	if (draw_status_ && type_ == Shape::kFreehand)
	{
		setMouseTracking(false);
		free_points.push_back(event->pos());
	}
	update();
}

void ViewWidget::mouseReleaseEvent(QMouseEvent* event)
{
	if (shape_ != NULL)
	{
		draw_status_ = false;
		shape_list_.push_back(shape_);
		shape_ = NULL;
	}
	if (draw_status_ && type_ == Shape::kPolygon)
	{
		poly_points.push_back(end_point_);
		if (Qt::RightButton == event->button())
		{
			draw_status_ = false;
			shape_ = new Poly(poly_points);
			shape_list_.push_back(shape_);
			shape_ = NULL;
			poly_points.clear();
		}
	}
	if (draw_status_ && type_ == Shape::kFreehand)
	{
		draw_status_ = false;
		shape_ = new Freehand(free_points);
		shape_list_.push_back(shape_);
		shape_ = NULL;
		free_points.clear();
	}
	update();
}

void ViewWidget::paintEvent(QPaintEvent*)
{
	//每次update都绘制shape_list_
	QPainter painter(this);

	for (int i = 0; i < shape_list_.size(); i++)
	{
		shape_list_[i]->Draw(painter);
	}

	if (shape_ != NULL) {
		shape_->Draw(painter);
	}
	if (draw_status_ && type_ == Shape::kPolygon)
	{
		painter.drawLine(poly_points.back(), end_point_);
		painter.drawPolyline(poly_points);
	}
	if(draw_status_ && type_== Shape::kFreehand)
	{
		painter.drawPolyline(free_points);
	}

	update();
}
