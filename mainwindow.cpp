#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDoubleValidator>
#include <QKeyEvent>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->lineEdit1->setPlaceholderText("yaw");
    ui->lineEditx1->setPlaceholderText("x");
    ui->lineEditz1->setPlaceholderText("z");

    ui->lineEdit2->setPlaceholderText("yaw");
    ui->lineEditx2->setPlaceholderText("x");
    ui->lineEditz2->setPlaceholderText("z");


    connect(ui->lineEdit1, &QLineEdit::returnPressed, this, [this]() {
        ui->lineEditx1->setFocus();
    });
    connect(ui->lineEditx1, &QLineEdit::returnPressed, this, [this]() {
        ui->lineEditz1->setFocus();
    });
    connect(ui->lineEditz1, &QLineEdit::returnPressed, this, [this]() {
        ui->pushButton1->click();
    });

    connect(ui->lineEdit2, &QLineEdit::returnPressed, this, [this]() {
        ui->lineEditx2->setFocus();
    });
    connect(ui->lineEditx2, &QLineEdit::returnPressed, this, [this]() {
        ui->lineEditz2->setFocus();
    });
    connect(ui->lineEditz2, &QLineEdit::returnPressed, this, [this]() {
        ui->pushButton2->click();
    });


    QDoubleValidator *validator = new QDoubleValidator(-180, 180, 15, this);
    QDoubleValidator *validator2 = new QDoubleValidator(-10000000, 10000000, 15, this);
    validator->setNotation(QDoubleValidator::StandardNotation);
    validator->setLocale(QLocale::c());
    validator2->setNotation(QDoubleValidator::StandardNotation);
    validator2->setLocale(QLocale::c());

    ui->lineEdit1->setValidator(validator);
    ui->lineEdit2->setValidator(validator);
    ui->lineEditx1->setValidator(validator2);
    ui->lineEditz1->setValidator(validator2);
    ui->lineEditx2->setValidator(validator2);
    ui->lineEditz2->setValidator(validator2);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton1_clicked()
{
    QString Sdegree1 = ui->lineEdit1->text();
    QString Sx1 = ui->lineEditx1->text();
    QString Sz1 = ui->lineEditz1->text();
    QLocale locale = QLocale::c();
    x1 = Sx1.toDouble();
    z1 = Sz1.toDouble();
    degree1 = Sdegree1.toDouble();
    ui->labelLeft->setText(QString::number(leftDegreeOverflow(degree1)));
    ui->labelRight->setText(QString::number(rightDegreeOverflow(degree1)) + " or");
    ui->lineEdit2->setFocus();
}


void MainWindow::on_pushButton2_clicked()
{
    QString Sdegree2 =  ui->lineEdit2->text();
    QString Sx2 = ui->lineEditx2->text();
    QString Sz2 = ui->lineEditz2->text();
    QLocale locale = QLocale::c();
    x2 = Sx2.toDouble();
    z2 = Sz2.toDouble();
    degree2 = Sdegree2.toDouble();
    calculateCoordinatesDistance();
    ui->labelDistance->setText(QString::number((int)calculateStrongholdDistance(abs(degree1-degree2))));
    calculateOverworldCoordinates();
    ui->labelOverworld->setText(QString::number((int)overworldX) + " ; " + QString::number((int)overworldZ));
    ui->labelNether->setText(QString::number((int)overworldX/8) + " ; " + QString::number((int)overworldZ/8));

}

