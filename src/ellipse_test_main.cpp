#include <QApplication>
#include "ellipsetest.h"

int main(int argc, char** argv)
{
  QApplication app(argc, argv);
  EllipseTest et;
  et.show();
  return app.exec();
}
