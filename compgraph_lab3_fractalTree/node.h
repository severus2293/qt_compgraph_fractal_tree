#ifndef NODE_H
#define NODE_H


class Node
{
public:
    Node* left;
    Node* right;
    Node* center;
    double x1;
    double x2;
    double x3;
    double x4;
    double y1;
    double y2;
    double y3;
    double y4;
    double width;
    double height;
    int side;
    Node* rotate_left(double angle,double shift_x,double shift_y,double scale_x = 1.0, double scale_y = 1.0);
    Node* rotate_right(double angle,double shift_x,double shift_y,double scale_x = 1.0, double scale_y = 1.0);
    Node(double x_center,
         double y_center,
         double width,
         double height,double scale_x = 1.0, double scale_y = 1.0);
    Node(double x1,
         double x2,
         double x3,
         double x4,
         double y1,
         double y2,
         double y3,
         double y4,int side,double scale_x = 1.0, double scale_y = 1.0);

};

#endif // NODE_H
