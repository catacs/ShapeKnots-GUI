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
    void setArgument(const QString& option,const QString& value);
    QString inputFile() const;
    QString outputFile() const;


signals:
    void line(const QString& line);

public slots:
    void stdOut();
    void stdErr();
    void run();
    void setInputFile(const QString &inputFile);
    void setOutputFile(const QString &outputFile);

private:
    QStringList m_argv;
    QString m_inputFile;
    QString m_outputFile;
};

#endif // SHAPEKNOTSPROCESS_H
