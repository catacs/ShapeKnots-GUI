/***************************************************************
 *  @author: Catalin Stanciu
 *  @email: catacsdev@gmail.com
 *  Copyright (C) 2014
 * *************************************************************/

#include "shapeknotsprocess.h"
#include "appsettings.h"
#include <QDebug>

ShapeKnotsProcess::ShapeKnotsProcess(QObject *parent) :
    QProcess(parent),
    m_argv(QString())
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

void ShapeKnotsProcess::setArgument(const QString &option, const QString &value)
{
    m_argv << option << " " << value;
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
    command = shapeknotsBin + QString(" ")
            + m_inputFile + QString(" ")
            + m_outputFile + QString(" ")
            + m_argv.join(" ");
    //this->setArguments(allArgs);
    qDebug() << command;
    setProcessEnvironment(env);
    start(command);
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

QString ShapeKnotsProcess::inputFile() const
{
    return m_inputFile;
}

void ShapeKnotsProcess::setInputFile(const QString &inputFile)
{
    qDebug() << inputFile;
    m_inputFile = inputFile;
}

