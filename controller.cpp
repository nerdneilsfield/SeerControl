#include <QStyle>
#include <QCommonStyle>
#include <QDebug>
#include <QObject>

#include "controller.h"
#include "ui_controller.h"

Controller::Controller(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Controller)
{
    QCommonStyle style;
    ui->setupUi(this);

    ui->forwardButton->setIcon(style.standardIcon(QStyle::SP_ArrowUp));
    ui->backwardButton->setIcon(style.standardIcon(QStyle::SP_ArrowDown));
    ui->leftButton->setIcon(style.standardIcon(QStyle::SP_ArrowLeft));
    ui->rightButton->setIcon(style.standardIcon(QStyle::SP_ArrowRight));

   // connect(ui->forwardButton, &QPushButton::clicked, this, &Controller::on_forwardButton_clicked);
}

Controller::~Controller()
{
    delete ui;
}

void Controller::on_forwardButton_clicked()
{
    qDebug() << "forward button is pushed" << '\n';
}
