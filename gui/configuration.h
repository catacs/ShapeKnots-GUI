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

class Configuration : public QDialog
{
    Q_OBJECT
public:
    explicit Configuration(QWidget *parent = 0);
    ~Configuration();

    QString shapeKnotsPath();
    QString datapath();
    QString drawPath();
    int language();

signals:
    void acceptRequest();

private slots:
    void closeRequest();

protected:
    void changeEvent(QEvent *event);
private:

    Ui::Configuration *ui;

    friend class MainWindow;
};

#endif // CONFIGURATION_H
