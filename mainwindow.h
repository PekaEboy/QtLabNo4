#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void resetResult();
    void SizeText();
    void on_pbAddRow_clicked();

    void on_pbAddCol_clicked();

    void on_pbRemoveRow_clicked();

    void on_pbRemoveCol_clicked();

    void on_pbShow_clicked();

    void on_pbFill_clicked();

    void on_pbRemoveRow_2_clicked();

    void on_pbAddRow_2_clicked();

    void on_pbRemoveCol_2_clicked();

    void on_pbAddCol_2_clicked();

    void on_pbShow_2_clicked();

    void on_pbFill_2_clicked();

    void on_pbPLUS_clicked();

    void on_pbMINUS_clicked();

    void on_pbCOMP_clicked();

    void on_pbShow_3_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
