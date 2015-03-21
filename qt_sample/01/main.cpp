#include <QApplication>
#include <QFile>
#include "Frame.h"
int main(int argc, char ** argv)
{
    QApplication app(argc, argv);
    QFile file("01_qt.css");
    Frame f;

    file.open(QFile::ReadOnly);
    f.setStyleSheet(file.readAll());
    f.show();
    return app.exec();
}
