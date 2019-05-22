#include <QApplication>
#include "ellipsetest.h"

#ifdef _WIN32
  #pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#endif
int main(int argc, char** argv)
{
  QApplication app(argc, argv);
  EllipseTest et;
  et.show();
  return app.exec();
}
