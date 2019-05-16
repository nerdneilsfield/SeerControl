#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QMainWindow>

namespace Ui {
class Controller;
}

class Controller : public QMainWindow
{
    Q_OBJECT

public:
    explicit Controller(QWidget *parent = nullptr);
    ~Controller();

private slots:
    void on_forwardButton_clicked();

private:
    Ui::Controller *ui;
};

#endif // CONTROLLER_H
