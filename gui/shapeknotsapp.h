/***************************************************************
 *  @author: Catalin Stanciu
 *  @email: catacsdev@gmail.com
 *  Copyright (C) 2014
 * *************************************************************/

#ifndef SHAPEKNOTSAPP_H
#define SHAPEKNOTSAPP_H
#include "mainwindow.h"
#include "shapeknotsprocess.h"

class ShapeKnotsApp: public QObject
{
    Q_OBJECT
public:
    ShapeKnotsApp(QObject *parent=0);
signals:
    void exit();
private:
    MainWindow m_mainWindow;
    ShapeKnotsProcess m_process;
};

#endif // SHAPEKNOTSAPP_H
