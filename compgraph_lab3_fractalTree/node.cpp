#include "node.h"
#include <cmath>

Node *Node::rotate_left(double angle, double shift_x, double shift_y,double scale_x, double scale_y)
{
    double coef = 1.2;
    //double new_x1 = (x1-x3)*cos(angle) + (y1-y3)*sin(angle) + x3 - shift_x;
    double new_x1 = x1 - shift_x;
    //double new_x2 = (x2-x3)*cos(angle) + (y2-y3)*sin(angle) + x3 - shift_x; //левый верхний x2*cos(angle) - y2*sin(angle)
    double new_x2 = (x2-x1)*cos(angle) - (y2-y1)*sin(angle) + x1 - shift_x;
    //double new_x3 = x3 - shift_x; //правый верхний
    double new_x3 = (x3-x1)*cos(angle) - (y3-y1)*sin(angle) + x1 - shift_x;
    //double new_x4 = (x4-x3)*cos(angle) + (y4-y3)*sin(angle) + x3 - shift_x;
    double new_x4 = (x4-x1)*cos(angle) - (y4-y1)*sin(angle) + x1 - shift_x;
    //double new_y1 = -(x1-x3)*sin(angle) + (y1-y3)*cos(angle) + y3 - shift_y;
    double new_y1 = y1 - shift_y;
    //double new_y2 = -(x2-x3)*sin(angle) + (y2-y3)*cos(angle) + y3 - shift_y; //левый верхний x2*sin(angle) + y2*cos(angle)
    double new_y2 = (x2-x1)*sin(angle) + (y2-y1)*cos(angle) + y1 - shift_y;
   // double new_y3 = y3 - shift_y; // правый верхний
    double new_y3 = (x3-x1)*sin(angle) + (y3-y1)*cos(angle) + y1 - shift_y;
    //double new_y4 = -(x4-x3)*sin(angle) + (y4-y3)*cos(angle) + y3 - shift_y ;
    double new_y4 = (x4-x1)*sin(angle) + (y4-y1)*cos(angle) + y1 - shift_y ;

   // return new Node(new_x4,new_x1,new_x2,new_x3,new_y4,new_y1,new_y2,new_y3,-1,scale_x,scale_y);
    return new Node(new_x1,new_x2,new_x3,new_x4,new_y1,new_y2,new_y3,new_y4,-1,scale_x,scale_y);
}

Node *Node::rotate_right(double angle, double shift_x, double shift_y,double scale_x, double scale_y)
{
    //double new_x1 = (x1-x2)*cos(angle) - (y1-y2)*sin(angle) + x2 + shift_x;
    double new_x1 = (x1-x4)*cos(angle) + (y1-y4)*sin(angle) + x4 + shift_x;
    //double new_x2 = x2 + shift_x; //левый верхний x2*cos(angle) - y2*sin(angle)
    double new_x2 = (x2-x4)*cos(angle) + (y2-y4)*sin(angle) + x4 + shift_x;
    //double new_x3 = (x3-x2)*cos(angle) - (y3-y2)*sin(angle) + x2 + shift_x; //правый верхний
    double new_x3 = (x3-x4)*cos(angle) + (y3-y4)*sin(angle) + x4 + shift_x;
   // double new_x4 = (x4-x2)*cos(angle) - (y4-y2)*sin(angle) + x2 + shift_x;
     double new_x4 = x4 + shift_x;
    //double new_y1 = (x1-x2)*sin(angle) + (y1-y2)*cos(angle) + y2 - shift_y;
     double new_y1 = -(x1-x4)*sin(angle) + (y1-y4)*cos(angle) + y4 - shift_y;
    //double new_y2 = y2 - shift_y; //левый верхний x2*sin(angle) + y2*cos(angle)
     double new_y2 = -(x2-x4)*sin(angle) + (y2-y4)*cos(angle) + y4 - shift_y;
    //double new_y3 = (x3-x2)*sin(angle) + (y3-y2)*cos(angle) + y2 - shift_y ; // правый верхний
     double new_y3 = -(x3-x4)*sin(angle) + (y3-y4)*cos(angle) + y4 - shift_y ;
    double new_y4 = y4 - shift_y;
    return new Node(new_x1,new_x2,new_x3,new_x4,new_y1,new_y2,new_y3,new_y4,1,scale_x,scale_y);
}

Node::Node(double x_center, double y_center, double width, double height,double scale_x, double scale_y)
{
    this-> side = 0;
    this->x1 = (x_center - width/2.0) * scale_x;
    this->x2 = (x_center - width/2.0) * scale_x;
    this->x3 = (x_center + width/2.0) * scale_x;
    this->x4 = (x_center + width/2.0) * scale_x;
    this->y1 = (y_center - height/2.0) * scale_y;
    this->y2 = (y_center + height/2.0) * scale_y;
    this->y3 = (y_center + height/2.0) * scale_y;
    this->y4 = (y_center - height/2.0) * scale_y;
    this->width = width*scale_x;
    this->height = height*scale_y;
    this->left = nullptr;
    this->right = nullptr;
    this->center = nullptr;
}

Node::Node(double x1, double x2, double x3, double x4, double y1, double y2, double y3, double y4, int side,double scale_x, double scale_y)
{
    this-> side = side;
    this->x1 = x1* scale_x;
    this->x2 = x2* scale_x;
    this->x3 = x3* scale_x;
    this->x4 = x4* scale_x;
    this->y1 = y1* scale_y;
    this->y2 = y2* scale_y;
    this->y3 = y3* scale_y;
    this->y4 = y4* scale_y;
    this->width = 0.25/10.0*scale_x;
    this->height = 0.5/10.0*scale_y;
    this->left = nullptr;
    this->right = nullptr;
    this->center = nullptr;
}
