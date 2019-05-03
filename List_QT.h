#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_List_QT.h"

class List_QT : public QMainWindow
{
	Q_OBJECT // asi vorbesi grnak signal slot sarkenk oktakortsenk

public:
	List_QT(QWidget *parent = Q_NULLPTR);


	
public slots:
	void OnCLicked();
	void OnCLicked_Add();
	void setItemm(const QString& str);
private:
	Ui::List_QTClass ui;
};
