#include "sendwindow.h"
#include "ui_sendwindow.h"

#include <QUdpSocket>
#include <QDebug>
#include <QMessageBox>

sendWindow::sendWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::sendWindow)
{
    ui->setupUi(this);
}

sendWindow::~sendWindow()
{
    delete ui;
}

#include <iostream>

void sendWindow::on_send_pushButton_clicked()
{
  int nrepeat = ui->repeat_spinBox->value();
      QByteArray bitstream = QByteArray::fromHex(ui->msg_lineEdit->text().toLocal8Bit());
      QByteArray head = QByteArray::fromHex(QString("82 98 98 40 40 40 E0 A8 8A A6 A8 40 40 61 03 F0").toLocal8Bit());
      QUdpSocket socket;

      socket.connectToHost("localhost", 5252);
      //teste de conectividade
      if(!socket.waitForConnected(1000)){
        QMessageBox::warning(this, "WARNING", "Falha ao tentar se conectar ao servidor!");
        return;
      }

      bitstream.push_front(head);
      for(int i = 0; i < nrepeat+1; i++)
      {
        socket.write(bitstream);
        socket.waitForBytesWritten();
      }
      socket.close();
}

void sendWindow::on_msg_lineEdit_returnPressed()
{
    on_send_pushButton_clicked();
}
