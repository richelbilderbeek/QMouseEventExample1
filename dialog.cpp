#include "dialog.h"
#include <QKeyEvent>
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::Dialog)
{
  ui->setupUi(this);
}

Dialog::~Dialog()
{
  delete ui;
}

QString Dialog::text() const noexcept
{
  return ui->label->text();
}

void Dialog::mousePressEvent(QMouseEvent * event)
{

  if (ui->label->text() == "Click left" && event->button() == Qt::LeftButton)
  {
    ui->label->setText("Click right");
    event->setAccepted(true);
    return;
  }
  if (ui->label->text() == "Click right" && event->button() == Qt::RightButton)
  {
    ui->label->setText("Click left");
    event->setAccepted(true);
    return;
  }
}
