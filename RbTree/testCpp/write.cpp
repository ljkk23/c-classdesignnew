#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <iostream>
#include "json.hpp"
using namespace std;

// for convenience
using json = nlohmann::json;
#define FIFO_NAME "/tmp/my_fifo"

#define BUFFER_SIZE PIPE_BUF
//从管道读取数据
void getdata(){
    int pipe_fd;

    char buffer[BUFFER_SIZE + 1];
    //if the pipe file do not exist
    memset(buffer, '\0', sizeof(buffer));
    //open FIFO pipe file.
    //this will be brocked until some one open another end point(write-point) of this pipe
    pipe_fd = open(FIFO_NAME, O_RDONLY);
    if(read(pipe_fd, buffer, BUFFER_SIZE) > 0)
    {
        printf("data from FIFO : %s\n", buffer);
    }
    close(pipe_fd);
}
//向管道中写入数据
void writeData(json j){
    int pipe_fd;

    char buffer[BUFFER_SIZE + 1];
    pipe_fd = open(FIFO_NAME, O_WRONLY);
    //写数据

	std::string s = j.dump(); 
    char tmp[50];
    strcpy(tmp,s.c_str());
    //write data into pipe 
    write(pipe_fd, tmp, PIPE_BUF);
    //close FIFO pipe file descriptor
    close(pipe_fd);
}

int main()
{
//     int pipe_fd;

    char buffer[BUFFER_SIZE + 1];
   // if the pipe file do not exist
    if (access(FIFO_NAME, F_OK) == -1)
    {
        //creat FIFO pipe file
        mkfifo(FIFO_NAME, 0777);
    }
//插入数据
    json j;
    j["option"] = 1;
	j["key"] = "aaa";
    j["value"] = "bbb";
    writeData(j);
    getdata();

    //插入数据
    json j2;
    j2["option"] = 1;
    j2["key"] = "sss";
    j2["value"] = "bdsadbb";
	writeData(j2);
    getdata();


    // //插入数据
    json j3;
    j3["option"] = 1;
    j3["key"] = "key3";
    j3["value"] = "value3";
	writeData(j3);
    getdata();
    
    // //层次遍历
    json j4;
    j4["option"] = 4;
	j4["key"] = "we";
    j4["value"] = "wewe";
    
	writeData(j4);
    getdata();
   // 删除节点
    json deleteJson;
     deleteJson["option"] = 2;
	deleteJson["key"] = "key3";
    deleteJson["value"] = "dfsf";
    writeData(deleteJson);
    getdata();
    //层次遍历
    
	writeData(j4);
    getdata();
//查询
    json queryJson;
     queryJson["option"] = 0;
	queryJson["key"] = "key3";
    queryJson["value"] = "dfsf";
    writeData(queryJson);
    getdata();

    //层次遍历
    
	writeData(j4);
    getdata();
    //修改
     json modifyJson;
     modifyJson["option"] = 3;
	modifyJson["key"] = "aaa";
    modifyJson["value"] = "dfsf";
    writeData(modifyJson);
    getdata();
     //层次遍历
    
	writeData(j4);
    getdata();

    return 0;
}