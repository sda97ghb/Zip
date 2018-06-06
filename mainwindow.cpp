#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "zipdir.h"

#include <QDirIterator>
#include <QFileDialog>

#include <QtDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_zipDirectoryButton_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, "Select directory", "/home/dmitry/a/",
                                                    QFileDialog::ShowDirsOnly |
                                                    QFileDialog::DontResolveSymlinks);
    QString output = QFileDialog::getSaveFileName(this, "Save zip as", "/home/dmitry/output.zip");
    ZipDir zipDir(dir, output);
    zipDir.execute();
}

void MainWindow::on_zipFileButton_clicked()
{

}
