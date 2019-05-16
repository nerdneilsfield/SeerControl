#ifndef GAMEPADMONITOR_H
#define GAMEPADMONITOR_H

#include <QtCore/QObject>
#include <QtGamepad/QGamepad>
#include <QtCore/QTimer>

class QGamepad;

class GamepadMonitor : public QObject
{
    Q_OBJECT
public:
    explicit GamepadMonitor(QObject *parent = nullptr, QGamepadManager* gamepad_manager=nullptr);
    ~GamepadMonitor();

private:
    QGamepad *m_gamepad;
    QGamepadManager* m_gamepad_manager;
};

#endif // GAMEPADMONITOR_H
