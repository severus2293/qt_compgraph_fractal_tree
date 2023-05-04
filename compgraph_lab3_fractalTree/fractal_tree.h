#ifndef FRACTAL_TREE_H
#define FRACTAL_TREE_H
#include "node.h"
class Fractal_Tree
{
public:
    Node* root;
    int count;
    double angle;
    double shift_x;
    double shift_y;
    double width;
    double height;
    ~Fractal_Tree();
    void del_tree(Node* root);
    Fractal_Tree(Node* obj,double angle,double width,double height);
    void add_Node(Node* parent,Node* child,int side);
    void Build_Fractal_Tree(int iter);
    void Rec_Build(Node* root);
    void InOrderTravers(Node* root);
    void UpChild(Node* root,int side);
};

#endif // FRACTAL_TREE_H
