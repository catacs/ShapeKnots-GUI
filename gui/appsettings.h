/***************************************************************
 *  @author: Catalin Stanciu
 *  @email: catacsdev@gmail.com
 *  Copyright (C) 2014
 * *************************************************************/

#ifndef APPSETTINGS_H
#define APPSETTINGS_H

#include <QString>
#include <QSettings>

class AppSettings
{
public:
    AppSettings();
    static QString version();
    static QSettings *settings();
    static QString settingsFile();
private:
    static QSettings *m_settings;
};

#endif // APPSETTINGS_H
