#define _USE_MATH_DEFINES
#include <cmath>

#include "customwidget.h"
#include <QPainter>

CustomWidget::CustomWidget(QWidget *parent) : QWidget(parent)
{
}

void CustomWidget::paintEvent(QPaintEvent *event)
{
  Q_UNUSED(event);
  QPainter painter(this);

  // Move painter to center
  painter.translate(width() / 2, height() / 2);

  // Get minimum size
  double sz = std::min(width() / 2, height() / 2);

  // Display circle
  painter.drawEllipse(QPointF(0.0, 0.0), sz, sz);

  // Display 45º
  painter.drawPie(QRectF(-sz, -sz, 2 * sz, 2 * sz), 45 * 16, 0);

  // Display 135º
  painter.drawPie(QRectF(-sz, -sz, 2 * sz, 2 * sz), 135 * 16, 0);

  // Change color
  painter.setPen(QPen(Qt::red));

  // Display ellipse
  painter.drawEllipse(QPointF(0.0, 0.0), sz, sz / 2);

  // Display 45º
  painter.drawPie(QRectF(-sz, -sz / 2, 2 * sz, sz), 45 * 16, 0);

  // Display 135º
  painter.drawPie(QRectF(-sz, -sz / 2, 2 * sz, sz), 135 * 16, 0);

  // Change color
  painter.setPen(QPen(Qt::blue));

  // Display real 45º on ellipse
  double ang_real_45 = atan2(sin(45 * M_PI / 180) * sz, cos(45 * M_PI / 180) * sz / 2) * 180.0 / M_PI;
  painter.drawPie(QRectF(-sz, -sz / 2, 2 * sz, sz), ang_real_45 * 16, 0);

  // Display real 135 on ellipse
  double ang_real_135 = atan2(sin(135 * M_PI / 180) * sz, cos(135 * M_PI / 180) * sz / 2) * 180.0 / M_PI;
  painter.drawPie(QRectF(-sz, -sz / 2, 2 * sz, sz), ang_real_135 * 16, 0);
}
