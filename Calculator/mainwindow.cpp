#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::~MainWindow()
{

}

MainWindow::MainWindow(QWidget *parent): QWidget(parent)
{
    vLayout = new QVBoxLayout();

    vLayout1 = new QVBoxLayout();
    lineEdit1 = new QLineEdit();
    vLayout1->addWidget(lineEdit1);

    hLayout = new QHBoxLayout();
    deleteButton = new QPushButton("Delete");
    QObject::connect(deleteButton, SIGNAL(clicked()), this, SLOT(deleteButtonClicked()));
    lineEdit2 = new QLineEdit();
    hLayout->addWidget(deleteButton);
    hLayout->addWidget(lineEdit2);

    gLayout = new QGridLayout();
    for(int i = 0; i <10; ++i){
        buttons[i] = createButton(QString::number(i));
    }

    dotButton = new QPushButton(".");
    QObject::connect(dotButton, SIGNAL(clicked()), this, SLOT(dotClicked()));
    equalButton = new QPushButton("=");
    QObject::connect(equalButton, SIGNAL(clicked()), this, SLOT(equalClicked()));

    plusButton = createOperationButton('+');
    minusButton = createOperationButton('-');
    divisionButton = createOperationButton('/');
    starButton = createOperationButton('*');

    for(int i = 1; i < 10; ++i){
        int row = ((9 - i) / 3);
        int column = ((i - 1) % 3);
        gLayout->addWidget(buttons[i], row, column);
    }
    gLayout->addWidget(buttons[0],3,0);
    gLayout->addWidget(dotButton, 3, 1);
    gLayout->addWidget(equalButton, 3, 2);
    gLayout->addWidget(divisionButton, 0, 3);
    gLayout->addWidget(starButton, 1, 3);
    gLayout->addWidget(plusButton, 2, 3);
    gLayout->addWidget(minusButton, 3, 3);


    vLayout->addLayout(vLayout1);
    vLayout->addLayout(hLayout);
    vLayout->addLayout(gLayout);
    setLayout(vLayout);

}

QPushButton* MainWindow::createButton(const QString &text){
    QPushButton* button = new QPushButton(text);
    QObject::connect(button, SIGNAL(clicked()), this, SLOT(numberClicked()));
    return button;
}

QPushButton* MainWindow::createOperationButton(const QChar &text){
    QPushButton* button = new QPushButton(text);
    QObject::connect(button, SIGNAL(clicked()), this, SLOT(operatorClicked()));
    return button;
}

void MainWindow::numberClicked()
{
    QPushButton *clickedButton = qobject_cast<QPushButton*>(sender());
    int value = clickedButton->text().toInt();
    lineEdit1->setText(lineEdit1->text() + QString::number(value));
}

void MainWindow::dotClicked()
{
    lineEdit1->setText(lineEdit1->text() + dotButton->text());
}

void MainWindow::operatorClicked(){

    QPushButton *clickedButton = qobject_cast<QPushButton*>(sender()); //getting the object
    if (!clickedButton) return;

    //if there is no number in the input field -> return
    //it also occurs when we press the addition operator after =
    if (lineEdit1->text().isEmpty()) {
        //setting the current pressed operator
        QChar clickedOperator =  clickedButton->text().at(0);
        currentOperator = clickedOperator.toLatin1();
        return;
    }

    //if this is not the first operator pressed, then it also behaves like equal operator
    if(!firstOperator) {
        equalClicked();
        lineEdit1->setText("");
    }

    //setting the current pressed operator
    QChar clickedOperator =  clickedButton->text().at(0);
    currentOperator = clickedOperator.toLatin1();

    //if this is the first operator pressed, then we save the value of the number added before the operator was pressed
    if(firstOperator){
        res = lineEdit1->text().toDouble(); //the previous clicked number
        lineEdit1->setText("");
        firstOperator = false;
        qDebug() << "itt";
    }

}

void MainWindow::equalClicked()
{
    //the previous clicked number
    operand = lineEdit1->text().toDouble();

    //performing the operation
    switch(currentOperator){
        case 43:
        this->res += operand; break;
        case 45:
            this->res -= operand; break;
        case 42:
            this->res *= operand; break;
        case 47:
            this->res /= operand; break;
        default:
            break;
   }

   lineEdit2->setText(QString::number(this->res));
   lineEdit1->setText("");

}

void MainWindow::deleteButtonClicked(){
    res = 0.0;
    lineEdit1->setText("");
    lineEdit2->setText("");
    firstOperator = true;
}
