#include "List_QT.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	List_QT w;
	w.show();
	return a.exec();
}
