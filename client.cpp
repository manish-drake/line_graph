#include "client.h"

void Client::refresh()
{
    setPoints(getRandPointsList());
}

Client::Client(QObject *parent) :
    QObject(parent),
    m_points{getRandPointsList()}
{
    this->startTimer(1000);
}


QList<int> Client::points()
{
    return m_points;
}

void Client::setPoints(QList<int> points)
{
    m_points = points;

    emit pointsChanged(points);
}

void Client::timerEvent(QTimerEvent *event)
{
    refresh();
}
