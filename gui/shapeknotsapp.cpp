/***************************************************************
 *  @author: Catalin Stanciu
 *  @email: catacsdev@gmail.com
 *  Copyright (C) 2014
 * *************************************************************/

#include "shapeknotsapp.h"
#include <QApplication>
ShapeKnotsApp::ShapeKnotsApp(QObject *parent)
    :QObject(parent)
{
    connect(&m_mainWindow,SIGNAL(start()),&m_process,SLOT(run()));
    connect(&m_process, SIGNAL(line(const QString&)),
                    &m_mainWindow, SLOT(log(const QString&)));
    connect(&m_mainWindow, SIGNAL(inputSelected(const QString&)),
                    &m_process, SLOT(setInputFile(const QString&)));
    connect(&m_mainWindow, SIGNAL(outputSelected(const QString&)),
                    &m_process, SLOT(setOutputFile(const QString&)));
    connect(&m_mainWindow, SIGNAL(exit()), qApp, SLOT(quit()));
    m_mainWindow.show();
}
