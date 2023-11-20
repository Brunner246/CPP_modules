//
// Created by michael.brunner on 14/11/2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_CMainWindow.h" resolved

#include "cmainwindow.h"
#include "ui_CMainWindow.h"


CMainWindow::CMainWindow(QWidget* parent)
		:
		QMainWindow(parent), ui(new Ui::CMainWindow)
{
	ui->setupUi(this);
}

CMainWindow::~CMainWindow()
{
	delete ui;
}

