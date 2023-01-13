#ifndef SNAKE_H
#define SNAKE_H

#include <QWidget>
#include<QPainter>
#include<QRect>
#include<QPen>
#include<QLabel>
#include<QLCDNumber>
#include<QCommandLinkButton>
#include<QKeyEvent>
#include<QAction>
#include<QTimer>
#include<QTime>
#include<QMessageBox>
#include<QVector>
#include<QtGlobal>

namespace Ui {
class snake;
}

class snake : public QWidget
{
    Q_OBJECT

public:
    explicit snake(QWidget *parent = 0);
    ~snake();
    void Ini();  //记录初始化函数

    bool IsEat();  //是否吃到食物
    bool IsHitYourself();  //是否撞到自己
    bool IsHitBoundary();  //是否撞到墙
    bool IsEatPoi();  //是否吃到毒药
    QRect CreateFood();  //创造食物
    void InitiateSnake();  //初始化食物
    void Speed(bool order);  //移动速度，用定时器定时更新,根据输入的入参确定是否开启或者停止计时器
    void Speed(int o);  //重载移动速度函数，修改移动速度的函数Speed
    void Run();  //启动定时器
    void Over();  //关闭定时器
    QRect CreatePoi(int a);  //创造毒药
    bool CheckLevel(int s);  //根据入参s判断等级是否需要加一
    void Restart();  //重新开始游戏
    void SetChange(bool sign);  //设置难度变化标志
    void ChangeDifficulty();  //改变难度，根据等级进行判断
    void Rank(int order);  //排行榜处理函数,根据入参分为1写入排行榜保存文件，0读取
    int Compare();  //比较函数，用于比较得分大小
    bool CheckUp();  //检查是否确认晋级

    int rank[5];  //得分榜数组

public slots:
    void SnakeUpdate();  //更新贪吃蛇
    void ReceiveGame();  //接收游戏开始信号

protected:
    void paintEvent(QPaintEvent*);
    void keyPressEvent(QKeyEvent* event);

private slots:
    void on_EXIT_clicked();

private:
    Ui::snake *ui;
    QVector<QRect> Snake;  //贪吃蛇
    QRect Food;  //食物
    QTimer* time;  //定时器
    int Direction;  //方向
    bool IsRun;  //开始标志
    bool IsOver;  //结束标志
    int Score;  //得分
    int Level;  //等级
    QVector<QRect>Poi;  //毒药
    bool Sign;  //难度改变标签
};

#endif // SNAKE_H
