#include "EventLoop.h"
#include "Server.h"
#include "base/Logging.h"
#include <getopt.h>
#include <string>

int main(int argc, char *argv[])
{
    int threadNum = 4;
    int port = 80;
    std::string logPath = "../Server.log";


    if(argc>4){
	printf("Args is error!/m");
	return 0;
    }
	
    threadNum = atoi(argv[1]);
    logPath = argv[2];
    port = atoi(argv[3]); 

    Logger::setLogFileName(logPath);
    #ifndef _PTHREADS
        LOG << "_PTHREADS is not defined !";
    #endif
    EventLoop mainLoop;
    Server myHTTPServer(&mainLoop, threadNum, port);
    myHTTPServer.start();
    mainLoop.loop();
    return 0;
}
