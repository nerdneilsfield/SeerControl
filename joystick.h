#ifndef JOYSTICK_H
#define JOYSTICK_H
#include <QObject>
#include <QTimer>

class QGamepad;

class joystick : public QObject
{
   Q_OBJECT
public:
    joystick(QObject *parent=nullptr);
    ~joystick();
private:
    QGamepad *m_gamepad;
};

#endif // JOYSTICK_H
