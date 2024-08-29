#ifndef HISTORY_H
#define HISTORY_H

#include <QStringList>
#include <QUrl>

class History
{
public:
    History();

    void addUrl(const QUrl &url);
    QUrl goBack();
    QUrl goForward();
    bool canGoBack() const;
    bool canGoForward() const;
    QStringList getAllHistory() const;  // New method to retrieve history

private:
    QStringList history;
    int currentHistoryIndex;

};

#endif // HISTORY_H
