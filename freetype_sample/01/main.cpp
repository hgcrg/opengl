#include "Widget.h"
#include <QApplication>
int main(int argc, char ** argv)
{
    QApplication app(argc, argv);
    Widget w;
    w.setGeometry(0, 0, 1024, 700);
    w.show();
    return app.exec();
}
