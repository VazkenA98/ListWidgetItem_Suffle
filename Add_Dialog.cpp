#include "Add_Dialog.h"

  
#include <fstream>  
#include <sstream>
#include <QIODevice>
#include <QString>
#include <qfile.h>
#include <QFile>
#include <qtextstream.h>
#include <QMessageBox>
//#include "List_QT.h"
using namespace std;
Add_Dialog::Add_Dialog(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	

	connect(ui.Add_but, SIGNAL(clicked(bool)), this, SLOT(OnCLicked()));
	
	
	
}
QString Convert(const QString &s)
{
	return s.toLower();
	/*string str = s.toStdString();
	int ln = str.length();
	for (int i = 0; i < ln; i++)
	{
			str[i] = tolower(str[i]);
	}
	QString qstr = QString::fromStdString(str);
	return qstr;*/
}

void Add_Dialog::OnCLicked()
{

	QString texte;
	QFile fichier("D:\\c++MFC\\List_QT\\list.txt");

	if (fichier.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		texte = fichier.readAll();
		fichier.close();
	}
	QRegExp rx(","); //RegEx for ',' 
	QStringList list = texte.split(rx);
	/*for (int i = 0; i < list.size(); i++) {
		QString st = list[i];
		QStringList list2.append(Convert(st));
	}*/
	QString s1 = ui.Add_text->text();
	QString s2 = Convert(s1);
	int count = 0;
	for (int i = 0; i < list.size(); i++) {
		if (s2.compare(list[i]) == 0) {
			ui.Add_text->setText(s2);
			QString st = s2;
			emit send(st); // emit =  define enel arants emitiyal gernank krel payts ge khankarenk kani gerna elal send() urish function ela
			count++;
			break;
		}
		
	}
	if (count == 0) {
		QMessageBox msgBox;
		msgBox.setText("no item");
		msgBox.exec();
	}

	

}






Add_Dialog::~Add_Dialog()
{	
}
