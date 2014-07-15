#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Create a new open action with an icon, keyboard shortcut and
    // info-text for the status bar
    openAct = new QAction("&Open...", this);
    openAct->setIcon(QIcon("image/open.png"));
    openAct->setShortcut(tr("Ctrl+O"));
    openAct->setStatusTip(tr("Open an existing file"));
    connect(openAct, SIGNAL(triggered()), this, SLOT(openFile()));

    // Add the action to the menu
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(openAct);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openFile()
{
    // Define 2 filter options - one for document and one for all files
    // The filter mask is automatically parsed, ";;" seperates lines
    QString fileName = QFileDialog::getOpenFileName(this, "Please choose a file to open", QString(),
                                                    tr("GCode (*.gcode);;All files (*.*)"));
    openFile(fileName);
}

void MainWindow::updateCurrentFileName(QString targetFileName)
{
    // Check if any changes is made in the current file
    // The file is new
    if (currentFileName.isEmpty()) {
        if (!(ui->textEdit->toPlainText()).isEmpty()){
            int confirm = QMessageBox::question(this, tr("Quit Action"),
                                                tr("This is a new file, do you want to save it?"),
                                                QMessageBox::Yes | QMessageBox::No);

            if (confirm == QMessageBox::Yes) {
                QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), QString(),
                                                                tr("GCode (*.gcode);;All files (*.*)"));
                saveFile(fileName);
            }
        }
    }
    // The file is not new
    else {
        QFile file(currentFileName);
        if (file.open(QIODevice::ReadOnly)) {
            QTextStream in(&file);
            QString fileString = in.readAll();
            QString currentString = ui->textEdit->toPlainText();
            if (QString::compare(fileString, currentString) != 0) {
                int confirm = QMessageBox::question(this, tr("Quit Action"),
                                                    tr("The current working file is changed, do you want to save it?"),
                                                    QMessageBox::Yes | QMessageBox::No);

                if (confirm == QMessageBox::Yes) {
                    saveFile(currentFileName);
                }
            }

            file.close();
        }
        else {
            // WHAT TO DO HERE TT______TT
            QMessageBox::critical(this, tr("Error"), tr("Could not open file, save as new file"));
            QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), QString(),
                                                            tr("GCode (*.gcode);;All files (*.*)"));
            saveFile(fileName);
        }
    }

    // Change the fileName, effectively change the internal open file
    currentFileName = targetFileName;
    ui->currentFileName->setText(currentFileName);
}

void MainWindow::openFile(QString fileName)
{
    updateCurrentFileName(fileName);
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
            return;
        }
        QTextStream in(&file);
        ui->textEdit->setText(in.readAll());
        file.close();
    }
}

// save everything in the text editor to the file named fileName
void MainWindow::saveFile(QString fileName){
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly)) {
            // error message
            QMessageBox::critical(this, tr("Error"), tr("Could not save to this file"));
            return;
        } else {
            QTextStream stream(&file);
            stream << ui->textEdit->toPlainText();
            stream.flush();
            file.close();
        }
    }
    else {
        // error message
        QMessageBox::critical(this, tr("Error"), tr("The file name is empty"));
    }
}

void MainWindow::on_saveButton_clicked()
{
    if (currentFileName.isEmpty()) {
        currentFileName = QFileDialog::getSaveFileName(this, tr("Save File"), QString(),
                                                       tr("GCode (*.gcode);;All files (*.*)"));
    }
    saveFile(currentFileName);
}

void MainWindow::on_saveAsButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), QString(),
                                                    tr("GCode (*.gcode);;All files (*.*)"));
    saveFile(fileName);
}

void MainWindow::on_discardButton_clicked()
{
    // Show the confirmation dialog
    int confirm = QMessageBox::question(this, tr("Confirm Discard"),
                                        tr("Are you sure you want to discard all the changes?"),
                                        QMessageBox::Yes | QMessageBox::No);

    if (confirm == QMessageBox::Yes) {
        openFile(currentFileName);
    }
}

void MainWindow::on_mixButton_clicked()
{
    if (changeRatio() == 0)
    {
        // Successfully mixed
        QMessageBox::information(this, tr("Mixed Successfully"), tr("The output has been mixed"));
    }
    else
    {
        QMessageBox::information(this, tr("Mixing failed"), tr("Mixing failed"));
    }
    // Change current working file to avoid save to the input file
    updateCurrentFileName(mixedGCodeFileName);
}

void MainWindow::on_origGCodeLocation_clicked()
{
    origGCodeFileName = QFileDialog::getOpenFileName(this, tr("Original GCode Location"), QString(),
                                                     tr("GCode (*.gcode);;All files (*.*)"));

    openFile(origGCodeFileName);
}

void MainWindow::on_mixedGCodeLocation_clicked()
{
    mixedGCodeFileName = QFileDialog::getOpenFileName(this, tr("Mixed GCode Location"), QString(),
                                                      tr("GCode (*.gcode);;All files (*.*)"));
}

void MainWindow::on_startingRatio1_valueChanged(int arg1)
{
    starting_ratios[0] = arg1;
}

void MainWindow::on_startingRatio2_valueChanged(int arg1)
{
    starting_ratios[1] = arg1;
}

void MainWindow::on_startingRatio3_valueChanged(int arg1)
{
    starting_ratios[2] = arg1;
}

void MainWindow::on_endingRatio1_valueChanged(int arg1)
{
    ending_ratios[0] = arg1;
}

void MainWindow::on_endingRatio2_valueChanged(int arg1)
{
    ending_ratios[1] = arg1;
}

void MainWindow::on_endingRatio3_valueChanged(int arg1)
{
    ending_ratios[2] = arg1;
}

void MainWindow::calibrateRatios()
{
    qint32 totalOutput;

    totalOutput = starting_ratios[0] + starting_ratios[1] + starting_ratios[2];
    if (totalOutput != 100) {
        starting_ratios[0] = (int)(starting_ratios[0] * 100 / totalOutput);
        starting_ratios[1] = (int)(starting_ratios[1] * 100 / totalOutput);
        starting_ratios[2] = (int)(starting_ratios[2] * 100 / totalOutput);
        if (starting_ratios[0] != 0) starting_ratios[0] = 100 - starting_ratios[1] - starting_ratios[2];
        else if (starting_ratios[1] != 0) starting_ratios[1] = 100 - starting_ratios[0] - starting_ratios[2];
        else if (starting_ratios[2] != 0) starting_ratios[2] = 100 - starting_ratios[0] - starting_ratios[1];
    }

    totalOutput = ending_ratios[0] + ending_ratios[1] + ending_ratios[2];
    if (totalOutput != 100) {
        ending_ratios[0] = (int)(ending_ratios[0] * 100 / totalOutput);
        ending_ratios[1] = (int)(ending_ratios[1] * 100 / totalOutput);
        ending_ratios[2] = (int)(ending_ratios[2] * 100 / totalOutput);
        if (ending_ratios[0] != 0) ending_ratios[0] = 100 - ending_ratios[1] - ending_ratios[2];
        else if (ending_ratios[1] != 0) ending_ratios[1] = 100 - ending_ratios[0] - ending_ratios[2];
        else if (ending_ratios[2] != 0) ending_ratios[2] = 100 - ending_ratios[0] - ending_ratios[1];
    }

    // UPDATE THE NEW RATIOS TO THE UI
    ui->startingRatio1->setValue(starting_ratios[0]);
    ui->startingRatio2->setValue(starting_ratios[1]);
    ui->startingRatio3->setValue(starting_ratios[2]);
    ui->endingRatio1->setValue(ending_ratios[0]);
    ui->endingRatio2->setValue(ending_ratios[1]);
    ui->endingRatio3->setValue(ending_ratios[2]);
}

// Gradually change the mixing ratio from start ratios to end ratios
qint8 MainWindow::changeRatio()
{
    QString line;
    quint32 totalLines;
    quint32 lineCount; // only count the movement line, like G1
    QVector<int> current_ratios{3,0};
    QVector<int> ratio_diffs{3,0};
    qint32 primaryRatio = 0;
    qint32 secondRatio = 0;
    qint32 thirdRatio = 0;
    qreal secondFinished = 0; // In percentage
    qreal thirdFinished = 0; // In percentage
    qint32 updateInterval = 0; // in number of lines

    QString output;
    QString input = ui->textEdit->toPlainText();
    QTextStream origGCode(&input);
    QTextStream newGCode(&output);

    // defensive programming
    calibrateRatios();

    // Initialize the current ratio variables
    current_ratios[0] = starting_ratios[0];
    current_ratios[1] = starting_ratios[1];
    current_ratios[2] = starting_ratios[2];
    // The ratio diff variables
    ratio_diffs[0] = ending_ratios[0] - starting_ratios[0];
    ratio_diffs[1] = ending_ratios[1] - starting_ratios[1];
    ratio_diffs[2] = ending_ratios[2] - starting_ratios[2];
    // Find the ratio with most change for Bresenham algorithm
    primaryRatio = 0;
    for (int i = 0; i < 3; i++) {
        if (qAbs(ratio_diffs[i]) > qAbs(ratio_diffs[primaryRatio]))
            primaryRatio = i;
    }

    totalLines = 0;
    line = origGCode.readLine();
    while (!line.isNull()) {
        if (line[0] == 'G') totalLines++;
        line = origGCode.readLine();
    }
    updateInterval = totalLines / qAbs(ratio_diffs[primaryRatio]);

    // Move the file pointer to the begining
    if (!origGCode.seek(0)) return 1;

    lineCount = 0;
    secondRatio = (primaryRatio + 1) % 3; // So that secondaryRatio != primaryRatio
    thirdRatio = (primaryRatio + 2) % 3; // So we have primary ratio != secondRatio != thirdRatio
    // set the starting ratios
    newGCode << "M206 T3 P945" << " X" << starting_ratios[0] << endl;
    newGCode << "M206 T3 P949" << " X" << starting_ratios[1] << endl;
    newGCode << "M206 T3 P953" << " X" << starting_ratios[2] << endl;

    line = origGCode.readLine();
    while (!line.isNull()) {
        if (line[0] == 'G') lineCount++;
        // show the cooking plate to the user before turn-off all motors
        if (line.contains("M84"))
            newGCode << "G1 Y200" << endl;

        newGCode << line << endl;
        if (lineCount == updateInterval) {
            lineCount = 0;
            // Update the primary extruder ratio
            current_ratios[primaryRatio] += ratio_diffs[primaryRatio] / qAbs(ratio_diffs[primaryRatio]);
            newGCode << "M206 T3 P" << 945 + 4*primaryRatio << " X" << current_ratios[primaryRatio] << endl;
            // Compute the percent of change finished in second extruder
            if (ending_ratios[secondRatio] - starting_ratios[secondRatio] == 0)
                secondFinished = 1;
            else
                secondFinished = qAbs((current_ratios[secondRatio] - starting_ratios[secondRatio]) * 1.0
                                      / (ending_ratios[secondRatio] - starting_ratios[secondRatio]));
            // Compute the percent of change finished in third extruder
            if (ending_ratios[thirdRatio] - starting_ratios[thirdRatio] == 0)
                thirdFinished = 1;
            else
                thirdFinished = qAbs((current_ratios[thirdRatio] - starting_ratios[thirdRatio]) * 1.0
                                     / (ending_ratios[thirdRatio] - starting_ratios[thirdRatio]));
            if (secondFinished <= thirdFinished) {
                // update the second ratio
                current_ratios[secondRatio] += ratio_diffs[secondRatio] / qAbs(ratio_diffs[secondRatio]);
                newGCode << "M206 T3 P" << 945 + 4 * secondRatio << " X" << current_ratios[secondRatio] << endl;
            }
            else {
                // update the third ratio
                current_ratios[thirdRatio] += ratio_diffs[thirdRatio] / qAbs(ratio_diffs[thirdRatio]);
                newGCode << "M206 T3 P" << 945 + 4 * thirdRatio << " X" << current_ratios[thirdRatio] << endl;
            }
        }
        line = origGCode.readLine();
    }

    // Set the ending ratios
    newGCode << "M206 T3 P945" << " X" << ending_ratios[0] << endl;
    newGCode << "M206 T3 P949" << " X" << ending_ratios[1] << endl;
    newGCode << "M206 T3 P953" << " X" << ending_ratios[2] << endl;

    origGCode.flush();
    newGCode.flush();

    // Set to the textEdit display
    ui->textEdit->setText(output);

    return 0;
}

void MainWindow::on_origGCodeComboBox_currentIndexChanged(int index)
{

}
