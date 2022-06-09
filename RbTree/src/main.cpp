// #include "RB_Tree.cpp"
// #include <iostream>
// #include "Kvalue.cpp"
// using namespace std;

// int main() {
//     int op, x,selectOp;
//     int data;
//     RB_Tree<int> w;
//     RB_Node<int> *p=new RB_Node<int>;
//    while(true)
//     {   
//         cout<<"0代表查询，1代表增加或者删除，2代表修改，3代表层次遍历,4代表退出";
//         cin>>selectOp;
//         if (selectOp==1)
//         {
//             /* code */
//             cout<<"1代表插入（增加），2代表删除,3退出";
//             while (cin >> op) {

//             if (op==1) {      
//                 cin>>x;
//                 w.insert(x);
//             }else if (op==3)
//              {
//                   break;
//             }else {      
//                    cin>>x;
//                     bool res = w.del(x);
//                     if (!res) {
//                         cout << "no this node\n";
//                         continue;
//                     }
//                 }
//                w.tree_show();
//                 w.floor_show();
//                  cout<<"-----------";
//             }
//         }else if (selectOp==2)
//         {
//            cout<<"输入你想修改的值";
//             cin>>data;
//             p=w.find(data);
//             if (p == nullptr) 
//             {      // 没有该元素，删除失败
//                        cout<<"没有该元素";
//             }else{
//                 w.del(data);
//                 cout<<"修改为多少:";
//                 cin>>data;
//                 w.insert(data);
//                 cout<<"成功修改";
//         }
//         }else if (selectOp==0)
//         {
//             /* code */
//             cout<<"输入你想查询的值";
//             cin>>data;
//             p=w.find(data);
//             if (p == nullptr) 
//             {      // 没有该元素，删除失败
//                        cout<<"没有该元素";
//             }else{
//             cout<<p->value;
//            cout<<"成功输出";
//             }

//         }else if (selectOp==3)
//         {
//             /* code */
//             w.floor_show();
//         }
//         else if (selectOp==4)
//         {
//             /* code */break;
//         }
        
        
//     }
    
//     return 0;
// }

// /*
// 1 10
// 1 12
// 1 14
// 1 8
// 0 12

//  */