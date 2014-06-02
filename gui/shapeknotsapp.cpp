/****************************************************************************
 *
 *   ShapeKnots-GUI - Qt GUI for ShapeKnots command-line tool
 *
 *           Copyright 2014 Catalin Stanciu
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *       http://www.apache.org/licenses/LICENSE-2.0
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *****************************************************************************/

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
    connect(&m_mainWindow, SIGNAL(shapeSelected(const QString&)),
                    &m_process, SLOT(setShapeFile(const QString&)));
    connect(&m_mainWindow, SIGNAL(optionsToggle(bool)),
                    &m_process, SLOT(setOptionals(bool)));
    connect(&m_mainWindow, SIGNAL(exit()), qApp, SLOT(quit()));
    m_mainWindow.show();
}
