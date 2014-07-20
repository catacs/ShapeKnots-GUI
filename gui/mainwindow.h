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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "about.h"
#include "configuration.h"
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
    void start();
    void cancel();
    void inputSelected(const QString& inputFile);
    void outputSelected(const QString& outputFile);
    void shapeSelected(const QString& outputFile);
    void diferentialShapeSelected(const QString& outputFile);
    void doubleOffsetSelected(const QString& outputFile);
    void singleOffsetSelected(const QString& outputFile);
    void optionsToggle(bool selected);
    void exit();

public slots:
    void log(const QString& line);

private  slots:
    void inputDialog();
    void outputDialog();
    void shapeDialog();
    void diferentialShapeDialog();
    void doubleOffsetDialog();
    void singleOffsetDialog();
    void showSettings();
    void showAbout();
    void startRun();
    void cancelRun();

private:
    void loadSettings();
    void saveSettings();

    Ui::MainWindow *ui;
    Configuration m_config;
    About   m_about;

};

#endif // MAINWINDOW_H
