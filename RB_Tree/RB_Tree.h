//
// Created by admin on 2022/3/7.
//

#ifndef RB_TREE_RB_TREE_H
#define RB_TREE_RB_TREE_H

#include "RB_Node.h"
#include <iostream>
#include <queue>
#include "Kvalue.cpp"
using namespace std;

template <class T>
class RB_Tree {

private:
    RB_Node<T> *root;

public:
    RB_Tree();      // 构造一颗 红黑树

    void left_rotate(RB_Node<T> *x);        // 左旋操作
    void right_rotate(RB_Node<T> *x);      // 右旋操作
    RB_Node<T>* min_node(RB_Node<T> *x);        // 查找以 x 为根节点的子树中的最小节点
    void transplant(RB_Node<T> *u, RB_Node<T> *v);      // 移植函数
    RB_Node<T>* find(T data);      // 查询值为 data 的节点

    void insert(T data);        // 插入一个节点， value 为 data
    bool del(T data);       // 删除值为 data 的节点
    void del_node(RB_Node<T> *del);       // 删除指定节点

    void insert_fixup(RB_Node<T> *x);       // 插入后调整红黑树使之保持红黑树的性质
    void delete_fixup(RB_Node<T> *x, RB_Node<T> *f);        // 删除节点后调整红黑树

    void tree_show();        // 展示该红黑树的三种遍历
    string floor_show();   // 层序遍历红黑树
    void preorder(RB_Node<T> *x);       // 先序遍历
    void inorder(RB_Node<T> *x);     // 中序遍历
    void postorder(RB_Node<T> *x);      // 后序遍历
    

    ~RB_Tree();     // 析构函数
};
// template <class T>
// void RB_Tree<T>::floor_show() {
//     cout << "-------------floor--------------\n";
//     string str;
//     queue<RB_Node<T>*> q, p;       // q 为奇数层节点， p 为偶数层节点。（从 1 开始数层数）
//     q.push(this->root);
//     while (!q.empty() || !p.empty()) {
//         while (!q.empty()) {        // 将偶数层的节点放入 p 中
//             RB_Node<T> *x = q.front();      // 取出队首节点
//             q.pop();
//             if (x != nullptr) {     // 如果 x 不为空，输出内容
//                 cout << "(" << x->value << ", " << (x->color ? "black" : "red") << ") ";
//                 p.push(x->left);        // 依次放入左右子节点
//                 p.push(x->right);
//             }
//             else {
//                 cout << "(null, null) ";
//             }
//         }
//         cout << "\n";
//         while (!p.empty()) {        // 将奇数层的节点放入 q 中
//             RB_Node<T> *x = p.front();      // 取出队首节点
//             p.pop();
//             if (x != nullptr) {
//                 cout << "(" << x->value << ", " << (x->color ? "black" : "red") << ") ";
//                 q.push(x->left);        // 依次放入左右子节点
//                 q.push(x->right);
//             }
//             else {
//                 cout << "(null, null) ";
//             }
//         }
//         cout << "\n";
//     }
//     return str;
// }


#endif //RB_TREE_RB_TREE_H
