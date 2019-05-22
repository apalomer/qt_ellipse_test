#ifndef CUSTOMWIDGET_H
#define CUSTOMWIDGET_H

#include <QWidget>
#include "ellipse_test_exports.h"

class ELLIPSE_TEST_EXPORT CustomWidget : public QWidget
{
  Q_OBJECT
public:
  CustomWidget(QWidget* parent = nullptr);

protected:
  virtual void paintEvent(QPaintEvent* event);
};

#endif  // CUSTOMWIDGET_H
