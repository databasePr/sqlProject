#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
{
    inputUserName = new QLineEdit;

    inputPassword = new QLineEdit;
    inputPassword->setEchoMode(QLineEdit::Password);

    connectDB = new QPushButton;
    connectDB->setText(tr("连接数据库"));
    connectDB->setShortcut(Qt::Key_Enter);
    connect(connectDB , SIGNAL(clicked()) , this , SLOT(connectDBClicked()));

    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(inputUserName);
    mainLayout->addWidget(inputPassword);
    mainLayout->addWidget(connectDB);

    this->setLayout(mainLayout);
    this->layout()->setSizeConstraint(QLayout::SetFixedSize);
}

MainWindow::~MainWindow()
{

}

void MainWindow::connectDataBase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName(QString("DRIVER={SQL SERVER};"
                               "SERVER=%1;"
                               "DATABASE=%2;"
                               "UID=%3;"
                               "PWD=%4;").arg("NICK")
                       .arg("软件学院科研管理系统")
                       .arg(username)
                       .arg(password));

    if (!db.open())
    {

        QMessageBox::warning(0, qApp->tr("Cannot open database"),
                             db.lastError().databaseText(), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::about(this , tr("连接信息") , tr("连接成功"));
        qDebug()<<"Connect to Database Success!";
    }

//    QDialog *mainDialog = new QDialog;
    QTableView *tableView = new QTableView;
//    QHBoxLayout *layout = new QHBoxLayout;
//    layout->addWidget(tableView);
//    mainDialog->setLayout(layout);

//    QSqlQueryModel *model1 = new QSqlQueryModel;
//    model1->setQuery(QString("insert into %1(%2,%3,%4,%5,%6,%7,%8)"
//                             "values('%9')").arg(a1)
//                     .arg(a2));

    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery(QObject::tr("select * from 注册用户"));
    tableView->setModel(model);
    mainLayout->addWidget(tableView);
//    mainDialog->adjustSize();
//    mainLayout->addWidget(mainDialog);
}

void MainWindow::connectDBClicked()
{
    username = inputUserName->text();
    password = inputPassword->text();
    connectDataBase();
}

