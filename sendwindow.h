#ifndef SENDWINDOW_H
#define SENDWINDOW_H

#include <QMainWindow>

namespace Ui {
class sendWindow;
}

class sendWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit sendWindow(QWidget *parent = nullptr);
    ~sendWindow();

private slots:
    void on_send_pushButton_clicked();

    void on_msg_lineEdit_returnPressed();

private:
    Ui::sendWindow *ui;
};

#endif // SENDWINDOW_H
