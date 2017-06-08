#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <time.h>

class Client : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<int> points READ points WRITE setPoints NOTIFY pointsChanged)
    Q_PROPERTY(QList<int> refPoints READ refPoints WRITE setRefPoints NOTIFY refPointsChanged)
public:
    Q_INVOKABLE void refresh();
    explicit Client(QObject *parent = 0);

    QList<int> points();
    void setPoints(QList<int> points);

    QList<int> refPoints();
    void setRefPoints(QList<int> points);
protected:
    void timerEvent(QTimerEvent *event);
signals:
    void pointsChanged(QList<int> points);
    void refPointsChanged(QList<int> points);
public slots:
private:
    QList<int> m_points;
    QList<int> m_refPoints;
    QList<int> getRandPointsList(){
        QList<int> list;
//        srand((unsigned)time(0));
        int random_integer;
        int lowest=0, highest=20, step = highest/2;
        int range=(highest-lowest)+1;
        for(int index=0; index<400; index++){
            random_integer = lowest+int(range*rand()/(RAND_MAX + 1.0));
            list.push_back(random_integer);

            lowest = (random_integer - step) < 0? 0: (random_integer - step);
            highest = (random_integer + step) > 255? 255: (random_integer + step);
        }
        return list;
    }

};
#endif // CLIENT_H
