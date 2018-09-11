#include "qthread.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include <assert.h>
#include <fstream>
#include<unistd.h>

using std::exit;
using namespace std;
int ret;
int threads_params;




QThread::QThread()
{

        pthread_attr_init(&_attr);
        pthread_attr_setdetachstate(&_attr, PTHREAD_CREATE_DETACHED);
        pthread_attr_setscope(&_attr, PTHREAD_SCOPE_SYSTEM);
        //void * ret_join;

}



QThread::~QThread(){

    pthread_attr_destroy(&_attr);
}


void *QThread::function(void *ptr)
{
  if (!ptr) {
    return NULL;
  }else if (ptr) {
		
             // QThread *thread = static_cast<QThread*>(ptr);
		int *numeroThread = (int*)malloc(sizeof(int));
		*numeroThread = *(int *)ptr;

                QThread* thread = (QThread*)ptr;
		cout<<"Endereçamento numeroThread : "<<&numeroThread<<endl;
	//thread->run();	
 		
              //thread-> Qthread::run();
              //thread->wait();
               pthread_exit(numeroThread);
               return NULL;
               }

      };


void QThread::start(Priority priority){
QThread *thread;
    if (priority == InheritPriority){

          //assert (ret == 0);
                 ret =pthread_create(&_id, &_attr, function, (void*)(this));
                    if(ret != 0) {
                         cout<<"Error: Thread não criada!\n"<<endl;
                        // assert(ret !=0 );
                         exit(EXIT_FAILURE);
                     }
			cout<<"Endereçamento pthread_create "<<&_id<<endl;
		run();
		
                        //cout<<"Executando Thread_id -> " << pthread_self() << "\nPrioridade: "<< QThread::InheritPriority <<endl;
                      //  pthread_exit(NULL);
         // pthread_detach(_id);



    } else{

             setPriority(priority);

      }


   };

void QThread::setPriority(Priority priority){


   // std::cout<<"Connecting setPriority() method !!"<<std::endl;
          if (priority == IdlePriority){

              pthread_create(&_id, &_attr, function, this);
              pthread_detach(_id);


        }else if(priority == LowestPriority){

              pthread_create(&_id, &_attr, function, this);
              pthread_detach(_id);

        }else if(priority == LowPriority){
              pthread_create(&_id, &_attr, function, this);
              pthread_detach(_id);

        }else if(priority == NormalPriority){
              pthread_create(&_id, &_attr, function, this);
              pthread_detach(_id);

        }else if(priority == HighPriority){
              pthread_create(&_id, &_attr, function, this);
              pthread_detach(_id);

        }else if(priority == HighestPriority){
              pthread_create(&_id, &_attr, function, this);
cout<<"Executando Thread_id -> " << pthread_self() << "\nPrioridade: "<< QThread::HighestPriority <<endl;
              pthread_detach(_id);

          }else if(priority == TimeCriticalPriority){
              pthread_create(&_id, &_attr, function, this);
              pthread_detach(_id);

        }


};


 bool QThread::wait()
     {
  pthread_join(_id, (void**)(this));
 
   int numThread ;
	
	  
   cout<<"A thread join() = "<< (string *)this<<endl;	

 };

void QThread::exit(int returnCode){
   cout<<"Entra na exit() "<<endl;	
   pthread_exit(NULL);

		

};

void QThread::quit(){
   cout<<"Entra na quit() "<<endl;	
   pthread_exit(NULL);
	

};


