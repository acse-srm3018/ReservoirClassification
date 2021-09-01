#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define _WIN32_WINNT  0x0500

#include <QMainWindow>
#include <QtWidgets>
#include <QTimer>
#include <QFile>
#include <QString>
#include <QClipboard>
#include <QIODevice>
#include <QDebug>
#include <QShowEvent>
#include <QMessageBox>
#include <QStringList>
#include <windows.h>
#include <winuser.h>
#include <QFileDialog>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    void showEvent(QShowEvent *);

private:
    Ui::MainWindow *ui;
    int mult;
    QTimer *timer;
    QClipboard *clipboard;
    QString line,path;
    QFile *file;
    void nextKeyPress();
public slots:
    void startButton();
    void getFile();
    void nextKeyEvent();
};

#endif // MAINWINDOW_H
