#ifndef REGISTER_H
#define REGISTER_H

#include <QWidget>
#include <GuiWidget.h>
#include <QImage>
#include <QFileDialog>

class Register : public QWidget
{
    Q_OBJECT
public:
    explicit Register(QWidget *parent = 0);
    ~Register();

protected:
    QLabel      *userInformationLabel[17];
    QLabel      *showPictureLabel;

    QLineEdit   *userInformationEdit[16];

    QPushButton *addPictureButton;
    QPushButton *sureButton;
    QPushButton *quitButton;

    QVBoxLayout *labelVBoxLayout;

    QVBoxLayout *editVBoxLayout;
    QVBoxLayout *wholeVBoxLayout;

    QHBoxLayout *situationHBoxLayout;
    QHBoxLayout *wholeHBoxLayout;
    QHBoxLayout *userPictureLayout;

protected slots:
    void addPictureButtonClicked();
    void sureButtonClicked();
    void quitButtonClicked();
};

#endif // REGISTER_H
