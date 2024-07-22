#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QStack>
#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupConnections();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::onPushButtonClicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (button) {
        QString buttonText = button->text();
        if(buttonText == '=')
        {
            QString expr = ui->textEdit->toPlainText();
            expr.remove(QRegularExpression("\\s"));

            // Convert the infix expression to postfix
            QStack<QChar> operators;
            QString postfix;
            QChar prevChar;

            for (int i = 0; i < expr.length(); ++i) {
                QChar c = expr[i];
                if (c.isDigit() || c == '.') {
                    postfix += c;
                } else {
                    postfix += ' ';
                    while (!operators.isEmpty() && precedence(operators.top()) >= precedence(c)) {
                        postfix += operators.pop();
                        postfix += ' ';
                    }
                    operators.push(c);
                }
                prevChar = c;
            }

            while (!operators.isEmpty()) {
                postfix += ' ';
                postfix += operators.pop();
            }

            QStack<double> stack;
            QStringList tokens = postfix.split(' ', Qt::SkipEmptyParts);

            for (const QString &token : tokens) {
                if (token.toDouble()) {
                    stack.push(token.toDouble());
                } else if (token.length() == 1) {
                    double b = stack.pop();
                    double a = stack.pop();
                    switch (token[0].toLatin1()) {
                    case '+': stack.push(a + b); break;
                    case '-': stack.push(a - b); break;
                    case '*': stack.push(a * b); break;
                    case '/': stack.push(a / b); break;
                    }
                }
            }
            ui->textEdit->clear();
            ui->textEdit->setText(QString::number(stack.pop()));
        }
        else if(buttonText == 'C')
        {
            ui->textEdit->clear();
        }
        else
        {
            ui->textEdit->insertPlainText(buttonText);
        }
    }

}
void MainWindow::setupConnections()
{
    // Connect number buttons to the slot
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::onNumberButtonClicked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::onNumberButtonClicked);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::onNumberButtonClicked);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &MainWindow::onNumberButtonClicked);
    connect(ui->pushButton_5, &QPushButton::clicked, this, &MainWindow::onNumberButtonClicked);
    connect(ui->pushButton_6, &QPushButton::clicked, this, &MainWindow::onNumberButtonClicked);
    connect(ui->pushButton_7, &QPushButton::clicked, this, &MainWindow::onNumberButtonClicked);
    connect(ui->pushButton_8, &QPushButton::clicked, this, &MainWindow::onNumberButtonClicked);
    connect(ui->pushButton_9, &QPushButton::clicked, this, &MainWindow::onNumberButtonClicked);
    connect(ui->pushButton_10, &QPushButton::clicked, this, &MainWindow::onPushButtonClicked);
    connect(ui->pushButton_11, &QPushButton::clicked, this, &MainWindow::onPushButtonClicked);
    connect(ui->pushButton_12, &QPushButton::clicked, this, &MainWindow::onPushButtonClicked);
    connect(ui->pushButton_13, &QPushButton::clicked, this, &MainWindow::onPushButtonClicked);
    connect(ui->pushButton_14, &QPushButton::clicked, this, &MainWindow::onPushButtonClicked);
    connect(ui->pushButton_15, &QPushButton::clicked, this, &MainWindow::onPushButtonClicked);

}

void MainWindow::onNumberButtonClicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (button) {
        QString buttonText = button->text();
        ui->textEdit->insertPlainText(buttonText);
    }
}


int MainWindow::precedence(QChar op)
{
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}
