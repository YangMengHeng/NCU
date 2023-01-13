#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_START_clicked()
{
    this->hide();
    emit StartGame();
}

void MainWindow::on_HELP_clicked()
{
    QString HelpTitle = "游戏助手";
    QMessageBox *QM= new QMessageBox;
    QString Help = {"贪吃蛇是一款经典的小游戏，本游戏采用C++高级程序语言，搭配第三方类库Qt，进行编写。\n由于编者水平有限，仅仅只能实现一些基本功能，如有不足之处恳请谅解！\n操作方式：利用键盘上的上下左右键盘键控制蛇头的方向进行移动，随着吃的食物越来越多，一个食物相当于十分，分数到达一定程度需要晋级，随着等级越来越来高，移动速度也会越来越快，同时黑色毒药会越来越多，黑色围墙也会越来越多，因此游戏难度越来越高，不过有一定上限，同时本游戏还配有游戏历史得分情况，便于大家挑战自我！其余更多敬请各位玩家自行探索！\n注意：绿色方块代表蛇头，蓝色方块代表蛇身,红色方块代表食物!"};
    QM->information(this, HelpTitle, Help, QMessageBox::Ok, QMessageBox::NoButton);
}
