/*
License

Filedialog use

Copyright (C) 2025 Emrullah Enis Çetinkaya and contributors

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see https://www.gnu.org/licenses/.*/
#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton,&QPushButton::clicked,this,&MainWindow::file_dialog_open_func);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::file_dialog_open_func(){
    QString filename=QFileDialog::getOpenFileName(this,"File Select",QDir::homePath(),"All Files(*.*);;Text File(*.txt);;Images(*.png *.jpg)");
    if(filename.isEmpty()){
        QMessageBox::critical(this,"Error","No File Selected");
    }
    else{
        ui->label->setText(filename);
    }
}
