#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <GuiWidget.h>

class Login : public QDialog
{
    Q_OBJECT
public:
    explicit Login(QWidget *parent = 0);
    ~Login();

protected:
    QLabel         *titleLabel;
    QLabel         *userNameLabel;
    QLabel         *passWordLabel;

    QLineEdit      *userNameEdit;
    QLineEdit      *passWordEdit;

    QPushButton    *loginButton;
    QPushButton    *quitButton;

    QComboBox      *roleOfUser;

    QGridLayout    *userGridLayout;

    QHBoxLayout    *buttonHBoxLayout;
    QHBoxLayout    *titleHBoxLayout;

    QVBoxLayout    *wholeVBoxLayout;

protected slots:
    void loginButtonClicked();
    void quitButtonClicked();
};

#endif // LOGIN_H
