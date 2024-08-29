#include "history.h"

History::History() : currentHistoryIndex(-1) {}

void History::addUrl(const QUrl &url)
{
    if (currentHistoryIndex < history.size() - 1) {
        history = history.mid(0, currentHistoryIndex + 1);
    }
    history.append(url.toString());
    currentHistoryIndex = history.size() - 1;
}

QUrl History::goBack()
{
    if (canGoBack()) {
        currentHistoryIndex--;
        return QUrl(history.at(currentHistoryIndex));
    }
    return QUrl();
}

QUrl History::goForward()
{
    if (canGoForward()) {
        currentHistoryIndex++;
        return QUrl(history.at(currentHistoryIndex));
    }
    return QUrl();
}

bool History::canGoBack() const
{
    return currentHistoryIndex > 0;
}

bool History::canGoForward() const
{
    return currentHistoryIndex < history.size() - 1;
}

QStringList History::getAllHistory() const  // Return the entire history list
{
    return history;
}
