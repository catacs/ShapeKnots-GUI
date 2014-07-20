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

#include "shapeknotsprocess.h"
#include "appsettings.h"
#include <QFile>
#include <QDebug>

ShapeKnotsProcess::ShapeKnotsProcess(QObject *parent) :
    QProcess(parent)
{
    connect(this, SIGNAL(readyReadStandardOutput()),
            this, SLOT(stdOut()));
    connect(this, SIGNAL(readyReadStandardError()),
            this, SLOT(stdErr()));
    connect(this, SIGNAL(finished(int,QProcess::ExitStatus)),
            this, SLOT(terminate()));
}

ShapeKnotsProcess::~ShapeKnotsProcess()
{
    terminate();
}

void ShapeKnotsProcess::stdOut()
{
    QByteArray bytes = readAllStandardOutput();
    QStringList lines = QString(bytes).split("\n");
    foreach (QString text, lines) {
        emit line(text);
    }
}

void ShapeKnotsProcess::stdErr()
{
    QByteArray bytes = readAllStandardError();
    QStringList lines = QString(bytes).split("\n");
    foreach (QString text, lines) {
        emit line(text);
    }
}

void ShapeKnotsProcess::run()
{
    QProcessEnvironment env = QProcessEnvironment::systemEnvironment();
    QString command;
    QSettings *settings = AppSettings::settings();

    settings->beginGroup("ShapeKnots");
    QString datapath = settings->value("DATAPATH","./data_tables").toString();
    QString shapeknotsBin = settings->value("ExecutablePath", "./ShapeKnots").toString();
    env.insert("DATAPATH", datapath);
    settings->endGroup();

    QStringList allArgs;
    //read options from gui
    if (m_optionals){
        if (!m_shapeFile.isEmpty() && QFile::exists(m_shapeFile))
            allArgs.append("-sh " + m_shapeFile);
        if (!m_differentialShapeFile.isEmpty() && QFile::exists(m_differentialShapeFile))
            allArgs.append("-dsh " + m_differentialShapeFile);
        if (!m_singleOffsetFile.isEmpty() && QFile::exists(m_singleOffsetFile))
            allArgs.append("-sso " + m_singleOffsetFile);
        if (!m_doubleOffsetFile.isEmpty() && QFile::exists(m_doubleOffsetFile))
            allArgs.append("-dso " + m_doubleOffsetFile);
    }

    command = shapeknotsBin + QString(" ")
            + m_inputFile + QString(" ")
            + m_outputFile + QString(" ");

    this->setArguments(allArgs);
    setProcessEnvironment(env);
    start(command);
}

void ShapeKnotsProcess::cancel()
{
    this->kill();
}

QString ShapeKnotsProcess::outputFile() const
{
    return m_outputFile;
}

void ShapeKnotsProcess::setOutputFile(const QString &outputFile)
{
    qDebug() << outputFile;
    m_outputFile = outputFile;
}
bool ShapeKnotsProcess::optionals() const
{
    return m_optionals;
}

void ShapeKnotsProcess::setOptionals(bool optionals)
{
    m_optionals = optionals;
}
QString ShapeKnotsProcess::singleOffsetFile() const
{
    return m_singleOffsetFile;
}

void ShapeKnotsProcess::setSingleOffsetFile(const QString &singleOffsetFile)
{
    qDebug() << singleOffsetFile;
    m_singleOffsetFile = singleOffsetFile;
}

QString ShapeKnotsProcess::doubleOffsetFile() const
{
    return m_doubleOffsetFile;
}

void ShapeKnotsProcess::setDoubleOffsetFile(const QString &doubleOffsetFile)
{
    qDebug() << doubleOffsetFile ;
    m_doubleOffsetFile = doubleOffsetFile;
}

QString ShapeKnotsProcess::differentialShapeFile() const
{
    return m_differentialShapeFile;
}

void ShapeKnotsProcess::setDifferentialShapeFile(const QString &differentialShapeFile)
{
    qDebug() << differentialShapeFile ;
    m_differentialShapeFile = differentialShapeFile;
}


QString ShapeKnotsProcess::shapeFile() const
{
    return m_shapeFile;
}

void ShapeKnotsProcess::setShapeFile(const QString &shapeFile)
{
    qDebug() << shapeFile;
    m_shapeFile = shapeFile;
}


QString ShapeKnotsProcess::inputFile() const
{
    return m_inputFile;
}

void ShapeKnotsProcess::setInputFile(const QString &inputFile)
{
    qDebug() << inputFile;
    m_inputFile = inputFile;
}

