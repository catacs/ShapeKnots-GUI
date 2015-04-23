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

#ifndef APPSETTINGS_H
#define APPSETTINGS_H

#include <QString>
#include <QSettings>
#include "appconstants.h"

/*!
 * \brief The AppSettings class to load and save all settings in the App.
 * It is based on singleton pattern, so the it is not necessary to create
 * the objecct because when it's accesed it's created.
 * To access it use AppSettings::functionToCall()
 */
class AppSettings
{
public:
    enum Language {en, es, fr, ro};

    AppSettings();

    //! Static member to obtain actual app version.
    /*!
     * \sa version()
     * \return version a QString()
     */
    static QString version();
    //! Static member to obtaing app settings
    /*!
     * \sa settings()
     * \return m_settings a QSettings object
     */
    static QSettings *settings();
    //! Static member to obtain the settings file
    /*!
     * \brief settingsFile
     * \return QString with the route to settings file
     */
    static QString settingsFile();
    //! Static member to obatin actual app language
    /*!
     * \brief language
     * \param languageIndex integer value with language Enum value
     * \return QString() with language code.
     */
    static QString language(int languageIndex);
private:
    //! Settings pointer
    /*! Static variable that holds the pointer to QSettings structure */
    static QSettings *m_settings;
};

#endif // APPSETTINGS_H
