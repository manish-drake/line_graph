#include "client.h"
bool flag = false;
void Client::refresh()
{
    setPoints(getRandPointsList());
}

Client::Client(QObject *parent) :
    QObject(parent),
    m_points{getRandPointsList()}
{
    this->startTimer(200);
    setRefPoints(getRandPointsList());
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

QList<int> Client::refPoints()
{
    return m_refPoints;
}

void Client::setRefPoints(QList<int> points)
{
    m_refPoints = points;
    emit refPointsChanged(points);
}

void Client::timerEvent(QTimerEvent *event)
{
    refresh();
}
