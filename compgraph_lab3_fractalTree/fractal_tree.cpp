#include "fractal_tree.h"
#include <QTextStream>
#include <cmath>
#include <QOpenGLWidget>
Fractal_Tree::~Fractal_Tree()
{
    del_tree(root);
}
void Fractal_Tree::del_tree(Node *root){
    if (root) {
        InOrderTravers(root->left);

        InOrderTravers(root->right);
        delete root;
    }
}

Fractal_Tree::Fractal_Tree(Node *obj,double angle,double width,double height)
{
    this->width = width;
    this->height = height;
    this->count = 1; //0.0,-1.2
    this->root = new Node(0.0,-0.5,width*0.5,height*0.5);
    this->angle = M_PI*angle/180.0;
    this->shift_x = 2.0*width*cos(this->angle)/3.0; //width
    this->shift_y = sin(this->angle)*height*1.0/4.0; //height
}

void Fractal_Tree::add_Node(Node *parent, Node *child, int side)
{
    if(side == -1){
        parent->left = child;
    }
    else if(side == 1){
        parent->right = child;
    }
    else if(side == 2){
        parent->center = child;
    }
}

void Fractal_Tree::Build_Fractal_Tree(int iter)
{
        this->count = 5;
        double parral_x = 0.01;
        double parral_y = abs(height)*1.5;
        Node* child = new Node(root->x1,root->x2,root->x3,root->x4,
                               root->y1 + parral_y ,root->y2 + parral_y,root->y3 + parral_y,root->y4 + parral_y,2,4.0,1.5); //4 and 1.5
        root->x1 = child->x1 +0.5*width;
        root->x2 = child->x2+0.5*width;
        root->x3 = child->x3- 0.5*width;
        root->x4 = child->x4-0.5*width;
        root->y1 = child->y1 - 0.5*height;
        root->y2 = child->y2 - 0.5*height;
        root->y3 = child->y3 - 0.5*height;
        root->y4 = child->y4 - 0.5*height;
        root->center = child;
        parral_x = width*0.1;
        parral_y = height*0.6;
        Node* prochild = new Node(root->center->x1 - parral_x,root->center->x2 - parral_x,root->center->x3 - parral_x,root->center->x4 - parral_x ,
                                  root->center->y1+ parral_y,root->center->y2+ parral_y,root->center->y3+ parral_y,root->center->y4+  parral_y,2);
        root->center->center = prochild;
        double shift_x =  0;
        double shift_y = height * 0.3;
        root->left = root->center->rotate_left(this->angle,shift_x,shift_y,1.0,1.0);
        root->right = root->center->rotate_right(this->angle,shift_x,shift_y,1.0,1.0);
        for (int i = 1;i<iter;i++) {
         Rec_Build(root);
        }
    }


void Fractal_Tree::Rec_Build(Node *root)
{
    if(root){
        Rec_Build(root->left);

        if(root->side == -1){

            double parral_x = cos(angle)*width*0.5;
            double parral_y = sin(angle)*height* 0.1;

            Node* tmp = root->left;
            UpChild(root->left,-1);
            Node* child = new Node(root->x1-parral_x,root->x2-parral_x,root->x3-parral_x,root->x4-parral_x,
                                   root->y1+parral_y,root->y2+parral_y,root->y3+parral_y,root->y4+parral_y,-1,1.0,1.0);
            Node* prochild = new Node(root->x1 + 0.5*width ,root->x2 + 0.3*width,root->x3 -0.3*width,root->x4,
                                   root->y1 - (double)0.001*height ,root->y2 - 0.001*height,root->y3  - 0.5*height,root->y4 - 0.5*height,1);

            add_Node(root,prochild,-1);
            add_Node(prochild,child,2);
            double shift_x = 0;
            double shift_y = 0;
             Node* cur = child->rotate_left(angle,shift_x,shift_y);
             add_Node(child,cur,-1);
             add_Node(child,new Node(child->x1-parral_x,child->x2-parral_x,child->x3-parral_x,child->x4-parral_x,
                                     child->y1+parral_y,child->y2+parral_y,child->y3+parral_y,child->y4+parral_y,0),2);
             add_Node(child,child->rotate_right(angle,shift_x,shift_y),1);

             add_Node(cur,tmp,-1);

            count +=5;
            Rec_Build(root->center);
            Rec_Build(root->right);

        }
        else if(root->side == 1){
            double parral_x = cos(angle)*width*0.5;
            double parral_y = sin(angle)*height* 0.1;
            Node* tmp = root->right;
            UpChild(root->right,1);
            Node* child = new Node(root->x1+parral_x,root->x2+parral_x,root->x3+parral_x,root->x4+parral_x,
                                   root->y1+parral_y,root->y2+parral_y,root->y3+parral_y,root->y4+parral_y,1);
            Node* prochild = new Node(root->x1 ,root->x2+0.3*width,root->x3- 0.3*width,root->x4-0.5*width,
                                   root->y1 - 0.5*height ,root->y2 - 0.5*height,root->y3 - 0.001*height,root->y4 - (double)0.001*height,1);
            add_Node(root,prochild,1);
            add_Node(prochild,child,2);
            double shift_x = 0;
            double shift_y = 0;
            Node* cur = child->rotate_right(angle,shift_x,shift_y);
            add_Node(child,cur,1);
            add_Node(child,new Node(child->x1+parral_x,child->x2+parral_x,child->x3+parral_x,child->x4+parral_x,
                                                child->y1+parral_y,child->y2+parral_y,child->y3+parral_y,child->y4+parral_y,0),2);
            add_Node(child,child->rotate_left(angle,shift_x,shift_y),-1);
            add_Node(cur,tmp,1);
            count +=5;
            Rec_Build(root->center);
            Rec_Build(tmp);
        }
        else if(root->side == 2){
            double parral_x = cos(angle)* width*0.1;
            double parral_y = sin(angle)*height* 0.7;
            Node* tmp = root->center;
            UpChild(root->center,2);
            Node* child = new Node(root->x1-parral_x,root->x2-parral_x,root->x3-parral_x,root->x4-parral_x,
                                   root->y1+parral_y,root->y2+parral_y,root->y3+parral_y,root->y4+parral_y,2);
            Node* prochild = new Node(root->x1 +0.5*width ,root->x2+0.5*width,root->x3- 0.5*width,root->x4-0.5*width,
                                   root->y1 - 0.5*height ,root->y2 - 0.5*height,root->y3 - 0.5*height,root->y4 - 0.5*height,1);
            add_Node(root,prochild,2);
            add_Node(prochild,child,2);
            double shift_x = 0;
            double shift_y = 0;
            Node* cur = child->rotate_right(angle,shift_x,shift_y);
            add_Node(child,cur,1);
            add_Node(child,new Node(child->x1+parral_x,child->x2+parral_x,child->x3+parral_x,child->x4+parral_x,
                                                child->y1+parral_y,child->y2+parral_y,child->y3+parral_y,child->y4+parral_y,0),2);
            add_Node(child,child->rotate_left(angle,shift_x,shift_y),-1);
            add_Node(cur,tmp,2);
            count +=5;
            Rec_Build(tmp);
            Rec_Build(root->right);
        }
        else{
            Rec_Build(root->center);
            Rec_Build(root->right);
        }
    }
}

void Fractal_Tree::InOrderTravers(Node* root)
{
    QTextStream out(stdout);

            if (root != nullptr) {
                InOrderTravers(root->left);
                glVertex2d(root->x1,root->y1); //отстраиваем квадрат
                glVertex2d(root->x2,root->y2);
                glVertex2d(root->x2,root->y2);
                glVertex2d(root->x3,root->y3);
                glVertex2d(root->x3,root->y3);
                glVertex2d(root->x4,root->y4);
                glVertex2d(root->x4,root->y4);
                glVertex2d(root->x1,root->y1);
                InOrderTravers(root->center);
                InOrderTravers(root->right);
            }

}

void Fractal_Tree::UpChild(Node *root,int side)
{
    if (root != nullptr) {
        double parral_x;
        double parral_y;
        UpChild(root->left,side);
        if(side == -1){
            parral_x = 1.5*width*cos(angle);
            parral_y = 0.3*height*sin(angle);
            root->x1 -=  parral_x;
            root->x2 -=  parral_x;
            root->x3 -=  parral_x;
            root->x4 -=  parral_x;
            root->y1 +=  parral_y;
            root->y2 +=  parral_y;
            root->y3 +=  parral_y;
            root->y4 +=  parral_y;
        }
        else if(side == 1){
            parral_x = 1.5*width*cos(angle);
            parral_y = 0.3*height*sin(angle);
            root->x1 +=  parral_x;
            root->x2 +=  parral_x;
            root->x3 +=  parral_x;
            root->x4 +=  parral_x;
            root->y1 +=  parral_y;
            root->y2 +=  parral_y;
            root->y3 +=  parral_y;
            root->y4 +=  parral_y;
        }
        else{
             parral_x = 0.1*width*cos(angle);
             parral_y = 0.7*height*sin(angle);
            root->y1 +=  parral_y;
            root->y2 +=  parral_y;
            root->y3 +=  parral_y;
            root->y4 +=  parral_y;
        }
        UpChild(root->center,side);
        UpChild(root->right,side);
    }

}
