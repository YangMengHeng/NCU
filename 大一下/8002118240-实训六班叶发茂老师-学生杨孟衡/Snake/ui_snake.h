/********************************************************************************
** Form generated from reading UI file 'snake.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SNAKE_H
#define UI_SNAKE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_snake
{
public:
    QLCDNumber *LCD_LEVEL;
    QLabel *SCORE;
    QLabel *LEVEL;
    QLCDNumber *LCD_SCORE;
    QLabel *RANK;
    QCommandLinkButton *EXIT;
    QLineEdit *FIRST;
    QLineEdit *SECOND;
    QLineEdit *THIRD;
    QLineEdit *FORTH;
    QLineEdit *FIFTH;

    void setupUi(QWidget *snake)
    {
        if (snake->objectName().isEmpty())
            snake->setObjectName(QStringLiteral("snake"));
        snake->resize(700, 500);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(snake->sizePolicy().hasHeightForWidth());
        snake->setSizePolicy(sizePolicy);
        LCD_LEVEL = new QLCDNumber(snake);
        LCD_LEVEL->setObjectName(QStringLiteral("LCD_LEVEL"));
        LCD_LEVEL->setGeometry(QRect(555, 60, 81, 31));
        sizePolicy.setHeightForWidth(LCD_LEVEL->sizePolicy().hasHeightForWidth());
        LCD_LEVEL->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        LCD_LEVEL->setFont(font);
        SCORE = new QLabel(snake);
        SCORE->setObjectName(QStringLiteral("SCORE"));
        SCORE->setGeometry(QRect(470, 120, 78, 25));
        sizePolicy.setHeightForWidth(SCORE->sizePolicy().hasHeightForWidth());
        SCORE->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setWeight(75);
        SCORE->setFont(font1);
        LEVEL = new QLabel(snake);
        LEVEL->setObjectName(QStringLiteral("LEVEL"));
        LEVEL->setGeometry(QRect(470, 60, 78, 25));
        LEVEL->setFont(font1);
        LCD_SCORE = new QLCDNumber(snake);
        LCD_SCORE->setObjectName(QStringLiteral("LCD_SCORE"));
        LCD_SCORE->setGeometry(QRect(555, 120, 81, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setBold(true);
        font2.setWeight(75);
        LCD_SCORE->setFont(font2);
        RANK = new QLabel(snake);
        RANK->setObjectName(QStringLiteral("RANK"));
        RANK->setGeometry(QRect(530, 180, 81, 25));
        RANK->setFont(font1);
        EXIT = new QCommandLinkButton(snake);
        EXIT->setObjectName(QStringLiteral("EXIT"));
        EXIT->setGeometry(QRect(470, 430, 172, 45));
        QFont font3;
        font3.setFamily(QStringLiteral("Segoe UI"));
        font3.setPointSize(15);
        font3.setBold(true);
        font3.setWeight(75);
        EXIT->setFont(font3);
        EXIT->setFocusPolicy(Qt::NoFocus);
        FIRST = new QLineEdit(snake);
        FIRST->setObjectName(QStringLiteral("FIRST"));
        FIRST->setGeometry(QRect(500, 220, 141, 31));
        FIRST->setFocusPolicy(Qt::NoFocus);
        FIRST->setReadOnly(true);
        SECOND = new QLineEdit(snake);
        SECOND->setObjectName(QStringLiteral("SECOND"));
        SECOND->setGeometry(QRect(500, 260, 141, 31));
        SECOND->setFocusPolicy(Qt::NoFocus);
        SECOND->setReadOnly(true);
        THIRD = new QLineEdit(snake);
        THIRD->setObjectName(QStringLiteral("THIRD"));
        THIRD->setGeometry(QRect(500, 300, 141, 31));
        THIRD->setFocusPolicy(Qt::NoFocus);
        THIRD->setReadOnly(true);
        FORTH = new QLineEdit(snake);
        FORTH->setObjectName(QStringLiteral("FORTH"));
        FORTH->setGeometry(QRect(500, 340, 141, 31));
        FORTH->setFocusPolicy(Qt::NoFocus);
        FORTH->setReadOnly(true);
        FIFTH = new QLineEdit(snake);
        FIFTH->setObjectName(QStringLiteral("FIFTH"));
        FIFTH->setGeometry(QRect(500, 380, 141, 31));
        FIFTH->setFocusPolicy(Qt::NoFocus);
        FIFTH->setReadOnly(true);

        retranslateUi(snake);

        QMetaObject::connectSlotsByName(snake);
    } // setupUi

    void retranslateUi(QWidget *snake)
    {
        snake->setWindowTitle(QApplication::translate("snake", "snake", Q_NULLPTR));
        SCORE->setText(QApplication::translate("snake", "\345\276\227\345\210\206\357\274\232", Q_NULLPTR));
        LEVEL->setText(QApplication::translate("snake", "\347\255\211\347\272\247\357\274\232", Q_NULLPTR));
        RANK->setText(QApplication::translate("snake", "\345\276\227\345\210\206\346\246\234", Q_NULLPTR));
        EXIT->setText(QApplication::translate("snake", "\351\200\200\345\207\272", Q_NULLPTR));
        FIRST->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class snake: public Ui_snake {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SNAKE_H
