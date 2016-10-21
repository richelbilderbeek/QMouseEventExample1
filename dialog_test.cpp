#include "dialog_test.h"

#include <cassert>
#include "dialog.h"

void dialog_test::mouse_event_left_should_have_an_effect()
{
  Dialog d;
  QMouseEvent event_left(
    QMouseEvent::MouseButtonPress,
    d.geometry().center(),
    Qt::LeftButton,
    Qt::NoButton,
    Qt::NoModifier
  );
  event_left.setAccepted(false);
  d.mousePressEvent(&event_left);
  QVERIFY(event_left.isAccepted());
}

void dialog_test::mouse_event_right_should_have_no_effect_initially()
{
  Dialog d;
  QMouseEvent event_right(
    QMouseEvent::MouseButtonPress,
    d.geometry().center(),
    Qt::RightButton,
    Qt::NoButton,
    Qt::NoModifier
  );
  event_right.setAccepted(false);
  d.mousePressEvent(&event_right);
  QVERIFY(!event_right.isAccepted());
}

void dialog_test::mouse_event_right_should_have_an_effect_after_left()
{
  Dialog d;
  {
    QMouseEvent event_left(
      QMouseEvent::MouseButtonPress,
      d.geometry().center(),
      Qt::LeftButton,
      Qt::NoButton,
      Qt::NoModifier
    );
    event_left.setAccepted(false);
    d.mousePressEvent(&event_left);
    assert(event_left.isAccepted());
  }
  QMouseEvent event_right(
    QMouseEvent::MouseButtonPress,
    d.geometry().center(),
    Qt::RightButton,
    Qt::NoButton,
    Qt::NoModifier
  );
  event_right.setAccepted(false);
  d.mousePressEvent(&event_right);
  QVERIFY(event_right.isAccepted());
}
