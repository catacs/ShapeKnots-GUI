/***************************************************************
 *  @author: Catalin Stanciu
 *  @email: catacsdev@gmail.com
 *  Copyright (C) 2014
 * *************************************************************/

#include "configuration.h"
#include "ui_configuration.h"

Configuration::Configuration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Configuration)
{
    ui->setupUi(this);
}

Configuration::~Configuration()
{
    delete ui;
}
