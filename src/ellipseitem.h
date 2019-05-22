#ifndef ELLIPSEITEM_H
#define ELLIPSEITEM_H

#include <QAbstractGraphicsShapeItem>
#include "ellipse_test_exports.h"

class ELLIPSE_TEST_EXPORT EllipseItem : public QAbstractGraphicsShapeItem
{
public:
  double ellipse_x;
  double ellipse_y;
  double ellipse_rot;
  double arrow_angle;
  double arrow_scale;
  double angle_aperture_2_;

  virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
  virtual QRectF boundingRect() const;
};

#endif  // ELLIPSEITEM_H
