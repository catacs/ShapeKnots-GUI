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

#ifndef SHAPEKNOTSPROCESS_H
#define SHAPEKNOTSPROCESS_H

#include <QProcess>
#include <QString>

class ShapeKnotsProcess : public QProcess
{
    Q_OBJECT
public:
    explicit ShapeKnotsProcess(QObject *parent = 0);
    ~ShapeKnotsProcess();
    QString inputFile() const;
    QString outputFile() const;
    QString shapeFile() const;
    QString differentialShapeFile() const;
    QString singleOffsetFile() const;
    QString doubleOffsetFile() const;
    bool optionals() const;

signals:
    void line(const QString& line);

public slots:
    void stdOut();
    void stdErr();
    void run();
    void setInputFile(const QString &inputFile);
    void setOutputFile(const QString &outputFile);
    void setShapeFile(const QString &shapeFile);
    void setDifferentialShapeFile(const QString &differentialShapeFile);
    void setSingleOffsetFile(const QString &singleOffsetFile);
    void setDoubleOffsetFile(const QString &doubleOffsetFile);
    void setOptionals(bool applyOptionals);

private:
    QString m_inputFile;
    QString m_outputFile;
    QString m_shapeFile;
    QString m_differentialShapeFile;
    QString m_singleOffsetFile;
    QString m_doubleOffsetFile;

    bool m_optionals;
};

#endif // SHAPEKNOTSPROCESS_H
