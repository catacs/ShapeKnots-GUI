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

#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <QDialog>


namespace Ui {
class Configuration;
}


/*!
 * \brief The Configuration class
 * The Configuration object stores the actual
 * configured values in the user interface to
 * be set when the program calls the Shapenots executable.
 */
class Configuration : public QDialog
{
    Q_OBJECT
public:
    explicit Configuration(QWidget *parent = 0);
    ~Configuration();
    //! Member to get the shapeknots path
    /*!
      * \brief
      * \return QString that holds the shapeknots route inside user interface.
     */
    QString shapeKnotsPath();
    //! Member to get the data_tables directory route
    /*!
     * \brief datapath
     * \return QString with data_tables route
     */
    QString datapath();
    //! Member to return the path to Draw command
    /*!
     * \brief drawPath
     * \return QString with Draw command route
     */
    QString drawPath();
    //! Member that returns the actual language
    /*!
     * \brief language
     * \return Integer with the actual selected language.
     */
    int language();

signals:
    //! Signal to accept saving the current configuration
    /*!
     * \brief acceptRequest
     */
    void acceptRequest();

private slots:
    //! Slot to close the window
    /*!
     * \brief closeRequest
     */
    void closeRequest();
    //! Slot to set ShapeKnots command route
    /*!
     * \brief selectShapeKnotsDialog
     */
    void selectShapeKnotsDialog();
    //! Slot to set the Draw command route
    /*!
     * \brief selectDrawDialog
     */
    void selectDrawDialog();
    //! Slot to set the data_tables route
    /*!
     * \brief selectDatapathDialog
     */
    void selectDatapathDialog();

protected:
    void changeEvent(QEvent *event);
private:

    Ui::Configuration *ui;

    friend class MainWindow;
};

#endif // CONFIGURATION_H
