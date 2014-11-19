#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QFileDialog>
#include "finddialog.h"

class AddressBook : public QWidget
{
    Q_OBJECT

public:
    enum Mode { NavigationMode, AddingMode, EditingMode };
    AddressBook(QWidget *parent = 0);
    ~AddressBook();
public slots:
    void addContact();
    void submitContact();
    void cancel();
    void next();
    void previous();
    void editContact();
    void removeContact();
    void findContact();
    void saveToFile();
    void loadFromFile();
private:
    void updateInterface(Mode mode);
    QPushButton *addButton;
    QPushButton *submitButton;
    QPushButton *cancelButton;
    QPushButton *nextButton;
    QPushButton *previousButton;
    QPushButton *editButton;
    QPushButton *removeButton;
    QPushButton *findButton;
    QPushButton *loadButton;
    QPushButton *saveButton;
    QLineEdit *nameLine;
    QTextEdit *addressText;
    QMap<QString, QString> contacts;
    QString oldName;
    QString oldAddress;
    Mode currentMode;
    FindDialog *dialog;
};

#endif // ADDRESSBOOK_H
