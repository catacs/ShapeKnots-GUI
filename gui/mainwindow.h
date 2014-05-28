/***************************************************************
 *  @author: Catalin Stanciu
 *  @email: catacsdev@gmail.com
 *  Copyright (C) 2014
 * *************************************************************/

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
    void inputSelected(const QString& inputFile);
    void outputSelected(const QString& outputFile);
    void shapeSelected(const QString& outputFile);
    void diferentialShapeSelected(const QString& outputFile);
    void doubleOffsetSelected(const QString& outputFile);
    void singleOffsetSelected(const QString& outputFile);
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

private:
    void loadSettings();
    void saveSettings();

    Ui::MainWindow *ui;
    Configuration m_config;
    About   m_about;

};

#endif // MAINWINDOW_H
