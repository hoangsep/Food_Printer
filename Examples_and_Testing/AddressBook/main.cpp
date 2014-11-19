#include "addressbook.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    AddressBook addressBook;
    addressBook.show();

    return app.exec();
}
