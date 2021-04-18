#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QObject>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    double res = 0; //the result of previous calculations
    double operand = 0; //the last clicked number
    int currentOperator = 0;
    bool firstOperator = true;

    QVBoxLayout * vLayout;
    QVBoxLayout * vLayout1;
    QHBoxLayout * hLayout;
    QGridLayout * gLayout;

    QLineEdit * lineEdit1;
    QLineEdit * lineEdit2;

    QPushButton * buttons[10];
    QPushButton * dotButton;
    QPushButton * equalButton;
    QPushButton * divisionButton;
    QPushButton * starButton;
    QPushButton * plusButton;
    QPushButton * minusButton;
    QPushButton * deleteButton;

QPushButton* createButton(const QString &text);
QPushButton* createOperationButton(const QChar &text);

private slots:
    void numberClicked();
    void equalClicked();
    void operatorClicked();
    void deleteButtonClicked();
    void dotClicked();

};
#endif // MAINWINDOW_H
