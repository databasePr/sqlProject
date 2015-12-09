#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QTextCodec>
#include <QDebug>
#include <GuiWidget.h>
#include <DataBase.h>

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void connectDataBase();

    QPushButton *connectDB;

    QLineEdit *inputUserName;
    QLineEdit *inputPassword;

    QVBoxLayout *mainLayout;

signals:

public slots:
    void connectDBClicked();

protected:

private:
    QString username;
    QString password;
};

#endif // MAINWINDOW_H
