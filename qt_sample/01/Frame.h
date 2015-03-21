#ifndef FRAME__HH__
#define FRAME__HH__
#include <QWidget>

class Frame : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QColor m_color READ getColor WRITE setColor)
public:
    Frame(QWidget * parent = 0);
    ~Frame();
public:
    QColor getColor();
    void   setColor(QColor & color);
protected:
    virtual void paintEvent(QPaintEvent * event);
private:
    QColor m_color;
};
#endif //FRAME__HH__
