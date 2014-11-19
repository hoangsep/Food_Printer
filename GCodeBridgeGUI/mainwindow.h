#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDir>
#include <QMessageBox>
#include <QVector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void openFile();

    void openFile(QString fileName);

    void on_saveButton_clicked();

    void on_discardButton_clicked();

    void saveFile(QString fileName);

    void on_mixButton_clicked();

    void on_origGCodeLocation_clicked();

    void on_mixedGCodeLocation_clicked();

    void on_saveAsButton_clicked();

    void on_startingRatio1_valueChanged(int arg1);

    void on_startingRatio2_valueChanged(int arg1);

    void on_startingRatio3_valueChanged(int arg1);

    void on_endingRatio1_valueChanged(int arg1);

    void on_endingRatio2_valueChanged(int arg1);

    void on_endingRatio3_valueChanged(int arg1);  

    void on_origGCodeComboBox_activated(const QString &arg1);

    void on_mixedGCodeComboBox_activated(const QString &arg1);

private:
    // Private variables
    Ui::MainWindow *ui;
    QMenu *fileMenu;
    QAction *openAct;
    QString origGCodeFileName;
    QString mixedGCodeFileName;
    QString currentFileName;

    // The start ratio of each component in the totalFeed, sum of them = 1
    QVector<int> starting_ratios{3,0};
    // The end ratio of each component in the totalFeed, sum of them = 1
    QVector<int> ending_ratios{3,0};

    // Private functions
    qint8 calibrateRatios();
    qint8 changeRatio();
    void updateCurrentFileName(QString targetFileName);
    void updateOrigBox(QString newLocation);
    void updateMixedBox(QString newLocation);
};

#endif // MAINWINDOW_H
