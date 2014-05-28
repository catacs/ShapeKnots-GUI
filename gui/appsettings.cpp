/***************************************************************
 *  @author: Catalin Stanciu
 *  @email: catacsdev@gmail.com
 *  Copyright (C) 2014
 * *************************************************************/

#include "appsettings.h"
#include <QApplication>

QSettings *AppSettings::m_settings=0;

AppSettings::AppSettings()
{
}

QString AppSettings::version()
{
    return "";
}

QSettings *AppSettings::settings()
{
    if (!m_settings)
        m_settings = new QSettings(settingsFile(),  QSettings::NativeFormat);
    return m_settings;
}

QString AppSettings::settingsFile()
{
#ifdef WIN32
    return QApplication::applicationDirPath().left(1) + QString("shapeknotsgui.ini");
#else
    return QApplication::applicationDirPath().left(1) + QString("shapeknotsgui.conf");
#endif
}
