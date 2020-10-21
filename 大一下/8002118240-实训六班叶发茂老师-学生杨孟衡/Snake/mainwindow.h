#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void StartGame();  //开始游戏

private slots:
    void on_START_clicked();

    void on_HELP_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
