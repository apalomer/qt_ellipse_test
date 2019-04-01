#ifndef ELLIPSETEST_H
#define ELLIPSETEST_H

#include <QWidget>
#include "ellipseitem.h"

namespace Ui
{
class EllipseTest;
}

class EllipseTest : public QWidget
{
  Q_OBJECT

public:
  explicit EllipseTest(QWidget *parent = nullptr);
  ~EllipseTest();
public slots:

  void valueChanged(double value);

private:
  Ui::EllipseTest *ui;

  EllipseItem *item_;
};

#endif  // ELLIPSETEST_H
