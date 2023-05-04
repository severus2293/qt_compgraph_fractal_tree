#include "glwidget.h"
#include <QTextStream>
#include <QMouseEvent>
#include <cmath>
#include <QLabel>
GLWidget::GLWidget(QWidget * parent):QGLWidget(parent) // инициализируем базовые параметры
{
connect(&timer,SIGNAL(timeout()),this,SLOT(updateGL()));
timer.start(100);
}


void GLWidget::clear() //очистить холст
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    this->paintGL();
}

GLWidget::~GLWidget()
{
}

void GLWidget::initializeGL() //задать базовый цвет для холста
{

    glClearColor(0.2,0.2,0.2,1);
}








void GLWidget::mousePressEvent(QMouseEvent * event) //событие нажатия на холст для отрисовки точки
{

        // границы окна OpenGL
        double x0 = -1.3;
        double y0 =  1.0;
        double x1 =  1.3;
        double y1 = -1.0;

        // переводим координаты окна в координаты окна OpenGL
        double xAtPress = double(event->x()) / this->geometry().size().width() * (x1 - x0) + x0;
        double yAtPress = double(event->y()) / this->geometry().size().height() * (y1 - y0) + y0;
        x.push_back(xAtPress);
        y.push_back(yAtPress);
        QTextStream out(stdout);

    out << xAtPress << endl;
    out << yAtPress  << endl;

}













void GLWidget::paintGL()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // очистка буфера
    glColor3f(1.0,0,0.0);
    double width = 0.25*this->width/10.0;
    double height = 0.5*this->height/10.0;
    Fractal_Tree* obj = new Fractal_Tree(new Node(0.0,-1.2,width,height,0.5,0.5),angle,width,height);
    obj->Build_Fractal_Tree(iter);
    glBegin(GL_LINES);
    obj->InOrderTravers(obj->root);
    glEnd();
    delete obj;

}

void GLWidget::resizeGL(int w, int h)
{
   glViewport(0,0,w,h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
  // updateGL();
}
