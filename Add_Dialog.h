#pragma once

#include <QWidget>
#include "ui_Add_Dialog.h"

class Add_Dialog : public QWidget
{
	Q_OBJECT
protected:
	QString strValue;
public:
	Add_Dialog(QWidget *parent = Q_NULLPTR);
	~Add_Dialog();

signals:
	void send(const QString& str);

public slots:
	void OnCLicked();
private:
	Ui::Add_Dialog ui;
};
