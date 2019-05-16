#include "controller.h"
//#include "joystick.h"
#include "gamepadmonitor.h"
#include <QApplication>
#include <QGamepad>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    do {

    a.processEvents();

    } while (QGamepadManager::instance()->connectedGamepads().isEmpty());


    QGamepadManager* gamepad_manager = QGamepadManager::instance();
    Controller w;
    GamepadMonitor m(nullptr, gamepad_manager);
    w.show();
    return a.exec();
}
