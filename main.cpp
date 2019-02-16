#include "dbox.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	DBOX w;
	w.show();

	return a.exec();
}
