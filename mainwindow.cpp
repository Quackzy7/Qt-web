#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QWebEngineView>
#include <QPushButton>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Access UI elements
    QPushButton *backButton = ui->backButton;
    QPushButton *forwardButton = ui->forwardButton;
    QWebEngineView *webView = ui->webEngineView;

    // Load a default webpage
    webView->load(QUrl("https://www.qt.io"));

    // Connect buttons to webView actions
    connect(backButton, &QPushButton::clicked, webView, &QWebEngineView::back);
    connect(forwardButton, &QPushButton::clicked, webView, &QWebEngineView::forward);
}


MainWindow::~MainWindow()
{
    delete ui;
}
