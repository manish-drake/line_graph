#ifndef LINEGRAPH_H
#define LINEGRAPH_H

#include <QtQuick/QQuickPaintedItem>
#include <QColor>

class LineGraph : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)
    Q_PROPERTY(QList<int> points READ points WRITE setPoints NOTIFY pointsChanged)
    Q_PROPERTY(int size READ size WRITE setSize NOTIFY sizeChanged)

public:
    explicit LineGraph(QQuickItem *parent = 0);

    QColor color() const;
    void setColor(const QColor &color);

    QList<int> points();
    void setPoints(QList<int> points);

    int size();
    void setSize(int size);

    void paint(QPainter *painter);

signals:
    void colorChanged(const QColor &color);
    void pointsChanged(const QList<int> points);
    void sizeChanged(int size);
public slots:
private:
    QColor m_color;
    QList<int> m_points;
    int m_size = 0;
};

#endif // LINEGRAPH_H
