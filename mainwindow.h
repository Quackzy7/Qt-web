#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWebEngineView>
#include "history.h" // Include your History class

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    History history;
 QStringList historyList;    // History object to manage browsing history

private slots:
    void onUrlEntered();
    void onHistoryButtonClicked(); // Slot for history button
};

#endif // MAINWINDOW_H
