// #include "Kvalue.cpp"
// #include <iostream>
// using namespace std;
// int main(){
//     Kvalue kvalue1(8,"重庆");
//     Kvalue kvalue2(9,"报恩经");
//     if (kvalue2>kvalue1)
//     {
//         /* code */
//         cout<<"大于";
//     }else
//     cout<<"小雨";
//     return 0;
// }
//------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


#include "RB_Tree.cpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "json.hpp"
using namespace std;

// for convenience
using json = nlohmann::json;
#define FIFO_NAME "/tmp/my_fifo"

#define BUFFER_SIZE PIPE_BUF

using namespace std;

string getdata(){
        int pipe_fd;
        char buffer[BUFFER_SIZE + 1];
        //reset all bytes in buffer as '\0' 
        memset(buffer, '\0', sizeof(buffer));
        //open FIFO pipe file.
        //this will be brocked until some one open another end point(write-point) of this pipe
        pipe_fd = open(FIFO_NAME, O_RDONLY);
        if(read(pipe_fd, buffer, BUFFER_SIZE) > 0)
        {
            printf("data from FIFO : %s\n", buffer);
        }
        //close pipe file descriptor
        close(pipe_fd);
        return buffer;
    }
int myhash(string key){
    char buf[50];
	strcpy(buf , key.c_str());//字符串转字符数组，使用strcpy
   int hash=0;
   int i=0;
   while (buf[i] != '\0')
   {
      /* code */
      hash+=buf[i];
      i++;
   }
   return hash;
}

int main() {
     int pipe_fd;

    char buffer[BUFFER_SIZE + 1];
    //if the pipe file do not exist
    int op, x,selectOp;
    string key,valueD,reMsg;
    srand((unsigned)time(NULL));
    RB_Tree<Kvalue> w;
    // cout<<rand()%100<<endl;
    RB_Node<Kvalue> *p=new RB_Node<Kvalue>;
   while(true)
    {   
       string jsonData=getdata();
        auto j4 = json::parse(jsonData);
        int selectOp=j4["option"].get<int>();
        string key=j4["key"].get<string>();
        string value=j4["value"].get<string>();
        cout<<selectOp<<key<<value<<endl;
        cout<<"0代表查询，1代表增加,输入key,以及value。2代表删除,3代表修改，4代表层次遍历,5代表退出";
        if (selectOp==1)
        {
            /* code */
                RB_Node<Kvalue> *q=new RB_Node<Kvalue>();
                // cout<<"输入key,以及value";
                // cin>>key>>valueD;
                q->value.setKey(key);
                q->value.setData(value);
                q->value.value=myhash(key);
                cout<<q->value.value<<endl;
                w.insert(q->value); 
                reMsg="插入成功";
        }
        //删除
        else if (selectOp==2)
        {
            //  cout<<"输入你想删除的key";     
                //    cin>>key;
                   Kvalue kvalue1(key,myhash(key));
                    bool res = w.del(kvalue1);
                    if (!res) {
                       reMsg="no this node\n";
                        continue;
                    }
                    reMsg="删除成功";
        }
        //修改
        else if (selectOp==3)
        {
           cout<<"输入你想修改的key";
            cin>>key;
            Kvalue kvalue2(key,myhash(key));
            p=w.find(kvalue2);
             int valueID=p->value.getValue(key);
            if (p == nullptr) 
            {      // 没有该元素，删除失败
                       cout<<"没有该元素";
            }else{
                w.del(kvalue2);
                cout<<"修改为多少:";
                cin>>valueD;
                Kvalue updatekvalue(key,valueD,valueID);
                w.insert(updatekvalue);
                cout<<"成功修改";
        }
        }
        //查询
        else if (selectOp==0)
        {
            /* code */
            cout<<"输入你想查询的key";
            cin>>key;
            Kvalue kvalue3(key,myhash(key));
            p=w.find(kvalue3);
            if (p == nullptr) 
            {      // 没有该元素，删除失败
                       cout<<"没有该元素";
            }else{
            cout<<p->value.data;
           cout<<"成功输出";
            }

        }
        //层次遍历
        else if (selectOp==4)
        {
            /* code */
            reMsg=w.floor_show();
        }
        //退出
        else if (selectOp==5)
        {
            /* code */break;
        }
        
        char tmp[50];
        strcpy(tmp,reMsg.c_str());
        pipe_fd = open(FIFO_NAME, O_WRONLY);

        write(pipe_fd,tmp, PIPE_BUF);
        close(pipe_fd);

    }
  
    // Kvalue kvalue1(8,"重庆","dd");
    // Kvalue kvalue2(9,"报恩经","ddd");
    // cout<<kvalue1<<endl;
    // cout<<kvalue2<<endl;
    return 0;
}

/*
1 10
1 12
1 14
1 8
0 12

 */
