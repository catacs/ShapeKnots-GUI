#ifndef DRAWPROCESS_H
#define DRAWPROCESS_H

#include <QProcess>

class DrawProcess : public QProcess
{
    Q_OBJECT
public:
    explicit DrawProcess(QObject *parent = 0);

signals:

public slots:

};

#endif // DRAWPROCESS_H
