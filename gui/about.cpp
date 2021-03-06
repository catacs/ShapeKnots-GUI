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
#include "about.h"
#include "ui_about.h"
#include "appsettings.h"

// About constructor
About::About(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);
    ui->m_versionLabel->setText(AppSettings::version());
}


// About destructor
About::~About()
{
    delete ui;
}


// Called when something changed in the interface
void About::changeEvent(QEvent *event)
{
    // When the language changed we process it
    if (event->type() == QEvent::LanguageChange)
    {
            // retranslate designer form (single inheritance approach)
            ui->retranslateUi(this);
    }

    // remember to call base class implementation
    QDialog::changeEvent(event);
}
