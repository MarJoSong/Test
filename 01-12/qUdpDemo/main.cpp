#include "udp1.h"
#include "udp2.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Udp1 w;
    w.show();
    
    Udp2 v;
    v.show();
    
    return a.exec();
}
