#include "snake.h"
#include "ui_snake.h"
#include<ctime>
#include<QFile>
#include<QDir>
#include<QTextStream>
#include<QTextDocument>
#include<QTextBlock>
#include<QDataStream>
#include<QString>
#include<windows.h>

snake::snake(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::snake)
{
    ui->setupUi(this);
    this->IsRun = false;
    this->IsOver = false;
    this->time = new QTimer;
    this->Score = 0;
    this->Level = 1;
    this->Sign = false;
    this->Rank(0);
    //this->Ini();
}

snake::~snake()
{
    delete time;
    delete ui;
}

void snake::Ini()
{
    for(int i = 0; i < 5; i++)
        {
            rank[i] = 0;
        }
    QString t = "No.";
    char a = '*';
    char w[5] = {'1', '2', '3', '4', '5'};
    QString temp[5];
    for(int i = 1; i <= 5; i++)
    {
        temp[i - 1] = t + w[i - 1] + a + QString::number(rank[i - 1]) + "grade";
    }
    QFile file("Rank.txt");
    QFile File("Score.txt");
    file.open(QIODevice::WriteOnly);
    File.open(QIODevice::WriteOnly);
    QDataStream WriteR(&file);
    QDataStream WriteS(&File);

    for(int i = 0; i < 5; i++)
    {
        WriteR << temp[i];
        WriteS << rank[i];
    }

    file.close();
    File.close();
    ui->FIRST->setText(temp[0]);
    ui->SECOND->setText(temp[1]);
    ui->THIRD->setText(temp[2]);
    ui->FORTH->setText(temp[3]);
    ui->FIFTH->setText(temp[4]);
}

bool snake::IsEat()
{
    if(Snake[0] == Food)
    {
    switch(Direction)
    {
    case 1:
    {
        if(Snake.last().x() < Snake.begin()->x())
        {
            QRect RECT(Snake.last().x() - 20, Snake.last().y(), 20, 20);
            Snake.append(RECT);
        }
        else if(Snake.last().x() > Snake.begin()->x())
        {
            QRect RECT(Snake.last().x() + 20, Snake.last().y(), 20, 20);
            Snake.append(RECT);
        }
        else
        {
            QRect RECT(Snake.last().x(), Snake.last().y() + 20, 20, 20);
            Snake.append(RECT);
        }

        break;
    }
    case 2:
    {
        if(Snake.last().x() < Snake.begin()->x())
        {
            QRect RECT(Snake.last().x() - 20, Snake.last().y(), 20, 20);
            Snake.append(RECT);
        }
        else if(Snake.last().x() > Snake.begin()->x())
        {
            QRect RECT(Snake.last().x() + 20, Snake.last().y(), 20, 20);
            Snake.append(RECT);
        }
        else
        {
            QRect RECT(Snake.last().x(), Snake.last().y() - 20, 20, 20);
            Snake.append(RECT);
        }

        break;
    }
    case 3:
    {
        if(Snake.last().y() < Snake.begin()->y())
        {
            QRect RECT(Snake.last().x(), Snake.last().y() - 20, 20, 20);
            Snake.append(RECT);
        }
        else if(Snake.last().y() > Snake.begin()->y())
        {
            QRect RECT(Snake.last().x(), Snake.last().y() + 20, 20, 20);
            Snake.append(RECT);
        }
        else
        {
            QRect RECT(Snake.last().x() + 20, Snake.last().y(), 20, 20);
            Snake.append(RECT);
        }

        break;
    }
    case 4:
    {
        if(Snake.last().y() < Snake.begin()->y())
        {
            QRect RECT(Snake.last().x(), Snake.last().y() - 20, 20, 20);
            Snake.append(RECT);
        }
        else if(Snake.last().y() > Snake.begin()->y())
        {
            QRect RECT(Snake.last().x(), Snake.last().y() + 20, 20, 20);
            Snake.append(RECT);
        }
        else
        {
            QRect RECT(Snake.last().x() - 20, Snake.last().y(), 20, 20);
            Snake.append(RECT);
        }

        break;
    }
    }
    this->Score += 10;

    return true;
    }

    return false;
}

bool snake::IsHitYourself()
{
    if(this->Snake.size() >= 4)
    {
        for(int i = 1; i < Snake.size(); i++)
        {
            if(Snake[0] == Snake[i])
            {
                IsOver = true;

                return true;
            }
        }
    }

    return false;
}

bool snake::IsHitBoundary()
{
    if(this->Level < 3)
    {
    if(this->Snake.data()->left() < 20 || this->Snake.data()->left() > 400 || this->Snake.data()->top() > 400 || this->Snake.data()->top() < 20)
    {
        IsOver = true;

        return true;
    }
    }
    switch(this->Level)
    {
    case 1:
    {
        if(this->Snake.data()->left() < 20 || this->Snake.data()->left() > 400 || this->Snake.data()->top() > 400 || this->Snake.data()->top() < 20)
        {
            IsOver = true;

            return true;
        }
        break;
    }
    case 2:
    {
        if(this->Snake.data()->left() < 20 || this->Snake.data()->left() > 400 || this->Snake.data()->top() > 400 || this->Snake.data()->top() < 20)
        {
            IsOver = true;

            return true;
        }
        break;
    }
    case 3:
    {
        if(this->Snake.data()->left() < 20 || this->Snake.data()->left() > 400 || this->Snake.data()->top() > 400 || this->Snake.data()->top() < 20
                || (this->Snake.data()->left() == 80 && this->Snake.data()->top() == 120)
                    || (this->Snake.data()->left() == 340 && this->Snake.data()->top() == 120))
        {
            IsOver = true;

            return true;
        }
        break;
    }
    case 4:
    {
        if(this->Snake.data()->left() < 20 || this->Snake.data()->left() > 400 || this->Snake.data()->top() > 400 || this->Snake.data()->top() < 20
                || (this->Snake.data()->left() == 80 && this->Snake.data()->top() == 120)
                    || (this->Snake.data()->left() == 340 && this->Snake.data()->top() == 120)
                || (this->Snake.data()->left() == 160 && this->Snake.data()->top() == 60)
                || (this->Snake.data()->left() == 160 && this->Snake.data()->top() == 360))
        {
            IsOver = true;

            return true;
        }
        break;
    }
    case 5:
    {
        if(this->Snake.data()->left() < 20 || this->Snake.data()->left() > 400 || this->Snake.data()->top() > 400 || this->Snake.data()->top() < 20
                || (this->Snake.data()->left() == 80 && this->Snake.data()->top() == 120)
                    || (this->Snake.data()->left() == 340 && this->Snake.data()->top() == 120)
                || (this->Snake.data()->left() == 160 && this->Snake.data()->top() == 60)
                || (this->Snake.data()->left() == 160 && this->Snake.data()->top() == 360)
                || (this->Snake.data()->left() >= 200 && this->Snake.data()->left() <= 260
                    && this->Snake.data()->top() >= 200 && this->Snake.data()->top() <= 260))
        {
            IsOver = true;

            return true;
        }
        break;
    }
    }

    return false;
}

bool snake::IsEatPoi()
{
    QVector<QRect>::iterator iter;

    for(iter = Poi.begin(); iter != Poi.end(); iter++)
    {
        if(*iter == Snake[0])
        {
            return true;
        }
    }

    return false;
}

QRect snake::CreateFood()
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    int x;
    int y;

    x = qrand()%(20);
    y = qrand()%(20);
    QRect rect(x * 20 + 20, y * 20 + 20, 20, 20);

    return rect;
}

void snake::InitiateSnake()
{
    switch (this->Level)
    {
    case 1:
    {
        Direction = 1;  //初始化方向向上
        this->IsRun = true;
        QRect rect(200, 200, 20, 20);
        QRect rect1(200,220, 20, 20);
        Snake.append(rect);
        Snake.append(rect1);
        this->Food = CreateFood();
        for(int i = 0; i < 3; i++)
        {
        this->Poi.append(this->CreatePoi(i+1));
        }
        ui->LCD_LEVEL->display(this->Level);
        ui->LCD_SCORE->display(this->Score);
        break;
    }
    case 2:
    {
        Poi.clear();
        for(int i = 0; i < 5; i++)
        {
        this->Poi.append(this->CreatePoi(i+1));
        }
        ui->LCD_LEVEL->display(this->Level);
        ui->LCD_SCORE->display(this->Score);
        break;
    }
    case 3:
    {
        Direction = 2;  //等级为3时，初始化方向向下
        QRect rect(200, 220, 20, 20);
        QRect rect1(200,200, 20, 20);
        Snake.append(rect);
        Snake.append(rect1);
        this->Poi.clear();
       for(int i = 0; i < 7; i++)
       {
           Poi.append(this->CreatePoi(i+1));
       }
        ui->LCD_LEVEL->display(this->Level);
        ui->LCD_SCORE->display(this->Score);
        break;
    }
    case 4:
    {
        Direction = 3;  //等级为4时，初始化方向向左
        QRect rect(200, 180, 20, 20);
        QRect rect1(200, 200, 20, 20);
        Snake.append(rect);
        Snake.append(rect1);
        this->Poi.clear();
        for(int i = 0; i < 8; i++)
        {
        this->Poi.append(this->CreatePoi(i+1));
        }
        ui->LCD_LEVEL->display(this->Level);
        ui->LCD_SCORE->display(this->Score);
    }
    case 5:
    {
        Direction = 4;  //等级为5时，初始化方向向右
        QRect rect(40, 200, 20, 20);
        QRect rect1(40, 220, 20, 20);
        Snake.append(rect);
        Snake.append(rect1);
        this->Poi.clear();
        for(int i = 0; i < 8; i++)
        {
        this->Poi.append(this->CreatePoi(i+1));
        }
        ui->LCD_LEVEL->display(this->Level);
        ui->LCD_SCORE->display(this->Score);
        break;
    }
    }
}

void snake::Speed(bool order)
{
    int od;

    if(order == true)
    {
        od = 1;
    }
    else
    {
        od = 0;
    }

    switch(od)
    {
    case 1:
    {
        this->Run();
        break;
    }
    case 0:
    {
        this->Over();
        break;
    }
    }
}

void snake::Speed(int o)
{
    this->time->setSingleShot(false);
    this->time->stop();
    this->time->start(o);
}

void snake::Run()
{
    this->time->setSingleShot(false);
    this->time->start(1000);  //等级为一时设置1S刷新一次

    connect(time, SIGNAL(timeout()), this, SLOT(SnakeUpdate()));
}

void snake::Over()
{
    this->time->stop();
}

QRect snake::CreatePoi(int a)
{
    qsrand(QTime(1,a,1).secsTo(QTime::currentTime()));
    int x;
    int y;

    x = qrand()%(20);
    y = qrand()%(20);
    QRect rect(x * 20 + 20, y * 20 + 20, 20, 20);

    return rect;
}

bool snake::CheckLevel(int s)
{
    static bool Curr[4] = {true, true, true, true};  //等级是否已经加一的标志,是为了等级只因为得分加一次

    ui->LCD_LEVEL->display(this->Level);
    ui->LCD_SCORE->display(this->Score);
    if(s == 30 && Curr[0] == true)
    {
        this->Level++;
        Curr[0] = false;
        return true;
    }
    else if(s == 70 && Curr[1] == true)
    {
        this->Level++;
        Curr[1] = false;
        return true;
    }
    else if(s == 120 && Curr[2] == true)
    {
        this->Level++;
        Curr[2] = false;
        return true;
    }
    else if(s == 180 && Curr[3] == true)
    {
        this->Level++;
        Curr[3] = false;
        return true;
    }

    return false;
}

void snake::Restart()
{
    this->Speed(false);
    QString temp = "很遗憾！蛇蛇死了！GAME OVER!";
    QMessageBox* QM = new QMessageBox;
    QM->information(this, "GameOver", temp);

    if(this->Score != 0)
    {
        this->Rank(1);
    }
    this->close();
}

void snake::SetChange(bool sign)
{
    this->Sign = sign;
}

void snake::ChangeDifficulty()
{
    QVector<QRect>::iterator Iter;

    switch(this->Level)
    {
    case 2:
    {
        this->Speed(800);
        break;
    }
    case 3:
    {
        Snake.clear();
        this->InitiateSnake();
        this->Speed(600);
        do
        {
            this->Food = this->CreateFood();
        }while(((Food.x() >= 80 && Food.x() <= 100) && (Food.y() >= 120 && Food.y() <= 300)) ||
               ((Food.x()>= 340 && Food.x() <= 360) && (Food.y() >= 120 && Food.y() <= 300)));
        break;
    }
    case 4:
    {
        Snake.clear();
        this->InitiateSnake();
        do
        {
            this->Food = this->CreateFood();
        }while(((Food.x() >= 80 && Food.x() <= 100) && (Food.y() >= 120 && Food.y() <= 300)) ||
               ((Food.x() >= 340 && Food.x() <= 360) && (Food.y() >= 120 && Food.y() <= 300)) ||
               ((Food.x() >= 160 && Food.x() <= 280) && (Food.y() >= 60 && Food.y() <= 60)) ||
               ((Food.x() >= 160 && Food.x() <= 280) && (Food.y() >= 360 && Food.y() <= 360)));
        break;
    }
    case 5:
    {
        Snake.clear();
        this->InitiateSnake();
        do
        {
            this->Food = this->CreateFood();
        }while(((Food.x() >= 80 && Food.x() <= 100) && (Food.y() >= 120 && Food.y() <= 300)) ||
               ((Food.x() >= 340 && Food.x() <= 360) && (Food.y() >= 120 && Food.y() <= 300)) ||
               ((Food.x() >= 160 && Food.x() <= 280) && (Food.y() >= 60 && Food.y() <= 60)) ||
               ((Food.x() >= 160 && Food.x() <= 280) && (Food.y() >= 360 && Food.y() <= 360)) |
               ((Food.x() >= 200 && Food.x() <= 260) && (Food.y() >= 200 && Food.y() <= 240)));
        break;
    }
    }
}

void snake::Rank(int order)//1写入,0读取,注意设计为读取同时显示
{
    switch(order)
    {
    case 1:
    {
        QFile file("Rank.txt");
        QFile File("Score.txt");
        file.open(QIODevice::WriteOnly);
        File.open(QIODevice::WriteOnly);
        QDataStream WriteR(&file);
        QDataStream WriteS(&File);
        int flag;
        int j[5];
        QString t = "No.";
        char a = '*';
        char w[5] = {'1', '2', '3', '4', '5'};
        flag = this->Compare();
        if(flag == 6)
        {
            break;
        }
        for(int i = 0 ; i < 5; i++)
        {
            j[i] = this->rank[i];
        }
        switch(flag)
        {
        case 0:
        {
            rank[0] = this->Score;
            for(int i = 1; i < 5; i++)
            {
                rank[i] = j[i - 1];
            }
            break;
        }
        case 1:
        {
            rank[1] = this->Score;
            for(int i = 2; i < 5; i++)
            {
                rank[i] = j[i - 1];
            }
            break;
        }
        case 2:
        {
            rank[2] = this->Score;
            for(int i = 3; i < 5; i++)
            {
                rank[i] = j[i - 1];
            }
            break;
        }
        case 3:
        {
            rank[3] = this->Score;
            for(int i = 4; i < 5; i++)
            {
                rank[i] = j[i - 1];
            }
            break;
        }
        case 4:
        {
            rank[4] = this->Score;
            break;
        }
        }
        QString temp[5];
        for(int i = 1; i <= 5; i++)
        {
            temp[i - 1] = t + w[i - 1] + a + QString::number(rank[i - 1]) + "grade";
        }
        for(int i = 0; i < 5; i++)
        {
            WriteR << temp[i];
            WriteS << rank[i];
        }

        file.close();
        File.close();
        break;
    }
    case 0:
    {
        QFile File("Rank.txt");
        QFile file("Score.txt");
        file.open(QIODevice::ReadOnly);
        File.open(QIODevice::ReadOnly);
        QDataStream ReadDataF(&file);
        QDataStream ReadData(&File);
        QString temp[5];
        for(int i = 0; i < 5; i++)
        {
            ReadData >> temp[i];
            ReadDataF >> rank[i];
        }
        ui->FIRST->setText(temp[0]);
        ui->SECOND->setText(temp[1]);
        ui->THIRD->setText(temp[2]);
        ui->FORTH->setText(temp[3]);
        ui->FIFTH->setText(temp[4]);

        file.close();
        File.close();
        break;
    }
    }
}

int snake::Compare()
{
    for(int i = 0 ; i < 5; i++)
    {
        if(this->Score > this->rank[i])
        {
            return i;
        }
    }

    return 6;
}

bool snake::CheckUp()
{
    QString temp = "恭喜得分已达晋级标准，进入下一关吗(共五关）？";
    QMessageBox* QM = new QMessageBox;
    QMessageBox::StandardButton sb = QM->information(this, "Game", temp, QMessageBox::Ok, QMessageBox::No);
    if(sb == QMessageBox::Ok)
    {
        return true;
    }

    this->Rank(1);
    return false;
}

void snake::SnakeUpdate()
{
    bool flag;
    QVector<QRect>::iterator Iter;

    switch(Direction)
    {
    case 1:
    {
        for(Iter = Snake.end() - 1; Iter != Snake.begin(); Iter--)
        {
            Iter->moveTo((Iter - 1)->x(), (Iter - 1)->y());
        }
        Snake[0].moveTo(Snake[0].x(), Snake[0].y() - 20);

        break;
    }
    case 2:
    {
        for(Iter = Snake.end() - 1; Iter != Snake.begin(); Iter--)
        {
            Iter->moveTo((Iter - 1)->x(), (Iter - 1)->y());
        }
        Snake[0].moveTo(Snake[0].x(), Snake[0].y() + 20);

        break;
    }
    case 3:
    {
        for(Iter = Snake.end() - 1; Iter != Snake.begin(); Iter--)
        {
            Iter->moveTo((Iter - 1)->x(), (Iter - 1)->y());
        }
        Snake[0].moveTo(Snake[0].x() - 20, Snake[0].y());

        break;
    }
    case 4:
    {
        for(Iter = Snake.end() - 1; Iter != Snake.begin(); Iter--)
        {
            Iter->moveTo((Iter - 1)->x(), (Iter - 1)->y());
        }
        Snake[0].moveTo(Snake[0].x() + 20, Snake[0].y());

        break;
    }
    }
    flag = this->IsHitBoundary();
    if(flag == true)
    {
        this->Restart();
    }
    flag = this->IsHitYourself();
    if(flag == true)
    {
        this->Restart();
    }
    flag = this->IsEatPoi();
    if(flag == true)
    {
        this->Restart();
    }
    flag = this->IsEat();
    if(flag == true)
    {
        this->Food = this->CreateFood();
        for(int i = 0; i < this->Poi.size(); i++)
        {
            Poi[i] = this->CreatePoi(i + 2);
        }
    }
    flag = this->CheckLevel(this->Score);
    if(flag == true)
    {
        bool Temp;

        Temp = this->CheckUp();
        if(Temp == true)
        {
        this->SetChange(true);
        }
        else exit(-1);
    }
    ui->LCD_LEVEL->display(this->Level);
    ui->LCD_SCORE->display(this->Score);

    update();
}

void snake::ReceiveGame()
{
    snake* S = new snake;
    S->show();
}

void snake::paintEvent(QPaintEvent *)
{
    QPainter painter(this);  //画笔
    QRect rect(20, 20, 400, 400);

    painter.fillRect(rect, Qt::yellow);

    for(int i = 1; i < 22; i++)
    {
        painter.drawLine(20, i * 20, 420, i * 20);
        painter.drawLine(i * 20, 20, i * 20, 420);
    }

    QFont font;
    font.setFamily("楷体");
    font.setItalic(true);
    font.setPointSize(16);
    painter.setFont(font);
    painter.setPen(Qt::black);
    painter.drawText(20, 470, "Created By 白哉の旗木");

    if(!IsRun)
    {
        this->Speed(true);
        this->InitiateSnake();
    }
    if(IsOver)
    {
        this->Speed(false);
    }

    QVector<QRect>::iterator iter;
    for(iter = Snake.begin() + 1; iter != Snake.end(); iter++)
    {
        painter.fillRect(*iter, Qt::blue);
        painter.drawRect(*iter);
    }
    painter.fillRect(*Snake.begin(), Qt::green);
    painter.drawRect(*Snake.begin());

    for(iter = Poi.begin(); iter != Poi.end(); iter++)
    {
        painter.fillRect(*iter, Qt::black);
        painter.drawRect(*iter);
    }

    switch(this->Level)
    {
    case 3:
    {
        QRect Temp[2];
        Temp[0].setX(80);
        Temp[0].setY(120);
        Temp[0].setHeight(200);
        Temp[0].setWidth(20);

        Temp[1].setX(340);
        Temp[1].setY(120);
        Temp[1].setHeight(200);
        Temp[1].setWidth(20);
        for(int i = 0; i < 2; i++)
        {
            painter.fillRect(Temp[i], Qt::black);
            painter.drawRect(Temp[i]);
        }
        break;
    }
    case 4:
    {
        QRect Temp[4];
        Temp[0].setX(80);
        Temp[0].setY(120);
        Temp[0].setHeight(200);
        Temp[0].setWidth(20);

        Temp[1].setX(340);
        Temp[1].setY(120);
        Temp[1].setHeight(200);
        Temp[1].setWidth(20);

        Temp[2].setX(160);
        Temp[2].setY(60);
        Temp[2].setHeight(20);
        Temp[2].setWidth(120);

        Temp[3].setX(160);
        Temp[3].setY(360);
        Temp[3].setHeight(20);
        Temp[3].setWidth(120);
        for(int i = 0; i < 4; i++)
        {
            painter.fillRect(Temp[i], Qt::black);
            painter.drawRect(Temp[i]);
        }
        break;
    }
    case 5:
    {
        QRect Temp[5];
        Temp[0].setX(80);
        Temp[0].setY(120);
        Temp[0].setHeight(200);
        Temp[0].setWidth(20);

        Temp[1].setX(340);
        Temp[1].setY(120);
        Temp[1].setHeight(200);
        Temp[1].setWidth(20);

        Temp[2].setX(160);
        Temp[2].setY(60);
        Temp[2].setHeight(20);
        Temp[2].setWidth(120);

        Temp[3].setX(160);
        Temp[3].setY(360);
        Temp[3].setHeight(20);
        Temp[3].setWidth(120);

        Temp[4].setX(200);
        Temp[4].setY(200);
        Temp[4].setHeight(60);
        Temp[4].setWidth(60);

        for(int i = 0; i < 5; i++)
        {
            painter.fillRect(Temp[i], Qt::black);
            painter.drawRect(Temp[i]);
        }
        break;
    }
    }

    if(this->Sign)
    {
        this->ChangeDifficulty();
        this->Sign = false;
    }

    painter.fillRect(this->Food, Qt::red);
    painter.drawRect(this->Food);

}

void snake::keyPressEvent(QKeyEvent *event)
{
    int flag;

    flag = event->key();
    switch(flag)
    {
    case Qt::Key_Up:Direction = 1;break;
    case Qt::Key_Down:Direction = 2;break;
    case Qt::Key_Left: Direction = 3; break;
    case Qt::Key_Right:Direction = 4; break;
    }
}

void snake::on_EXIT_clicked()
{
    this->Speed(false);
    QString temp = " 1秒后退出游戏！";
    QMessageBox* QM = new QMessageBox;
    QM->information(this, "GameDown", temp);

    if(this->Score != 0)
    {
        this->Rank(1);
    }
    Sleep(1000);
    this->close();
}
