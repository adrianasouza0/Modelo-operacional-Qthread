#include <iostream>
#include "qthread.h"
using namespace std;

int main(int argc, char *argv[])
{
    Qthread thread;
    thread.run();
    thread.wait();
    thread.start();	
   // cout << "Hello World!" << endl;
    return 0;
}

