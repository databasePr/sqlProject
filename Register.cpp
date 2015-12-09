#include "Register.h"
#include <QDebug>

Register::Register(QWidget *parent) :
    QWidget(parent)
{
    /////////////////////////////////////用户注册信息
    QStringList user_Info = {
        "中文姓名：","英文姓名：",
        "性别：","系/中心：",
        "职称：","教学系列：",
        "科研管理系列：","实验室系列：",
        "工程系列：","职务：",
        "工号：","出生日期（如2000-01-01）：",
        "电子邮件地址：","移动电话：",
        "办公电话：","备注：",
        "照片："
    };
    ///////////////////////////////////////
    //注册界面所用布局们
    labelVBoxLayout = new QVBoxLayout;
    editVBoxLayout = new QVBoxLayout;
    wholeVBoxLayout = new QVBoxLayout;

    wholeHBoxLayout = new QHBoxLayout;
    userPictureLayout = new QHBoxLayout;
    situationHBoxLayout = new QHBoxLayout;

    sureButton = new QPushButton;
    sureButton->setText(tr("确定"));
    sureButton->setShortcut(Qt::Key_Enter);
//    connect

    quitButton = new QPushButton;
    quitButton->setText(tr("取消"));
    connect(quitButton , SIGNAL(clicked()) , this , SLOT(quitButtonClicked()));

    situationHBoxLayout->addWidget(sureButton);
    situationHBoxLayout->addWidget(quitButton);

    for(int i = 0 ; i < 16 ; i++)
    {
        userInformationLabel[i] = new QLabel;
        userInformationLabel[i]->setText(user_Info[i]);
        labelVBoxLayout->addWidget(userInformationLabel[i]);
        userInformationEdit[i] = new QLineEdit;
        editVBoxLayout->addWidget(userInformationEdit[i]);
    }
    userInformationLabel[16] = new QLabel;
    userInformationLabel[16]->setText(user_Info[16]);

    showPictureLabel = new QLabel;
    showPictureLabel->setHidden(true);

    addPictureButton = new QPushButton;
    addPictureButton->setText(tr("加载图片"));
    addPictureButton->setToolTip(tr("No"));
    connect(addPictureButton , SIGNAL(clicked()) , this , SLOT(addPictureButtonClicked()));

    userPictureLayout->addWidget(userInformationLabel[16]);
    userPictureLayout->addWidget(showPictureLabel);
    userPictureLayout->addWidget(addPictureButton);

    wholeHBoxLayout->addLayout(labelVBoxLayout);
    wholeHBoxLayout->addLayout(editVBoxLayout);

    wholeVBoxLayout->addLayout(wholeHBoxLayout);
    wholeVBoxLayout->addLayout(userPictureLayout);
    wholeVBoxLayout->addLayout(situationHBoxLayout , 10);
    this->setLayout(wholeVBoxLayout);
}

Register::~Register()
{

}

void Register::addPictureButtonClicked()
{
    QString filename;
    QImage *img;
    filename = QFileDialog::getOpenFileName(this,
                                            tr("Choose Picture"),
                                            "",
                                            tr("Images(*.png *.bmp *.jpg *.tif)"));
    if(filename.isEmpty())
    {
        return;
    }
    else
    {
        img = new QImage;
        if(!(img->load(filename)))
        {
            QMessageBox::information(this,
                                     tr("Filed"),
                                     tr("Filed!"));
            delete img;
            return;
        }
        showPictureLabel->setPixmap(QPixmap::fromImage(*img));
    }
    if(addPictureButton->toolTip() == "No")
    {
        showPictureLabel->setHidden(false);
        addPictureButton->setHidden(true);
    }
}

void Register::sureButtonClicked()
{

}

void Register::quitButtonClicked()
{
    this->close();
}

