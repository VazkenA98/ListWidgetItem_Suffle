#include "List_QT.h"
#include "Add_Dialog.h"
using namespace std;
#include<iostream>
List_QT::List_QT(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.shuffle_but, SIGNAL(clicked(bool)), this, SLOT(OnCLicked()));
	connect(ui.Add_Main, SIGNAL(clicked(bool)), this, SLOT(OnCLicked_Add()));
	QListWidgetItem * itemno0 = new QListWidgetItem("itemno0");
	QListWidgetItem * itemno1 = new QListWidgetItem("itemno1");
	QListWidgetItem * itemno2 = new QListWidgetItem("itemno2");
	QListWidgetItem * itemno3 = new QListWidgetItem("itemno3");
	
	

	ui.listWidget->addItem(itemno0);
	ui.listWidget->addItem(itemno1);
	ui.listWidget->addItem(itemno2);
	ui.listWidget->addItem(itemno3);
	
}
int randomfunc(int j)
{
	return rand() % j;
}
void List_QT::setItemm(const QString& str)
{
	ui.listWidget->addItem(str);
}
void List_QT::OnCLicked()
{
	QVector<QString> v;
	int size = ui.listWidget->count();
	v.resize(size);
	for (int i = 0; i < ui.listWidget->count(); i++) {
		QListWidgetItem * item = ui.listWidget->item(i);
		v[i] = item->text();
	}
	srand(unsigned(time(0)));
	random_shuffle(v.begin(), v.end());
	random_shuffle(v.begin(), v.end(), randomfunc);
	ui.listWidget->clear();
	for (int i = 0; i < v.size(); i++) {
		ui.listWidget->addItem(v[i]);
	}
	
}
void List_QT::OnCLicked_Add() {
	Add_Dialog *d = new Add_Dialog();
	
	connect(d, SIGNAL(send(const QString&)), this, SLOT(setItemm(const QString&)));
	d->show();
}
