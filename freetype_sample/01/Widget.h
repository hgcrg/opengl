#ifndef WIDGET__HH__
#define WIDGET__HH__
#include <GL/glew.h>
#include <qgl.h>
#include <boost/smart_ptr.hpp>

class Stage;
class Widget : public QGLWidget
{
    Q_OBJECT
public:
    Widget(QWidget * parent = 0);
    ~Widget();
protected:
    virtual void initializeGL();
    virtual void resizeGL(int w, int h);
    virtual void paintGL();
private:
    boost::shared_ptr<Stage> m_pStage;
};
#endif //WIDGET__HH__
