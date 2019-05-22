#define _USE_MATH_DEFINES
#include <cmath>

#include "ellipseitem.h"

#include <QDebug>
#include <QPainter>

void EllipseItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
  // Remove compilation warnings
  Q_UNUSED(option);
  Q_UNUSED(widget);

  // Set the pen and the brush
  painter->setPen(pen());
  painter->setBrush(brush());

  // Draw the arrow
  QPolygonF arrow;
  arrow.append(QPointF(0, -arrow_scale / 2));
  arrow.append(QPointF(arrow_scale * 3 / 4, 0));
  arrow.append(QPointF(0, arrow_scale / 2));
  arrow.append(QPointF(-arrow_scale / 4, 0));
  painter->save();
  painter->rotate(arrow_angle);
  painter->drawPolygon(arrow);
  painter->restore();

  // Draw the ellipse
  painter->save();
  painter->rotate(ellipse_rot);
  painter->drawEllipse(QPointF(0, 0), ellipse_x, ellipse_y);
  // Draw the x axis of the elipse in red
  QPen pn = pen();
  pn.setColor(Qt::red);
  painter->setPen(pn);
  painter->drawPie(QRectF(-ellipse_x, -ellipse_y, 2 * ellipse_x, 2 * ellipse_y), 0, 0);
  // Draw the y axis of the elipse in green
  pn.setColor(Qt::green);
  painter->setPen(pn);
  painter->drawPie(QRectF(-ellipse_x, -ellipse_y, 2 * ellipse_x, 2 * ellipse_y), 90 * 16, 0);
  // Draw the arrow axis in blue
  pn.setColor(Qt::blue);
  painter->setPen(pn);
  QBrush brs = brush();
  QColor c = Qt::blue;
  c.setAlpha(50);
  brs.setColor(c);
  brs.setStyle(Qt::SolidPattern);
  painter->setBrush(brs);
  double angle = arrow_angle - ellipse_rot;
  double angle_ellipse_0 = atan2(sin((angle + angle_aperture_2_) * M_PI / 180) * ellipse_x,
                                 cos((angle + angle_aperture_2_) * M_PI / 180) * ellipse_y) *
                           180.0 / M_PI;
  double angle_ellipse_1 = atan2(sin((angle - angle_aperture_2_) * M_PI / 180) * ellipse_x,
                                 cos((angle - angle_aperture_2_) * M_PI / 180) * ellipse_y) *
                           180.0 / M_PI;
  double angle_spawn = angle_ellipse_1 - angle_ellipse_0;
  if (angle_spawn > 0)
  {
    angle_spawn = angle_spawn - 360;
  }
  painter->drawPie(QRectF(-ellipse_x, -ellipse_y, 2 * ellipse_x, 2 * ellipse_y), -(angle_ellipse_0)*16,
                   -angle_spawn * 16);
  painter->restore();
}

QRectF EllipseItem::boundingRect() const
{
  double mx = std::max(ellipse_x, std::max(ellipse_y, arrow_scale * 3 / 4));
  return QRectF(-mx, -mx, 2 * mx, 2 * mx);
}
