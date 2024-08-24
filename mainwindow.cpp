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
    webView->load(QUrl("https://www.google.com"));

    // Connect buttons to webView actions
    connect(backButton, &QPushButton::clicked, webView, &QWebEngineView::back);
    connect(forwardButton, &QPushButton::clicked, webView, &QWebEngineView::forward);

    // Connect the returnPressed signal of the QLineEdit to the slot
    connect(ui->lineEdit, &QLineEdit::returnPressed, this, &MainWindow::onUrlEntered);

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onUrlEntered()
{
    QString urlText = ui->lineEdit->text();

    // Basic check to see if the input is a URL
    if (!urlText.startsWith("http://") && !urlText.startsWith("https://")) {
        // Treat it as a search query if it's not a URL
        urlText = "https://www.google.com/search?q=" + urlText;
    }

    QUrl url = QUrl::fromUserInput(urlText);
    ui->webEngineView->setUrl(url);
}

