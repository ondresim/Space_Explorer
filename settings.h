/********************************************************************************
** Form generated from reading UI file 'Settings.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QPushButton *backtomenu_button;
    QFrame *frame;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *radioButton_5;
    QRadioButton *radioButton_6;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_4;
    QLabel *label;
    QLabel *label_2;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioButton_7;
    QRadioButton *radioButton_8;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QWidget *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName(QStringLiteral("Settings"));
        Settings->resize(1024, 768);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Settings->sizePolicy().hasHeightForWidth());
        Settings->setSizePolicy(sizePolicy);
        Settings->setStyleSheet(QStringLiteral(""));
        backtomenu_button = new QPushButton(Settings);
        backtomenu_button->setObjectName(QStringLiteral("backtomenu_button"));
        backtomenu_button->setGeometry(QRect(430, 640, 171, 81));
        backtomenu_button->setAutoFillBackground(false);
        frame = new QFrame(Settings);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(40, 130, 501, 121));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayoutWidget = new QWidget(frame);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 501, 122));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(6, -1, -1, -1);
        radioButton_2 = new QRadioButton(horizontalLayoutWidget);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setChecked(true);

        verticalLayout->addWidget(radioButton_2);

        radioButton_3 = new QRadioButton(horizontalLayoutWidget);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));

        verticalLayout->addWidget(radioButton_3);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(6, -1, -1, -1);
        radioButton_5 = new QRadioButton(horizontalLayoutWidget);
        radioButton_5->setObjectName(QStringLiteral("radioButton_5"));

        verticalLayout_3->addWidget(radioButton_5);

        radioButton_6 = new QRadioButton(horizontalLayoutWidget);
        radioButton_6->setObjectName(QStringLiteral("radioButton_6"));

        verticalLayout_3->addWidget(radioButton_6);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(6, -1, -1, -1);
        radioButton = new QRadioButton(horizontalLayoutWidget);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        verticalLayout_2->addWidget(radioButton);

        radioButton_4 = new QRadioButton(horizontalLayoutWidget);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));
        radioButton_4->setAutoFillBackground(false);

        verticalLayout_2->addWidget(radioButton_4);


        horizontalLayout->addLayout(verticalLayout_2);

        label = new QLabel(Settings);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 60, 471, 41));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        label->setAutoFillBackground(false);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(Settings);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(120, 320, 261, 51));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);
        horizontalLayoutWidget_2 = new QWidget(Settings);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(120, 460, 351, 61));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        radioButton_7 = new QRadioButton(horizontalLayoutWidget_2);
        radioButton_7->setObjectName(QStringLiteral("radioButton_7"));
        radioButton_7->setChecked(true);

        horizontalLayout_2->addWidget(radioButton_7);

        radioButton_8 = new QRadioButton(horizontalLayoutWidget_2);
        radioButton_8->setObjectName(QStringLiteral("radioButton_8"));

        horizontalLayout_2->addWidget(radioButton_8);

        label_3 = new QLabel(Settings);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(80, 370, 131, 81));
        label_4 = new QLabel(Settings);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(260, 370, 131, 81));

        retranslateUi(Settings);

        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QWidget *Settings)
    {
        Settings->setWindowTitle(QApplication::translate("Settings", "Form", Q_NULLPTR));
        backtomenu_button->setText(QApplication::translate("Settings", "Back to menu", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("Settings", "White", Q_NULLPTR));
        radioButton_3->setText(QApplication::translate("Settings", "Yellow", Q_NULLPTR));
        radioButton_5->setText(QApplication::translate("Settings", "Purple", Q_NULLPTR));
        radioButton_6->setText(QApplication::translate("Settings", "Green", Q_NULLPTR));
        radioButton->setText(QApplication::translate("Settings", "Red", Q_NULLPTR));
        radioButton_4->setText(QApplication::translate("Settings", "Blue", Q_NULLPTR));
        label->setText(QApplication::translate("Settings", "You can change the color of the buttons here!", Q_NULLPTR));
        label_2->setText(QApplication::translate("Settings", "Choose your spaceship:", Q_NULLPTR));
        radioButton_7->setText(QApplication::translate("Settings", "MK3", Q_NULLPTR));
        radioButton_8->setText(QApplication::translate("Settings", "MK4", Q_NULLPTR));
        label_3->setText(QString());
        label_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
