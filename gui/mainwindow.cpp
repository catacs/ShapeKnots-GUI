#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loadSettings();

    ui->m_optionsWidget->setVisible(ui->m_optionsCheckBox->isChecked());
    connect(ui->m_actionExit,SIGNAL(toggled(bool)), this, SIGNAL(exit()));

    connect(ui->m_runButton, SIGNAL(clicked()),
            this, SIGNAL(start()));
    connect(ui->m_inputBrowse, SIGNAL(clicked()),
            this, SLOT(inputDialog()));
    connect(ui->m_outputBrowse, SIGNAL(clicked()),
            this, SLOT(outputDialog()));
    connect(ui->m_shapeBrowse, SIGNAL(clicked()),
            this, SLOT(shapeDialog()));
    connect(ui->m_diferrentialShapeBrowse,SIGNAL(clicked()),
            this, SLOT(diferentialShapeDialog()));
    connect(ui->m_doubleOffsetBrowse, SIGNAL(clicked()),
            this, SLOT(doubleOffsetDialog()));
    connect(ui->m_singleOffsetBrowse, SIGNAL(clicked()),
            this, SLOT(singleOffsetDialog()));

    connect(ui->m_inputSelected, SIGNAL(textChanged(const QString&)),
            this, SIGNAL(inputSelected(const QString&)));
    connect(ui->m_outputSelected, SIGNAL(textChanged(const QString&)),
            this, SIGNAL(outputSelected(const QString&)));
    connect(ui->m_shapeFileSelected, SIGNAL(textChanged(const QString&)),
            this, SIGNAL(shapeSelected(const QString&)));
    connect(ui->m_differencialShapeFileSelected, SIGNAL(textChanged(const QString&)),
            this, SIGNAL(diferentialShapeSelected(const QString&)));
    connect(ui->m_doubleOffsetSelected, SIGNAL(textChanged(const QString&)),
            this, SIGNAL(doubleOffsetSelected(const QString&)));
    connect(ui->m_singleOffsetSelected, SIGNAL(textChanged(const QString&)),
            this, SIGNAL(singleOffsetSelected(const QString&)));

    connect(ui->m_optionsCheckBox,SIGNAL(clicked(bool)),
            ui->m_optionsWidget, SLOT(setVisible(bool)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::log(const QString &line)
{
    ui->m_commandOutput->append(line);
}

void MainWindow::inputDialog()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                     "",
                                                     tr("Files (*.seq)"));
    ui->m_inputSelected->setText(fileName);
}

void MainWindow::outputDialog()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                     "",
                                                     tr("Files (*.*)"));
    ui->m_outputSelected->setText(fileName);
}

void MainWindow::shapeDialog()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                     "",
                                                     tr("Files (*.*)"));
    ui->m_shapeFileSelected->setText(fileName);
}

void MainWindow::diferentialShapeDialog()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                     "",
                                                     tr("Files (*.*)"));
    ui->m_differencialShapeFileSelected->setText(fileName);
}

void MainWindow::doubleOffsetDialog()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                     "",
                                                     tr("Files (*.*)"));
    ui->m_doubleOffsetSelected->setText(fileName);
}

void MainWindow::singleOffsetDialog()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                     "",
                                                     tr("Files (*.*)"));
    ui->m_singleOffsetSelected->setText(fileName);
}

