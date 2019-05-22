#ifndef ELLIPSE_TEST_EXPORTS_H
#define ELLIPSE_TEST_EXPORTS_H

#include <QtCore/QtGlobal>

#ifdef _WIN32
  #ifdef ellipse_test_EXPORTS
    #define ELLIPSE_TEST_EXPORT __declspec(dllexport)
  #else
    #define ELLIPSE_TEST_EXPORT __declspec(dllimport)
  #endif
#else
  #define ELLIPSE_TEST_EXPORT
#endif

#endif /* ELLIPSE_TEST_EXPORTS_H */