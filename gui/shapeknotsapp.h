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
