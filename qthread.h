#ifndef QTHREAD_H
#define QTHREAD_H

#include "qobject.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>


class Qthread// : public  QObject
{
 // Q_OBJECT
public:
    pthread_attr_t _attr;
    pthread_t _id;
    Qthread();
   ~Qthread();
    enum Priority {
        IdlePriority,
        LowestPriority,
        LowPriority,
        NormalPriority,
        HighPriority,
        HighestPriority,

        TimeCriticalPriority,

        InheritPriority
    };
   void setPriority(Priority priority);
    //setPriority --sets the priority of a running thread
   Priority priority() const;
   void start(Priority = InheritPriority);
//y
    static void* function(void* ptr);
    virtual void run();
    int exec();
    void exit(int returnCode = 0);
    void quit();
    bool wait();
    
    static Qthread *currentThread();


protected:
  




//Q_SIGNALS:


};
#endif // QTHREAD_H
