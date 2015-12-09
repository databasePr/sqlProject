#include "Login.h"
#include "QApplication"

Login::Login(QWidget *parent):
    QDialog(parent)
{
    roleOfUser = new QComboBox;
    roleOfUser->addItem(tr("系统管理员"));
    roleOfUser->addItem(tr("普通用户"));

    titleLabel = new QLabel;
    titleLabel->setText(tr("软件学院科研管理系统"));

    userNameLabel = new QLabel;
    userNameLabel->setText(tr("用户名："));

    passWordLabel = new QLabel;
    passWordLabel->setText(tr("密码："));

    userNameEdit = new QLineEdit;

    passWordEdit = new QLineEdit;
    passWordEdit->setEchoMode(QLineEdit::Password);

    loginButton = new QPushButton;
    loginButton->setText(tr("登录"));
    loginButton->setShortcut(Qt::Key_Enter);
    connect(loginButton , SIGNAL(clicked()) , this , SLOT(loginButtonClicked()));

    quitButton = new QPushButton;
    quitButton->setText(tr("退出"));
    connect(quitButton , SIGNAL(clicked()) , this, SLOT(quitButtonClicked()));


    //账号密码布局
    userGridLayout = new QGridLayout;
    userGridLayout->addWidget(userNameLabel , 0 , 0);
    userGridLayout->addWidget(userNameEdit , 0 , 1);
    userGridLayout->addWidget(passWordLabel , 1 , 0);
    userGridLayout->addWidget(passWordEdit , 1 , 1);

    titleHBoxLayout = new QHBoxLayout;
    titleHBoxLayout->addWidget(roleOfUser , 1);
    titleHBoxLayout->addWidget(titleLabel , 2);

    buttonHBoxLayout = new QHBoxLayout;
    buttonHBoxLayout->addWidget(loginButton);
    buttonHBoxLayout->addWidget(quitButton);

    wholeVBoxLayout = new QVBoxLayout;
    wholeVBoxLayout->addLayout(titleHBoxLayout);
    wholeVBoxLayout->addLayout(userGridLayout);
    wholeVBoxLayout->addLayout(buttonHBoxLayout);

    this->setLayout(wholeVBoxLayout);
    this->resize(350 , 150);
    this->setWindowTitle(tr("软件学院科研管理"));
    this->setWindowFlags(windowFlags()|Qt::WindowMaximizeButtonHint);
    this->setWindowFlags(windowFlags()|Qt::WindowMinimizeButtonHint);
}

Login::~Login()
{

}

void Login::loginButtonClicked()
{
    if((userNameEdit->text() == tr("tang")) && (passWordEdit->text() == tr("123456")))
    {
        accept();
    }
    else if((userNameEdit->text() == NULL) && (passWordEdit->text() != NULL))
    {
        QMessageBox::warning(this , tr("提示") , ("请输入用户名！") , QMessageBox::Ok);
    }
    else if((passWordEdit->text() == NULL) && (userNameEdit->text() != NULL))
    {
        QMessageBox::warning(this , tr("提示") , ("请输入密码！") , QMessageBox::Ok);
    }
    else if((userNameEdit->text() == NULL) && (passWordEdit->text() == NULL))
    {
        QMessageBox::warning(this , tr("提示") , ("请输入用户名和密码！") , QMessageBox::Ok);
    }
    else
    {
        QMessageBox::warning(this , tr("提示") , ("用户名或密码输入错误！") , QMessageBox::Ok);
        userNameEdit->clear();
        passWordEdit->clear();
        userNameEdit->setFocus();
    }
}

void Login::quitButtonClicked()
{
    this->close();
}

