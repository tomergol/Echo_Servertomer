#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include <QString>
#include "qstring.h"
#include <string>
#include "string.h"
Client *c;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    c->connect_server("127.0.0.1",3939);
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_label_linkActivated(const QString &link)
{
    ui->connect_label->setText(link);
}

void MainWindow::on_Send_butt_clicked()
{
    c->send_Massage(ui->massage_line->text().toStdString());
    ui->client_label->setText("client: "+ui->massage_line->text());
    ui->massage_line->clear();
    string s = c->resvv_massage();
    QString qs;
    qs = QString::fromStdString(s);
    ui->server_label->setText(qs);
}
