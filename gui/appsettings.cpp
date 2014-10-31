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
#include <QStandardPaths>
#include <QDebug>

QSettings *AppSettings::m_settings=0;


AppSettings::AppSettings()
{
}


QString AppSettings::version()
{
    return "0.0.2 beta";
}


QSettings *AppSettings::settings()
{
    if (!m_settings)
#ifdef WIN32
        m_settings = new QSettings(settingsFile(),  QSettings::IniFormat);
#else
        m_settings = new QSettings(settingsFile(),  QSettings::NativeFormat);
#endif
    return m_settings;
}


QString AppSettings::settingsFile()
{
#ifdef WIN32
    return QStandardPaths::writableLocation(QStandardPaths::DataLocation) + "\\"  + QString(DEFAULT_APPNAME) + "\\" +QString(DEFAULT_CONFIGURATION_FILENAME) + QString(".ini");
#else
    return QDir::homePath() +"/.config/" + QString(DEFAULT_APPNAME) + "/" + QString(DEFAULT_CONFIGURATION_FILENAME) +QString(".conf");
#endif
}


QString AppSettings::language(const int languageIndex)
{
    switch (languageIndex) {
    case en:
        return "en";
        break;
    case es:
        return "es";
        break;
    case fr:
        return "fr";
        break;
    case ro:
        return "ro";
        break;
    default:
        break;
    }
    return "en";
}
