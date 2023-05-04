#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>
#include <QTimer>
#include <QGLWidget>
#include <vector>
#include <QTime>
#include "fractal_tree.h"
using namespace std;
class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    vector <double> x; // координаты точек по оси x
    vector <double> y;  // координаты точек по оси y
    double angle = 60.0;
    int iter = 4;
    int width = 3;
    int height = 3;
    explicit GLWidget(QWidget* parent = 0);
    ~GLWidget();
    void clear(); //очистка холста
    void initializeGL() override;
    void paintGL() override; // отрисовка примитивов
    void resizeGL(int w, int h) override;
private:
    QTimer timer;
protected:
    void mousePressEvent(QMouseEvent * event) override; // эвент нажатия мыши по холсту
};

#endif // GLWIDGET_H
