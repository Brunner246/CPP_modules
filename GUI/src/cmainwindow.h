//
// Created by michael.brunner on 14/11/2023.
//

#ifndef GUI_CMAINWINDOW_H
#define GUI_CMAINWINDOW_H

#include <QMainWindow>
#include "gui_api.h"

QT_BEGIN_NAMESPACE
namespace Ui { class CMainWindow; }
QT_END_NAMESPACE

class GUI_API CMainWindow : public QMainWindow
{
Q_OBJECT

public:
	explicit CMainWindow(QWidget* parent = nullptr);

	~CMainWindow() override;

private:
	Ui::CMainWindow* ui;
};


#endif //GUI_CMAINWINDOW_H
