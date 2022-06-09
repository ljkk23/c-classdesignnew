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
    int pipe_fd;

    char buffer[BUFFER_SIZE + 1];
    //if the pipe file do not exist
    // if (access(FIFO_NAME, F_OK) == -1)
    // {
    //     //creat FIFO pipe file
    //     mkfifo(FIFO_NAME, 0777);
    // }
    //open FIFO pipe file.
    //this will be brocked until some one open another end point(read-point) of this pipe
    // pipe_fd = open(FIFO_NAME, O_WRONLY);
    // //写数据
    // json j;

	// // add a number that is stored as double (note the implicit conversion of j to an object)
	// j["option"] = 1;

	// 	// add a Boolean that is stored as bool
	// j["key"] = "aaa";
    // j["value"] = "bbb";
    
	// std::string s = j.dump(); 
    // char tmp[50];
    // strcpy(tmp,s.c_str());
    // //write data into pipe 
    // write(pipe_fd, tmp, PIPE_BUF);
    // //close FIFO pipe file descriptor
    // close(pipe_fd);

//写数据
    json j;
   // add a number that is stored as double (note the implicit conversion of j to an object)
	j["option"] = 1;
   // add a Boolean that is stored as bool
	j["key"] = "aaa";
    j["value"] = "bbb";
    writeData(j);
    getdata();

    //写数据
    json j2;

	// add a number that is stored as double (note the implicit conversion of j to an object)
	j2["option"] = 1;

		// add a Boolean that is stored as bool
	j2["key"] = "sss";
    j2["value"] = "bdsadbb";
    
	writeData(j2);
    getdata();
    
    //写数据
    json j3;

	// add a number that is stored as double (note the implicit conversion of j to an object)
	j3["option"] = 4;

		// add a Boolean that is stored as bool
	j3["key"] = "sss";
    j3["value"] = "bdsadbb";
    
	writeData(j3);
    getdata();

    return 0;
}