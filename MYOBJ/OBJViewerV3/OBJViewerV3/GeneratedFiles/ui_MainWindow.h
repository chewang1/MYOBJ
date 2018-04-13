/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <glwidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QAction *actionOpen;
    QAction *actionExit;
    QWidget *centralWidget;
    GLWidget *openGLWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *dockWidget_3;
    QWidget *dockWidgetContents_3;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QDoubleSpinBox *rotate_z;
    QDoubleSpinBox *rotate_y;
    QDoubleSpinBox *scale_x;
    QLabel *label_scale3d;
    QDoubleSpinBox *scale_y;
    QDoubleSpinBox *scale_z;
    QLabel *label_rotate;
    QDoubleSpinBox *scale_all;
    QDoubleSpinBox *rotate_x;
    QLabel *label_scale;
    QWidget *tab_2;
    QComboBox *comboBox_light;
    QWidget *widget_directionLight;
    QWidget *gridLayoutWidget_2;
    QGridLayout *directionLight_layout;
    QSpacerItem *horizontalSpacer_2;
    QSpinBox *lightKd_g;
    QLabel *label_lightambient;
    QSpinBox *lightKa_a;
    QSpinBox *lightKd_r;
    QSpinBox *lightKa_g;
    QSpinBox *lightKa_b;
    QSpinBox *lightKs_g;
    QLabel *label_lightspecular;
    QDoubleSpinBox *lightdir_x;
    QSpinBox *lightKs_a;
    QSpinBox *lightKs_b;
    QSpinBox *lightKa_r;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer;
    QLabel *label_lightIntensity;
    QLabel *label_lightdir;
    QSpinBox *lightKs_r;
    QDoubleSpinBox *lightdir_z;
    QDoubleSpinBox *lightdir_y;
    QSpinBox *lightKd_b;
    QSpinBox *lightKd_a;
    QLabel *label_lightdiffuse;
    QDoubleSpinBox *lightInten;
    QWidget *widget_pointlight;
    QWidget *gridLayoutWidget_4;
    QGridLayout *directionLight_layout_3;
    QSpinBox *lightKa_a_3;
    QSpinBox *lightKd_r_3;
    QSpinBox *lightKa_g_3;
    QSpinBox *lightKa_b_3;
    QSpinBox *lightKs_g_3;
    QLabel *label_lightambient_3;
    QSpacerItem *horizontalSpacer_9;
    QSpinBox *lightKd_g_3;
    QLabel *label_lightspecular_3;
    QDoubleSpinBox *lightpos_x_3;
    QSpinBox *lightKs_a_3;
    QDoubleSpinBox *lightpos_y_3;
    QDoubleSpinBox *lightpos_z_3;
    QSpinBox *lightKd_a_3;
    QLabel *label_lightdiffuse_3;
    QLabel *label_lightIntensity_3;
    QLabel *label_lightdir_3;
    QSpinBox *lightKd_b_3;
    QDoubleSpinBox *lightInten_3;
    QSpinBox *lightKs_b_3;
    QSpinBox *lightKa_r_3;
    QSpinBox *lightKs_r_3;
    QSpacerItem *horizontalSpacer_11;
    QSpacerItem *horizontalSpacer_12;
    QSpacerItem *horizontalSpacer_10;
    QWidget *widget_spotlight;
    QWidget *gridLayoutWidget_3;
    QGridLayout *directionLight_layout_2;
    QDoubleSpinBox *lightpos_y_2;
    QDoubleSpinBox *lightpos_z_2;
    QLabel *label_lightpos_2;
    QDoubleSpinBox *lightpos_x_2;
    QSpinBox *lightKs_g_2;
    QSpinBox *lightKs_b_2;
    QLabel *label_lightspecular_2;
    QSpacerItem *horizontalSpacer_5;
    QSpinBox *lightKa_g_2;
    QSpinBox *lightKa_a_2;
    QSpinBox *lightKa_b_2;
    QLabel *label_lightambient_2;
    QDoubleSpinBox *lightdir_x_2;
    QSpinBox *lightKs_a_2;
    QSpinBox *lightKd_g_2;
    QSpinBox *lightKa_r_2;
    QLabel *label_lightdir_2;
    QSpinBox *lightKs_r_2;
    QSpinBox *lightKd_r_2;
    QLabel *label_lightIntensity_2;
    QLabel *label_lightdiffuse_2;
    QDoubleSpinBox *lightdir_y_2;
    QSpinBox *lightKd_a_2;
    QDoubleSpinBox *lightdir_z_2;
    QDoubleSpinBox *lightInten_2;
    QSpinBox *lightKd_b_2;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label;
    QDoubleSpinBox *light_inner;
    QLabel *label_2;
    QDoubleSpinBox *light_outer;
    QSpacerItem *horizontalSpacer_13;
    QDoubleSpinBox *lightfalloff;
    QLabel *label_3;
    QTabWidget *tabWidget_2;
    QWidget *tab_3;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QStringLiteral("MainWindowClass"));
        MainWindowClass->resize(1366, 768);
        MainWindowClass->setWindowOpacity(1);
        MainWindowClass->setStyleSheet(QLatin1String("background-color:rgb(68, 68, 68);\n"
"color:rgb(255, 255, 255);\n"
"selection-background-color:rgb(161, 161, 161)"));
        MainWindowClass->setTabShape(QTabWidget::Rounded);
        actionOpen = new QAction(MainWindowClass);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionExit = new QAction(MainWindowClass);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setAutoFillBackground(false);
        openGLWidget = new GLWidget(centralWidget);
        openGLWidget->setObjectName(QStringLiteral("openGLWidget"));
        openGLWidget->setGeometry(QRect(20, 10, 981, 701));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(68, 68, 68, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush2(QColor(161, 161, 161, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Highlight, brush2);
        openGLWidget->setPalette(palette);
        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1366, 21));
        menuBar->setStyleSheet(QStringLiteral(""));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuFile->setStyleSheet(QStringLiteral("selection-background-color:rgb(161, 161, 161)"));
        MainWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindowClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindowClass->setStatusBar(statusBar);
        dockWidget_3 = new QDockWidget(MainWindowClass);
        dockWidget_3->setObjectName(QStringLiteral("dockWidget_3"));
        dockWidget_3->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(50);
        sizePolicy.setVerticalStretch(50);
        sizePolicy.setHeightForWidth(dockWidget_3->sizePolicy().hasHeightForWidth());
        dockWidget_3->setSizePolicy(sizePolicy);
        dockWidget_3->setMinimumSize(QSize(340, 720));
        dockWidget_3->setMaximumSize(QSize(340, 720));
        dockWidget_3->setBaseSize(QSize(0, 0));
        dockWidget_3->setFeatures(QDockWidget::AllDockWidgetFeatures);
        dockWidget_3->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
        dockWidgetContents_3 = new QWidget();
        dockWidgetContents_3->setObjectName(QStringLiteral("dockWidgetContents_3"));
        tabWidget = new QTabWidget(dockWidgetContents_3);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setGeometry(QRect(0, 0, 311, 371));
        tabWidget->setAutoFillBackground(false);
        tabWidget->setStyleSheet(QStringLiteral(""));
        tabWidget->setTabShape(QTabWidget::Rounded);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayoutWidget = new QWidget(tab);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 20, 281, 101));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        rotate_z = new QDoubleSpinBox(gridLayoutWidget);
        rotate_z->setObjectName(QStringLiteral("rotate_z"));
        rotate_z->setStyleSheet(QStringLiteral("background-color:rgb(42, 42, 42);color:rgb(222, 222, 222)"));

        gridLayout->addWidget(rotate_z, 2, 3, 1, 1);

        rotate_y = new QDoubleSpinBox(gridLayoutWidget);
        rotate_y->setObjectName(QStringLiteral("rotate_y"));
        rotate_y->setStyleSheet(QStringLiteral("background-color:rgb(42, 42, 42);color:rgb(222, 222, 222)"));

        gridLayout->addWidget(rotate_y, 2, 2, 1, 1);

        scale_x = new QDoubleSpinBox(gridLayoutWidget);
        scale_x->setObjectName(QStringLiteral("scale_x"));
        scale_x->setStyleSheet(QStringLiteral("background-color:rgb(42, 42, 42);color:rgb(222, 222, 222)"));

        gridLayout->addWidget(scale_x, 0, 1, 1, 1);

        label_scale3d = new QLabel(gridLayoutWidget);
        label_scale3d->setObjectName(QStringLiteral("label_scale3d"));
        QFont font;
        font.setPointSize(10);
        label_scale3d->setFont(font);
        label_scale3d->setStyleSheet(QStringLiteral("color:rgb(222, 222, 222)"));
        label_scale3d->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_scale3d, 0, 0, 1, 1);

        scale_y = new QDoubleSpinBox(gridLayoutWidget);
        scale_y->setObjectName(QStringLiteral("scale_y"));
        scale_y->setStyleSheet(QStringLiteral("background-color:rgb(42, 42, 42);color:rgb(222, 222, 222)"));

        gridLayout->addWidget(scale_y, 0, 2, 1, 1);

        scale_z = new QDoubleSpinBox(gridLayoutWidget);
        scale_z->setObjectName(QStringLiteral("scale_z"));
        scale_z->setStyleSheet(QStringLiteral("background-color:rgb(42, 42, 42);color:rgb(222, 222, 222)"));

        gridLayout->addWidget(scale_z, 0, 3, 1, 1);

        label_rotate = new QLabel(gridLayoutWidget);
        label_rotate->setObjectName(QStringLiteral("label_rotate"));
        label_rotate->setFont(font);
        label_rotate->setStyleSheet(QStringLiteral("color:rgb(222, 222, 222)"));
        label_rotate->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_rotate, 2, 0, 1, 1);

        scale_all = new QDoubleSpinBox(gridLayoutWidget);
        scale_all->setObjectName(QStringLiteral("scale_all"));
        scale_all->setStyleSheet(QStringLiteral("background-color:rgb(42, 42, 42);color:rgb(222, 222, 222)"));

        gridLayout->addWidget(scale_all, 1, 1, 1, 1);

        rotate_x = new QDoubleSpinBox(gridLayoutWidget);
        rotate_x->setObjectName(QStringLiteral("rotate_x"));
        rotate_x->setStyleSheet(QStringLiteral("background-color:rgb(42, 42, 42);color:rgb(222, 222, 222)"));

        gridLayout->addWidget(rotate_x, 2, 1, 1, 1);

        label_scale = new QLabel(gridLayoutWidget);
        label_scale->setObjectName(QStringLiteral("label_scale"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_scale->sizePolicy().hasHeightForWidth());
        label_scale->setSizePolicy(sizePolicy1);
        label_scale->setFont(font);
        label_scale->setStyleSheet(QStringLiteral("color:rgb(222, 222, 222)"));
        label_scale->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_scale, 1, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        comboBox_light = new QComboBox(tab_2);
        comboBox_light->addItem(QString());
        comboBox_light->addItem(QString());
        comboBox_light->addItem(QString());
        comboBox_light->setObjectName(QStringLiteral("comboBox_light"));
        comboBox_light->setGeometry(QRect(70, 10, 141, 21));
        QFont font1;
        font1.setPointSize(12);
        comboBox_light->setFont(font1);
        comboBox_light->setStyleSheet(QLatin1String("background-color:rgb(255, 255, 255);\n"
"color:rgb(0, 0, 0);"));
        widget_directionLight = new QWidget(tab_2);
        widget_directionLight->setObjectName(QStringLiteral("widget_directionLight"));
        widget_directionLight->setEnabled(true);
        widget_directionLight->setGeometry(QRect(10, 40, 291, 281));
        gridLayoutWidget_2 = new QWidget(widget_directionLight);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(0, 10, 281, 191));
        directionLight_layout = new QGridLayout(gridLayoutWidget_2);
        directionLight_layout->setSpacing(6);
        directionLight_layout->setContentsMargins(11, 11, 11, 11);
        directionLight_layout->setObjectName(QStringLiteral("directionLight_layout"));
        directionLight_layout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        directionLight_layout->addItem(horizontalSpacer_2, 0, 4, 1, 1);

        lightKd_g = new QSpinBox(gridLayoutWidget_2);
        lightKd_g->setObjectName(QStringLiteral("lightKd_g"));

        directionLight_layout->addWidget(lightKd_g, 2, 2, 1, 1);

        label_lightambient = new QLabel(gridLayoutWidget_2);
        label_lightambient->setObjectName(QStringLiteral("label_lightambient"));
        label_lightambient->setFont(font);
        label_lightambient->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        directionLight_layout->addWidget(label_lightambient, 1, 0, 1, 1);

        lightKa_a = new QSpinBox(gridLayoutWidget_2);
        lightKa_a->setObjectName(QStringLiteral("lightKa_a"));

        directionLight_layout->addWidget(lightKa_a, 1, 4, 1, 1);

        lightKd_r = new QSpinBox(gridLayoutWidget_2);
        lightKd_r->setObjectName(QStringLiteral("lightKd_r"));

        directionLight_layout->addWidget(lightKd_r, 2, 1, 1, 1);

        lightKa_g = new QSpinBox(gridLayoutWidget_2);
        lightKa_g->setObjectName(QStringLiteral("lightKa_g"));

        directionLight_layout->addWidget(lightKa_g, 1, 2, 1, 1);

        lightKa_b = new QSpinBox(gridLayoutWidget_2);
        lightKa_b->setObjectName(QStringLiteral("lightKa_b"));

        directionLight_layout->addWidget(lightKa_b, 1, 3, 1, 1);

        lightKs_g = new QSpinBox(gridLayoutWidget_2);
        lightKs_g->setObjectName(QStringLiteral("lightKs_g"));

        directionLight_layout->addWidget(lightKs_g, 3, 2, 1, 1);

        label_lightspecular = new QLabel(gridLayoutWidget_2);
        label_lightspecular->setObjectName(QStringLiteral("label_lightspecular"));
        label_lightspecular->setFont(font);
        label_lightspecular->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        directionLight_layout->addWidget(label_lightspecular, 3, 0, 1, 1);

        lightdir_x = new QDoubleSpinBox(gridLayoutWidget_2);
        lightdir_x->setObjectName(QStringLiteral("lightdir_x"));

        directionLight_layout->addWidget(lightdir_x, 0, 1, 1, 1);

        lightKs_a = new QSpinBox(gridLayoutWidget_2);
        lightKs_a->setObjectName(QStringLiteral("lightKs_a"));

        directionLight_layout->addWidget(lightKs_a, 3, 4, 1, 1);

        lightKs_b = new QSpinBox(gridLayoutWidget_2);
        lightKs_b->setObjectName(QStringLiteral("lightKs_b"));

        directionLight_layout->addWidget(lightKs_b, 3, 3, 1, 1);

        lightKa_r = new QSpinBox(gridLayoutWidget_2);
        lightKa_r->setObjectName(QStringLiteral("lightKa_r"));

        directionLight_layout->addWidget(lightKa_r, 1, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        directionLight_layout->addItem(horizontalSpacer_3, 4, 3, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        directionLight_layout->addItem(horizontalSpacer_4, 4, 4, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        directionLight_layout->addItem(horizontalSpacer, 4, 2, 1, 1);

        label_lightIntensity = new QLabel(gridLayoutWidget_2);
        label_lightIntensity->setObjectName(QStringLiteral("label_lightIntensity"));

        directionLight_layout->addWidget(label_lightIntensity, 4, 0, 1, 1);

        label_lightdir = new QLabel(gridLayoutWidget_2);
        label_lightdir->setObjectName(QStringLiteral("label_lightdir"));
        label_lightdir->setFont(font);
        label_lightdir->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        directionLight_layout->addWidget(label_lightdir, 0, 0, 1, 1);

        lightKs_r = new QSpinBox(gridLayoutWidget_2);
        lightKs_r->setObjectName(QStringLiteral("lightKs_r"));

        directionLight_layout->addWidget(lightKs_r, 3, 1, 1, 1);

        lightdir_z = new QDoubleSpinBox(gridLayoutWidget_2);
        lightdir_z->setObjectName(QStringLiteral("lightdir_z"));

        directionLight_layout->addWidget(lightdir_z, 0, 3, 1, 1);

        lightdir_y = new QDoubleSpinBox(gridLayoutWidget_2);
        lightdir_y->setObjectName(QStringLiteral("lightdir_y"));

        directionLight_layout->addWidget(lightdir_y, 0, 2, 1, 1);

        lightKd_b = new QSpinBox(gridLayoutWidget_2);
        lightKd_b->setObjectName(QStringLiteral("lightKd_b"));

        directionLight_layout->addWidget(lightKd_b, 2, 3, 1, 1);

        lightKd_a = new QSpinBox(gridLayoutWidget_2);
        lightKd_a->setObjectName(QStringLiteral("lightKd_a"));

        directionLight_layout->addWidget(lightKd_a, 2, 4, 1, 1);

        label_lightdiffuse = new QLabel(gridLayoutWidget_2);
        label_lightdiffuse->setObjectName(QStringLiteral("label_lightdiffuse"));
        label_lightdiffuse->setFont(font);
        label_lightdiffuse->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        directionLight_layout->addWidget(label_lightdiffuse, 2, 0, 1, 1);

        lightInten = new QDoubleSpinBox(gridLayoutWidget_2);
        lightInten->setObjectName(QStringLiteral("lightInten"));

        directionLight_layout->addWidget(lightInten, 4, 1, 1, 1);

        widget_pointlight = new QWidget(tab_2);
        widget_pointlight->setObjectName(QStringLiteral("widget_pointlight"));
        widget_pointlight->setEnabled(true);
        widget_pointlight->setGeometry(QRect(10, 40, 291, 281));
        gridLayoutWidget_4 = new QWidget(widget_pointlight);
        gridLayoutWidget_4->setObjectName(QStringLiteral("gridLayoutWidget_4"));
        gridLayoutWidget_4->setGeometry(QRect(0, 10, 281, 191));
        directionLight_layout_3 = new QGridLayout(gridLayoutWidget_4);
        directionLight_layout_3->setSpacing(6);
        directionLight_layout_3->setContentsMargins(11, 11, 11, 11);
        directionLight_layout_3->setObjectName(QStringLiteral("directionLight_layout_3"));
        directionLight_layout_3->setContentsMargins(0, 0, 0, 0);
        lightKa_a_3 = new QSpinBox(gridLayoutWidget_4);
        lightKa_a_3->setObjectName(QStringLiteral("lightKa_a_3"));

        directionLight_layout_3->addWidget(lightKa_a_3, 1, 4, 1, 1);

        lightKd_r_3 = new QSpinBox(gridLayoutWidget_4);
        lightKd_r_3->setObjectName(QStringLiteral("lightKd_r_3"));

        directionLight_layout_3->addWidget(lightKd_r_3, 2, 1, 1, 1);

        lightKa_g_3 = new QSpinBox(gridLayoutWidget_4);
        lightKa_g_3->setObjectName(QStringLiteral("lightKa_g_3"));

        directionLight_layout_3->addWidget(lightKa_g_3, 1, 2, 1, 1);

        lightKa_b_3 = new QSpinBox(gridLayoutWidget_4);
        lightKa_b_3->setObjectName(QStringLiteral("lightKa_b_3"));

        directionLight_layout_3->addWidget(lightKa_b_3, 1, 3, 1, 1);

        lightKs_g_3 = new QSpinBox(gridLayoutWidget_4);
        lightKs_g_3->setObjectName(QStringLiteral("lightKs_g_3"));

        directionLight_layout_3->addWidget(lightKs_g_3, 3, 2, 1, 1);

        label_lightambient_3 = new QLabel(gridLayoutWidget_4);
        label_lightambient_3->setObjectName(QStringLiteral("label_lightambient_3"));
        label_lightambient_3->setFont(font);
        label_lightambient_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        directionLight_layout_3->addWidget(label_lightambient_3, 1, 0, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        directionLight_layout_3->addItem(horizontalSpacer_9, 0, 4, 1, 1);

        lightKd_g_3 = new QSpinBox(gridLayoutWidget_4);
        lightKd_g_3->setObjectName(QStringLiteral("lightKd_g_3"));

        directionLight_layout_3->addWidget(lightKd_g_3, 2, 2, 1, 1);

        label_lightspecular_3 = new QLabel(gridLayoutWidget_4);
        label_lightspecular_3->setObjectName(QStringLiteral("label_lightspecular_3"));
        label_lightspecular_3->setFont(font);
        label_lightspecular_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        directionLight_layout_3->addWidget(label_lightspecular_3, 3, 0, 1, 1);

        lightpos_x_3 = new QDoubleSpinBox(gridLayoutWidget_4);
        lightpos_x_3->setObjectName(QStringLiteral("lightpos_x_3"));

        directionLight_layout_3->addWidget(lightpos_x_3, 0, 1, 1, 1);

        lightKs_a_3 = new QSpinBox(gridLayoutWidget_4);
        lightKs_a_3->setObjectName(QStringLiteral("lightKs_a_3"));

        directionLight_layout_3->addWidget(lightKs_a_3, 3, 4, 1, 1);

        lightpos_y_3 = new QDoubleSpinBox(gridLayoutWidget_4);
        lightpos_y_3->setObjectName(QStringLiteral("lightpos_y_3"));

        directionLight_layout_3->addWidget(lightpos_y_3, 0, 2, 1, 1);

        lightpos_z_3 = new QDoubleSpinBox(gridLayoutWidget_4);
        lightpos_z_3->setObjectName(QStringLiteral("lightpos_z_3"));

        directionLight_layout_3->addWidget(lightpos_z_3, 0, 3, 1, 1);

        lightKd_a_3 = new QSpinBox(gridLayoutWidget_4);
        lightKd_a_3->setObjectName(QStringLiteral("lightKd_a_3"));

        directionLight_layout_3->addWidget(lightKd_a_3, 2, 4, 1, 1);

        label_lightdiffuse_3 = new QLabel(gridLayoutWidget_4);
        label_lightdiffuse_3->setObjectName(QStringLiteral("label_lightdiffuse_3"));
        label_lightdiffuse_3->setFont(font);
        label_lightdiffuse_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        directionLight_layout_3->addWidget(label_lightdiffuse_3, 2, 0, 1, 1);

        label_lightIntensity_3 = new QLabel(gridLayoutWidget_4);
        label_lightIntensity_3->setObjectName(QStringLiteral("label_lightIntensity_3"));

        directionLight_layout_3->addWidget(label_lightIntensity_3, 4, 0, 1, 1);

        label_lightdir_3 = new QLabel(gridLayoutWidget_4);
        label_lightdir_3->setObjectName(QStringLiteral("label_lightdir_3"));
        label_lightdir_3->setFont(font);
        label_lightdir_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        directionLight_layout_3->addWidget(label_lightdir_3, 0, 0, 1, 1);

        lightKd_b_3 = new QSpinBox(gridLayoutWidget_4);
        lightKd_b_3->setObjectName(QStringLiteral("lightKd_b_3"));

        directionLight_layout_3->addWidget(lightKd_b_3, 2, 3, 1, 1);

        lightInten_3 = new QDoubleSpinBox(gridLayoutWidget_4);
        lightInten_3->setObjectName(QStringLiteral("lightInten_3"));

        directionLight_layout_3->addWidget(lightInten_3, 4, 1, 1, 1);

        lightKs_b_3 = new QSpinBox(gridLayoutWidget_4);
        lightKs_b_3->setObjectName(QStringLiteral("lightKs_b_3"));

        directionLight_layout_3->addWidget(lightKs_b_3, 3, 3, 1, 1);

        lightKa_r_3 = new QSpinBox(gridLayoutWidget_4);
        lightKa_r_3->setObjectName(QStringLiteral("lightKa_r_3"));

        directionLight_layout_3->addWidget(lightKa_r_3, 1, 1, 1, 1);

        lightKs_r_3 = new QSpinBox(gridLayoutWidget_4);
        lightKs_r_3->setObjectName(QStringLiteral("lightKs_r_3"));

        directionLight_layout_3->addWidget(lightKs_r_3, 3, 1, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        directionLight_layout_3->addItem(horizontalSpacer_11, 4, 3, 1, 1);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        directionLight_layout_3->addItem(horizontalSpacer_12, 4, 4, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        directionLight_layout_3->addItem(horizontalSpacer_10, 4, 2, 1, 1);

        widget_spotlight = new QWidget(tab_2);
        widget_spotlight->setObjectName(QStringLiteral("widget_spotlight"));
        widget_spotlight->setEnabled(true);
        widget_spotlight->setGeometry(QRect(10, 40, 291, 281));
        gridLayoutWidget_3 = new QWidget(widget_spotlight);
        gridLayoutWidget_3->setObjectName(QStringLiteral("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(0, 10, 291, 261));
        directionLight_layout_2 = new QGridLayout(gridLayoutWidget_3);
        directionLight_layout_2->setSpacing(6);
        directionLight_layout_2->setContentsMargins(11, 11, 11, 11);
        directionLight_layout_2->setObjectName(QStringLiteral("directionLight_layout_2"));
        directionLight_layout_2->setContentsMargins(0, 0, 0, 0);
        lightpos_y_2 = new QDoubleSpinBox(gridLayoutWidget_3);
        lightpos_y_2->setObjectName(QStringLiteral("lightpos_y_2"));

        directionLight_layout_2->addWidget(lightpos_y_2, 0, 2, 1, 1);

        lightpos_z_2 = new QDoubleSpinBox(gridLayoutWidget_3);
        lightpos_z_2->setObjectName(QStringLiteral("lightpos_z_2"));

        directionLight_layout_2->addWidget(lightpos_z_2, 0, 3, 1, 1);

        label_lightpos_2 = new QLabel(gridLayoutWidget_3);
        label_lightpos_2->setObjectName(QStringLiteral("label_lightpos_2"));
        label_lightpos_2->setFont(font);
        label_lightpos_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        directionLight_layout_2->addWidget(label_lightpos_2, 0, 0, 1, 1);

        lightpos_x_2 = new QDoubleSpinBox(gridLayoutWidget_3);
        lightpos_x_2->setObjectName(QStringLiteral("lightpos_x_2"));

        directionLight_layout_2->addWidget(lightpos_x_2, 0, 1, 1, 1);

        lightKs_g_2 = new QSpinBox(gridLayoutWidget_3);
        lightKs_g_2->setObjectName(QStringLiteral("lightKs_g_2"));

        directionLight_layout_2->addWidget(lightKs_g_2, 4, 2, 1, 1);

        lightKs_b_2 = new QSpinBox(gridLayoutWidget_3);
        lightKs_b_2->setObjectName(QStringLiteral("lightKs_b_2"));

        directionLight_layout_2->addWidget(lightKs_b_2, 4, 3, 1, 1);

        label_lightspecular_2 = new QLabel(gridLayoutWidget_3);
        label_lightspecular_2->setObjectName(QStringLiteral("label_lightspecular_2"));
        label_lightspecular_2->setFont(font);
        label_lightspecular_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        directionLight_layout_2->addWidget(label_lightspecular_2, 4, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        directionLight_layout_2->addItem(horizontalSpacer_5, 1, 4, 1, 1);

        lightKa_g_2 = new QSpinBox(gridLayoutWidget_3);
        lightKa_g_2->setObjectName(QStringLiteral("lightKa_g_2"));

        directionLight_layout_2->addWidget(lightKa_g_2, 2, 2, 1, 1);

        lightKa_a_2 = new QSpinBox(gridLayoutWidget_3);
        lightKa_a_2->setObjectName(QStringLiteral("lightKa_a_2"));

        directionLight_layout_2->addWidget(lightKa_a_2, 2, 4, 1, 1);

        lightKa_b_2 = new QSpinBox(gridLayoutWidget_3);
        lightKa_b_2->setObjectName(QStringLiteral("lightKa_b_2"));

        directionLight_layout_2->addWidget(lightKa_b_2, 2, 3, 1, 1);

        label_lightambient_2 = new QLabel(gridLayoutWidget_3);
        label_lightambient_2->setObjectName(QStringLiteral("label_lightambient_2"));
        label_lightambient_2->setFont(font);
        label_lightambient_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        directionLight_layout_2->addWidget(label_lightambient_2, 2, 0, 1, 1);

        lightdir_x_2 = new QDoubleSpinBox(gridLayoutWidget_3);
        lightdir_x_2->setObjectName(QStringLiteral("lightdir_x_2"));

        directionLight_layout_2->addWidget(lightdir_x_2, 1, 1, 1, 1);

        lightKs_a_2 = new QSpinBox(gridLayoutWidget_3);
        lightKs_a_2->setObjectName(QStringLiteral("lightKs_a_2"));

        directionLight_layout_2->addWidget(lightKs_a_2, 4, 4, 1, 1);

        lightKd_g_2 = new QSpinBox(gridLayoutWidget_3);
        lightKd_g_2->setObjectName(QStringLiteral("lightKd_g_2"));

        directionLight_layout_2->addWidget(lightKd_g_2, 3, 2, 1, 1);

        lightKa_r_2 = new QSpinBox(gridLayoutWidget_3);
        lightKa_r_2->setObjectName(QStringLiteral("lightKa_r_2"));

        directionLight_layout_2->addWidget(lightKa_r_2, 2, 1, 1, 1);

        label_lightdir_2 = new QLabel(gridLayoutWidget_3);
        label_lightdir_2->setObjectName(QStringLiteral("label_lightdir_2"));
        label_lightdir_2->setFont(font);
        label_lightdir_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        directionLight_layout_2->addWidget(label_lightdir_2, 1, 0, 1, 1);

        lightKs_r_2 = new QSpinBox(gridLayoutWidget_3);
        lightKs_r_2->setObjectName(QStringLiteral("lightKs_r_2"));

        directionLight_layout_2->addWidget(lightKs_r_2, 4, 1, 1, 1);

        lightKd_r_2 = new QSpinBox(gridLayoutWidget_3);
        lightKd_r_2->setObjectName(QStringLiteral("lightKd_r_2"));

        directionLight_layout_2->addWidget(lightKd_r_2, 3, 1, 1, 1);

        label_lightIntensity_2 = new QLabel(gridLayoutWidget_3);
        label_lightIntensity_2->setObjectName(QStringLiteral("label_lightIntensity_2"));

        directionLight_layout_2->addWidget(label_lightIntensity_2, 5, 0, 1, 1);

        label_lightdiffuse_2 = new QLabel(gridLayoutWidget_3);
        label_lightdiffuse_2->setObjectName(QStringLiteral("label_lightdiffuse_2"));
        label_lightdiffuse_2->setFont(font);
        label_lightdiffuse_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        directionLight_layout_2->addWidget(label_lightdiffuse_2, 3, 0, 1, 1);

        lightdir_y_2 = new QDoubleSpinBox(gridLayoutWidget_3);
        lightdir_y_2->setObjectName(QStringLiteral("lightdir_y_2"));

        directionLight_layout_2->addWidget(lightdir_y_2, 1, 2, 1, 1);

        lightKd_a_2 = new QSpinBox(gridLayoutWidget_3);
        lightKd_a_2->setObjectName(QStringLiteral("lightKd_a_2"));

        directionLight_layout_2->addWidget(lightKd_a_2, 3, 4, 1, 1);

        lightdir_z_2 = new QDoubleSpinBox(gridLayoutWidget_3);
        lightdir_z_2->setObjectName(QStringLiteral("lightdir_z_2"));

        directionLight_layout_2->addWidget(lightdir_z_2, 1, 3, 1, 1);

        lightInten_2 = new QDoubleSpinBox(gridLayoutWidget_3);
        lightInten_2->setObjectName(QStringLiteral("lightInten_2"));

        directionLight_layout_2->addWidget(lightInten_2, 5, 1, 1, 1);

        lightKd_b_2 = new QSpinBox(gridLayoutWidget_3);
        lightKd_b_2->setObjectName(QStringLiteral("lightKd_b_2"));

        directionLight_layout_2->addWidget(lightKd_b_2, 3, 3, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        directionLight_layout_2->addItem(horizontalSpacer_6, 5, 2, 1, 1);

        label = new QLabel(gridLayoutWidget_3);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        directionLight_layout_2->addWidget(label, 6, 0, 1, 1);

        light_inner = new QDoubleSpinBox(gridLayoutWidget_3);
        light_inner->setObjectName(QStringLiteral("light_inner"));

        directionLight_layout_2->addWidget(light_inner, 6, 1, 1, 1);

        label_2 = new QLabel(gridLayoutWidget_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        directionLight_layout_2->addWidget(label_2, 6, 3, 1, 1);

        light_outer = new QDoubleSpinBox(gridLayoutWidget_3);
        light_outer->setObjectName(QStringLiteral("light_outer"));

        directionLight_layout_2->addWidget(light_outer, 6, 4, 1, 1);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        directionLight_layout_2->addItem(horizontalSpacer_13, 6, 2, 1, 1);

        lightfalloff = new QDoubleSpinBox(gridLayoutWidget_3);
        lightfalloff->setObjectName(QStringLiteral("lightfalloff"));

        directionLight_layout_2->addWidget(lightfalloff, 5, 4, 1, 1);

        label_3 = new QLabel(gridLayoutWidget_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        directionLight_layout_2->addWidget(label_3, 5, 3, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tabWidget_2 = new QTabWidget(dockWidgetContents_3);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(0, 390, 311, 241));
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tabWidget_2->addTab(tab_3, QString());
        dockWidget_3->setWidget(dockWidgetContents_3);
        MainWindowClass->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockWidget_3);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionExit);

        retranslateUi(MainWindowClass);
        QObject::connect(actionExit, SIGNAL(triggered()), MainWindowClass, SLOT(close()));

        tabWidget->setCurrentIndex(0);
        comboBox_light->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "MainWindow", nullptr));
        actionOpen->setText(QApplication::translate("MainWindowClass", "Open", nullptr));
        actionExit->setText(QApplication::translate("MainWindowClass", "Exit", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindowClass", "File", nullptr));
        dockWidget_3->setWindowTitle(QApplication::translate("MainWindowClass", "Attribute Editor", nullptr));
        label_scale3d->setText(QApplication::translate("MainWindowClass", "Scale3D", nullptr));
        label_rotate->setText(QApplication::translate("MainWindowClass", "Rotate", nullptr));
        label_scale->setText(QApplication::translate("MainWindowClass", "Scale", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindowClass", "Transform", nullptr));
        comboBox_light->setItemText(0, QApplication::translate("MainWindowClass", "Directional Light", nullptr));
        comboBox_light->setItemText(1, QApplication::translate("MainWindowClass", "Spot Light", nullptr));
        comboBox_light->setItemText(2, QApplication::translate("MainWindowClass", "Point Light", nullptr));

        label_lightambient->setText(QApplication::translate("MainWindowClass", "Ambient", nullptr));
        label_lightspecular->setText(QApplication::translate("MainWindowClass", "Specular", nullptr));
        label_lightIntensity->setText(QApplication::translate("MainWindowClass", "Intensity", nullptr));
        label_lightdir->setText(QApplication::translate("MainWindowClass", "Direction", nullptr));
        label_lightdiffuse->setText(QApplication::translate("MainWindowClass", "Diffuse", nullptr));
        label_lightambient_3->setText(QApplication::translate("MainWindowClass", "Ambient", nullptr));
        label_lightspecular_3->setText(QApplication::translate("MainWindowClass", "Specular", nullptr));
        label_lightdiffuse_3->setText(QApplication::translate("MainWindowClass", "Diffuse", nullptr));
        label_lightIntensity_3->setText(QApplication::translate("MainWindowClass", "Intensity", nullptr));
        label_lightdir_3->setText(QApplication::translate("MainWindowClass", "Position", nullptr));
        label_lightpos_2->setText(QApplication::translate("MainWindowClass", "Position", nullptr));
        label_lightspecular_2->setText(QApplication::translate("MainWindowClass", "Specular", nullptr));
        label_lightambient_2->setText(QApplication::translate("MainWindowClass", "Ambient", nullptr));
        label_lightdir_2->setText(QApplication::translate("MainWindowClass", "Direction", nullptr));
        label_lightIntensity_2->setText(QApplication::translate("MainWindowClass", "Intensity", nullptr));
        label_lightdiffuse_2->setText(QApplication::translate("MainWindowClass", "Diffuse", nullptr));
        label->setText(QApplication::translate("MainWindowClass", "InnerAng", nullptr));
        label_2->setText(QApplication::translate("MainWindowClass", "OuterAng", nullptr));
        label_3->setText(QApplication::translate("MainWindowClass", "FallOff", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindowClass", "Light", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QApplication::translate("MainWindowClass", "Material", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
