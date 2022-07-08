#include <QApplication>
#include <QPushButton>
#include "src/Home/Home.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    (new Home())->show();
    return QApplication::exec();
}
