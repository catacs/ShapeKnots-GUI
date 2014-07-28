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

#include "configuration.h"
#include "ui_configuration.h"
#include "appsettings.h"

Configuration::Configuration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Configuration)
{
    ui->setupUi(this);

    QSettings *settings = AppSettings::settings();
    int languageIndex = settings->value("Language/Language",0).toInt();
    ui->comboBox->setCurrentIndex(languageIndex);

    connect(ui->m_cancelButton, SIGNAL(clicked()),
            this, SLOT(closeRequest()));
    connect(ui->m_acceptButton, SIGNAL(clicked()),
            this, SIGNAL(acceptRequest()));
}

Configuration::~Configuration()
{
    delete ui;
}


void Configuration::closeRequest()
{
    this->close();
}


void Configuration::changeEvent(QEvent *event)
{
    if (event->type() == QEvent::LanguageChange)
    {
            // retranslate designer form (single inheritance approach)
            ui->retranslateUi(this);
    }

    // remember to call base class implementation
    QDialog::changeEvent(event);
}


QString Configuration::shapeKnotsPath()
{
    return ui->m_shapeKnotsPathEdit->text();
}


QString Configuration::datapath()
{
    return ui->m_datatablesPathEdit->text();
}


QString Configuration::drawPath()
{
    return ui->m_drawPathEdit->text();
}

int Configuration::language()
{
    return ui->comboBox->currentIndex();
}
