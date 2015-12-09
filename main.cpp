#include <QApplication>
#include <MainWindow.h>
#include <Login.h>

int main(int argc , char *argv[])
{
    QApplication app(argc , argv);
    MainWindow *window = new MainWindow;
    Login      *loginWindow = new Login;
    loginWindow->show();
    if(loginWindow->exec() == QDialog::Accepted)
    {
        window->show();
        return app.exec();
    }
    else
        return 0;
}
