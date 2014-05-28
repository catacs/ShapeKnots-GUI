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
