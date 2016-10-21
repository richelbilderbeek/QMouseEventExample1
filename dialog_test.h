#ifndef DIALOG_TEST_H
#define DIALOG_TEST_H

#include <QtTest/QtTest>

class dialog_test : public QObject
{
    Q_OBJECT //!OCLINT

private slots:

  void mouse_event_left_should_have_an_effect();
  void mouse_event_right_should_have_no_effect_initially();
  void mouse_event_right_should_have_an_effect_after_left();
};

#endif // DIALOG_TEST_H
