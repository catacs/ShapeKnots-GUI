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

#include "appsettings.h"
#include <QApplication>
#include <QDir>
#include <QDebug>

QSettings *AppSettings::m_settings=0;


AppSettings::AppSettings()
{
}


QString AppSettings::version()
{
    return "DEBUG";
}


QSettings *AppSettings::settings()
{
    qDebug() << settingsFile();
    if (!m_settings)
        m_settings = new QSettings(settingsFile(),  QSettings::NativeFormat);
    return m_settings;
}


QString AppSettings::settingsFile()
{
#ifdef WIN32
    return QString("%appdata%/") + QString(DEFAULT_APPNAME) + QString(DEFAULT_CONFIGURATION_FILENAME) + QString(".ini");
#else
    return QDir::homePath() +"/.config/" + QString(DEFAULT_APPNAME) + QString(DEFAULT_CONFIGURATION_FILENAME) +QString(".conf");
#endif
}


QString AppSettings::language(const int languageIndex)
{
    switch (languageIndex) {
    case 0:
        return "en";
        break;
    case 1:
        return "es";
        break;
    case 2:
        return "fr";
        break;
    case 3:
        return "ro";
        break;
    default:
        break;
    }
    return "en";
}
