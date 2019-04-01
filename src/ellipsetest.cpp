#include "ellipsetest.h"
#include "ui_ellipsetest.h"

#include <QDoubleSpinBox>

EllipseTest::EllipseTest(QWidget *parent) : QWidget(parent), ui(new Ui::EllipseTest)
{
  // Set up interface
  ui->setupUi(this);

  // Set up connections
  connect(ui->ellipse_x_doubleSpinBox, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this,
          &EllipseTest::valueChanged);
  connect(ui->ellipse_y_doubleSpinBox, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this,
          &EllipseTest::valueChanged);
  connect(ui->ellipse_rot_doubleSpinBox, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this,
          &EllipseTest::valueChanged);
  connect(ui->arrow_angle_doubleSpinBox, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this,
          &EllipseTest::valueChanged);
  connect(ui->arrow_scale_doubleSpinBox, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this,
          &EllipseTest::valueChanged);
  connect(ui->aperture_doubleSpinBox, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this,
          &EllipseTest::valueChanged);

  // Create scene
  ui->graphicsView->setScene(new QGraphicsScene);

  // Create item
  item_ = new EllipseItem;
  QPen pen = item_->pen();
  pen.setWidthF(0.2);
  item_->setPen(pen);
  ui->graphicsView->scene()->addItem(item_);

  // Update item
  valueChanged(0);

  // Fit in view
  ui->graphicsView->fitInView(item_->boundingRect(), Qt::KeepAspectRatio);
}

EllipseTest::~EllipseTest()
{
  delete ui;
}

void EllipseTest::valueChanged(double value)
{
  Q_UNUSED(value);
  item_->ellipse_x = ui->ellipse_x_doubleSpinBox->value();
  item_->ellipse_y = ui->ellipse_y_doubleSpinBox->value();
  item_->ellipse_rot = ui->ellipse_rot_doubleSpinBox->value();
  item_->arrow_angle = ui->arrow_angle_doubleSpinBox->value();
  item_->arrow_scale = ui->arrow_scale_doubleSpinBox->value();
  item_->angle_aperture_2_ = ui->aperture_doubleSpinBox->value() / 2.0;
  item_->update();
  ui->graphicsView->fitInView(item_->boundingRect(), Qt::KeepAspectRatio);
}
