#include "MainWindow.h"
#include "ImageProcessor.h"
#include <QApplication>
#include <sstream>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    if(argc == 2)
    {
        istringstream ss(argv[1]);
        int id =0;
        ss >> id;
        w.startAutoMode(id);
    }
    return a.exec();
}
