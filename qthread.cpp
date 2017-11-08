#include "qthread.h"
#include "qobject.h"
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include <pthread.h>
#include <fstream>
#include "qeventloop.h"

using std::exit;
using namespace std;

Qthread::Qthread()
{
        pthread_attr_init(&_attr);
        pthread_attr_setdetachstate(&_attr, PTHREAD_CREATE_DETACHED);
        pthread_attr_setscope(&_attr, PTHREAD_SCOPE_SYSTEM);
}



Qthread::~Qthread(){

    pthread_attr_destroy(&_attr);
}


void* Qthread::function(void* ptr)
{
  if (!ptr) {
    return NULL;
  }else if (ptr) {
              Qthread* thread = (Qthread*)ptr;
              thread->run();
              pthread_exit(NULL);
              return NULL;
               }

      };


void Qthread::start(Priority priority){



    if (priority == InheritPriority){
        pthread_create(&_id, &_attr, Qthread::function, (void *)this);
        pthread_detach(_id);
	run();

    }else{

          setPriority(priority);
	  run();

   }


};


void Qthread::setPriority(Priority priority){


   // std::cout<<"Conectando metodo setPriority () !!"<<std::endl;
          if (priority == IdlePriority){

              pthread_create(&_id, &_attr, Qthread::function, this);
              pthread_detach(_id);


        }else if(priority == LowestPriority){

              pthread_create(&_id, &_attr, Qthread::function, this);
              pthread_detach(_id);

        }else if(priority == LowPriority){
              pthread_create(&_id, &_attr, Qthread::function, this);
              pthread_detach(_id);

        }else if(priority == NormalPriority){
              pthread_create(&_id, &_attr, Qthread::function, this);
              pthread_detach(_id);

        }else if(priority == HighPriority){
              pthread_create(&_id, &_attr, Qthread::function, this);
              pthread_detach(_id);

        }else if(priority == HighestPriority){
              pthread_create(&_id, &_attr, Qthread::function, this);
              pthread_detach(_id);

          }else if(priority == TimeCriticalPriority){
              pthread_create(&_id, &_attr, Qthread::function, this);
              pthread_detach(_id);

        }


};





void Qthread::run(){

              cout<<"Thread estartada! " << endl;
              exec();


};
int Qthread::exec(){
  // QEventLoop::exec();

    
};

void Qthread::quit(){
    Qthread::exit(0);
    
};

void Qthread::exit(int retcode){

};
bool Qthread::wait()
    {
    int *b;

    pthread_join(_id,(void**)&b);
    cout << "Thread finalizada"<< b <<endl;
};
