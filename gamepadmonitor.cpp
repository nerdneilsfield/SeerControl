#include "gamepadmonitor.h"
#include <QtGamepad/QGamepad>

#include <QDebug>
#include <QLoggingCategory>

GamepadMonitor::GamepadMonitor(QObject *parent, QGamepadManager* gamepad_manager)
    : QObject(parent)
    , m_gamepad(nullptr)
{
    QLoggingCategory::setFilterRules(QStringLiteral("qt.gamepad.debug=true"));

    m_gamepad_manager = gamepad_manager;

    QList<int> gamepads;

    for(auto i=0; i < 20; i++){

        gamepads = m_gamepad_manager->connectedGamepads();
        if (gamepads.isEmpty()) {
            qDebug() << "Did not find any connected gamepads";
            if(i == 19){
                return;
            }
        } else {
            qDebug() << "Find!";
            i = 20;
        }
    }

    m_gamepad = new QGamepad(*gamepads.begin(), this);
    connect(m_gamepad, &QGamepad::axisLeftXChanged, this, [](double value){
        qDebug() << "Left X" << value;
    });
    connect(m_gamepad, &QGamepad::axisLeftYChanged, this, [](double value){
        qDebug() << "Left Y" << value;
    });
    connect(m_gamepad, &QGamepad::axisRightXChanged, this, [](double value){
        qDebug() << "Right X" << value;
    });
    connect(m_gamepad, &QGamepad::axisRightYChanged, this, [](double value){
        qDebug() << "Right Y" << value;
    });
    connect(m_gamepad, &QGamepad::buttonAChanged, this, [](bool pressed){
        qDebug() << "Button A" << pressed;
    });
    connect(m_gamepad, &QGamepad::buttonBChanged, this, [](bool pressed){
        qDebug() << "Button B" << pressed;
    });
    connect(m_gamepad, &QGamepad::buttonXChanged, this, [](bool pressed){
        qDebug() << "Button X" << pressed;
    });
    connect(m_gamepad, &QGamepad::buttonYChanged, this, [](bool pressed){
        qDebug() << "Button Y" << pressed;
    });
    connect(m_gamepad, &QGamepad::buttonL1Changed, this, [](bool pressed){
        qDebug() << "Button L1" << pressed;
    });
    connect(m_gamepad, &QGamepad::buttonR1Changed, this, [](bool pressed){
        qDebug() << "Button R1" << pressed;
    });
    connect(m_gamepad, &QGamepad::buttonL2Changed, this, [](double value){
        qDebug() << "Button L2: " << value;
    });
    connect(m_gamepad, &QGamepad::buttonR2Changed, this, [](double value){
        qDebug() << "Button R2: " << value;
    });
    connect(m_gamepad, &QGamepad::buttonSelectChanged, this, [](bool pressed){
        qDebug() << "Button Select" << pressed;
    });
    connect(m_gamepad, &QGamepad::buttonStartChanged, this, [](bool pressed){
        qDebug() << "Button Start" << pressed;
    });
    connect(m_gamepad, &QGamepad::buttonGuideChanged, this, [](bool pressed){
        qDebug() << "Button Guide" << pressed;
    });
}

GamepadMonitor::~GamepadMonitor()
{
    delete m_gamepad;
}
