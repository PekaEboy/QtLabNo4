#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>

void showMessage(QString text) {
    QMessageBox msgb;
    msgb.setText(text);
    msgb.exec();
}

QTableWidgetItem* getItem(QTableWidget* tw, int i, int j) {
    QTableWidgetItem* item = tw->item(i, j);
    if(!item) {
        item = new QTableWidgetItem("0");
        tw->setItem(i, j, item);
    }
    return item;
}
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->twMatrix->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->twMatrix_2->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->twResult->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    connect(ui->pbAddCol, &QPushButton::clicked, this, &MainWindow::resetResult);
    connect(ui->pbAddRow, &QPushButton::clicked, this, &MainWindow::resetResult);
    connect(ui->pbAddCol_2, &QPushButton::clicked, this, &MainWindow::resetResult);
    connect(ui->pbAddRow_2, &QPushButton::clicked, this, &MainWindow::resetResult);
    connect(ui->pbRemoveCol, &QPushButton::clicked, this, &MainWindow::resetResult);
    connect(ui->pbRemoveRow, &QPushButton::clicked, this, &MainWindow::resetResult);
    connect(ui->pbRemoveCol_2, &QPushButton::clicked, this, &MainWindow::resetResult);
    connect(ui->pbRemoveRow_2, &QPushButton::clicked, this, &MainWindow::resetResult);
    connect(ui->twMatrix, &QTableWidget::itemChanged, this, &MainWindow::resetResult);
    connect(ui->twMatrix_2, &QTableWidget::itemChanged, this, &MainWindow::resetResult);
    ui->lblSIZE->setText("0x0");
    ui->lblSIZE2->setText("0x0");
    connect(ui->pbAddCol, &QPushButton::clicked, this, &MainWindow::SizeText);
    connect(ui->pbAddRow, &QPushButton::clicked, this, &MainWindow::SizeText);
    connect(ui->pbAddCol_2, &QPushButton::clicked, this, &MainWindow::SizeText);
    connect(ui->pbAddRow_2, &QPushButton::clicked, this, &MainWindow::SizeText);
    connect(ui->pbRemoveCol, &QPushButton::clicked, this, &MainWindow::SizeText);
    connect(ui->pbRemoveRow, &QPushButton::clicked, this, &MainWindow::SizeText);
    connect(ui->pbRemoveCol_2, &QPushButton::clicked, this, &MainWindow::SizeText);
    connect(ui->pbRemoveRow_2, &QPushButton::clicked, this, &MainWindow::SizeText);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pbAddRow_clicked()
{
    int rows = ui->twMatrix->rowCount();
    ui->twMatrix->setRowCount(rows + 1);
}


void MainWindow::on_pbAddCol_clicked()
{
    int rows = ui->twMatrix->columnCount();
    ui->twMatrix->setColumnCount(rows + 1);
}


void MainWindow::on_pbRemoveRow_clicked()
{
    int rows = ui->twMatrix->rowCount();
    if (rows > 0)
        ui->twMatrix->setRowCount(rows - 1);
}



void MainWindow::on_pbRemoveCol_clicked()
{
    int rows = ui->twMatrix->columnCount();
    if (rows > 0)
        ui->twMatrix->setColumnCount(rows - 1);
}


void MainWindow::on_pbShow_clicked()
{
    QString s = "";
    int rows = ui->twMatrix->rowCount();
    int cols = ui->twMatrix->columnCount();
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; j++) {
            s+=getItem(ui->twMatrix, i, j)->text() + "\t";
        }
        s += "\n";
    }
    showMessage(s);
}


void MainWindow::on_pbFill_clicked()
{
    int rows = ui->twMatrix->rowCount();
    int cols = ui->twMatrix->columnCount();
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; j++) {
            getItem(ui->twMatrix, i, j)->setText(QString::number(i*cols+j));
        }
    }
}


void MainWindow::on_pbRemoveRow_2_clicked()
{
    int rows = ui->twMatrix_2->rowCount();
    if (rows > 0)
        ui->twMatrix_2->setRowCount(rows - 1);
}


void MainWindow::on_pbAddRow_2_clicked()
{
    int rows = ui->twMatrix_2->rowCount();
    ui->twMatrix_2->setRowCount(rows + 1);
}


void MainWindow::on_pbRemoveCol_2_clicked()
{
    int rows = ui->twMatrix_2->columnCount();
    if (rows > 0)
        ui->twMatrix_2->setColumnCount(rows - 1);
}


void MainWindow::on_pbAddCol_2_clicked()
{
    int rows = ui->twMatrix_2->columnCount();
    ui->twMatrix_2->setColumnCount(rows + 1);
}


void MainWindow::on_pbShow_2_clicked()
{
    QString s = "";
    int rows = ui->twMatrix_2->rowCount();
    int cols = ui->twMatrix_2->columnCount();
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; j++) {
            s+=getItem(ui->twMatrix_2, i, j)->text() + "\t";
        }
        s += "\n";
    }
    showMessage(s);
}


void MainWindow::on_pbFill_2_clicked()
{
    int rows = ui->twMatrix_2->rowCount();
    int cols = ui->twMatrix_2->columnCount();
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; j++) {
            getItem(ui->twMatrix_2, i, j)->setText(QString::number(i*cols+j));
        }
    }
}


void MainWindow::on_pbPLUS_clicked()
{
    int rows = ui->twMatrix->rowCount();
    int cols = ui->twMatrix->columnCount();
    int rows2 = ui->twMatrix_2->rowCount();
    int cols2 = ui->twMatrix_2->columnCount();
    if(rows*cols*rows2*cols2 == 0) {
        showMessage("Ошибка! Отсутствует одна или две матрицы");
    } else if((rows==rows2) && (cols==cols2)) {
        ui->twResult->setColumnCount(cols);
        ui->twResult->setRowCount(rows);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; j++) {
                getItem(ui->twResult, i, j)->setText(QString::number(getItem(ui->twMatrix, i, j)->text().toDouble() + getItem(ui->twMatrix_2, i, j)->text().toDouble()));
            }
        }
    } else {
        showMessage("Ошибка! Матрицы должны иметь равные размеры");
    }
}


void MainWindow::on_pbMINUS_clicked()
{
    int rows = ui->twMatrix->rowCount();
    int cols = ui->twMatrix->columnCount();
    int rows2 = ui->twMatrix_2->rowCount();
    int cols2 = ui->twMatrix_2->columnCount();
    if(rows*cols*rows2*cols2 == 0) {
        showMessage("Ошибка! Отсутствует одна или две матрицы");
    } else if((rows==rows2) && (cols==cols2)) {
        ui->twResult->setColumnCount(cols);
        ui->twResult->setRowCount(rows);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; j++) {
                getItem(ui->twResult, i, j)->setText(QString::number(getItem(ui->twMatrix, i, j)->text().toDouble() - getItem(ui->twMatrix_2, i, j)->text().toDouble()));
            }
        }
    } else {
        showMessage("Ошибка! Матрицы должны иметь равные размеры");
    }
}


void MainWindow::on_pbCOMP_clicked()
{
    int rows = ui->twMatrix->rowCount();
    int cols = ui->twMatrix->columnCount();
    int rows2 = ui->twMatrix_2->rowCount();
    int cols2 = ui->twMatrix_2->columnCount();
    if(rows*cols*rows2*cols2 == 0) {
        showMessage("Ошибка! Отсутствует одна или две матрицы");
    } else if(rows2==cols) {
        ui->twResult->setColumnCount(cols2);
        ui->twResult->setRowCount(rows);
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols2; j++) {
                double s = 0;
                for(int k = 0; k<rows2; k++) {
                    s+=getItem(ui->twMatrix, i, k)->text().toDouble() * getItem(ui->twMatrix_2, k, j)->text().toDouble();
                }
                getItem(ui->twResult, i, j)->setText(QString::number(s));
            }
        }
    } else {
        showMessage("Ошибка! Столбец первого матрицы должна быть равна ряду второго матрицы");
    }
}

void MainWindow::resetResult() {
    ui->twResult->setColumnCount(0);
    ui->twResult->setRowCount(0);
}

void MainWindow::on_pbShow_3_clicked()
{
    QString s = "";
    int rows = ui->twResult->rowCount();
    int cols = ui->twResult->columnCount();
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; j++) {
            s+=getItem(ui->twResult, i, j)->text() + "\t";
        }
        s += "\n";
    }
    showMessage(s);
}

void MainWindow::SizeText() {
    ui->lblSIZE->setText(QString::number(ui->twMatrix->rowCount()) + "x" + QString::number(ui->twMatrix->columnCount()));
    ui->lblSIZE2->setText(QString::number(ui->twMatrix_2->rowCount()) + "x" + QString::number(ui->twMatrix_2->columnCount()));
}
