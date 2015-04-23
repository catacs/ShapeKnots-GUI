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
    //! Signal fired when start button clicked
    /*!
     * \brief start
     */
    void start();
    //! Signal fired when cancel button clicked
    /*!
     * \brief cancel
     */
    void cancel();
    //! Signal fired when input file has changed
    /*!
     * \brief inputSelected
     * \param inputFile
     */
    void inputSelected(const QString& inputFile);
    //! Signal fired when output file has changed
    /*!
     * \brief outputSelected
     * \param outputFile
     */
    void outputSelected(const QString& outputFile);
    //! Signal fired when shape file has been selected
    /*!
     * \brief shapeSelected
     * \param outputFile
     */
    void shapeSelected(const QString& outputFile);
    //! Signal fired when differential shape file has been selected
    /*!
     * \brief diferentialShapeSelected
     * \param outputFile
     */
    void diferentialShapeSelected(const QString& outputFile);
    //! Signal fired when double offset file has been selected
    /*!
     * \brief doubleOffsetSelected
     * \param outputFile
     */
    void doubleOffsetSelected(const QString& outputFile);
    //! Signal fired when single offset file has been selected
    /*!
     * \brief singleOffsetSelected
     * \param outputFile
     */
    void singleOffsetSelected(const QString& outputFile);
    //! Signal fired when options check button has changed
    /*!
     * \brief optionsToggle
     * \param selected
     */
    void optionsToggle(bool selected);
    //! Signal fired when app is closed
    /*!
     * \brief exit
     */
    void exit();

public slots:
    //! Slot to write the Shapeknots output to screen
    /*!
     * \brief log
     * \param lines
     */
    void log(const QString& line);

private  slots:
    //! Slot to show input file dialog
    /*!
     * \brief inputDialog
     */
    void inputDialog();
    //! Slot to show ouput file dialog
    /*!
     * \brief outputDialog
     */
    void outputDialog();
    //! Slot to show shape file dialog
    /*!
     * \brief shapeDialog
     */
    void shapeDialog();
    //! Slot to show differential shape dialog
    /*!
     * \brief diferentialShapeDialog
     */
    void diferentialShapeDialog();
    //! Slot to show double offset dialog
    /*!
     * \brief doubleOffsetDialog
     */
    void doubleOffsetDialog();
    //! Slot to show single offset dialog
    /*!
     * \brief singleOffsetDialog
     */
    void singleOffsetDialog();
    //! Slot to show settings options
    /*!
     * \brief showSettings
     */
    void showSettings();
    //! Slot to show about dialog
    /*!
     * \brief showAbout
     */
    void showAbout();
    //! Slot to start running Shapeknots program
    /*!
     * \brief startRun
     */
    void startRun();
    //! Slot to cancel the execution of Shapeknots program
    void cancelRun();

private slots:
    //! Slot to load app settings into user interface
    /*!
     * \brief loadSettings
     */
    void loadSettings();
    //! Slot to save user interface settings
    void saveSettings();
protected:
    void changeEvent(QEvent *event);
private:
    //! Pointer to main window interface
    Ui::MainWindow *ui;
    //! Configuration window
    Configuration m_config;
    //! About window
    About   m_about;

};

#endif // MAINWINDOW_H
