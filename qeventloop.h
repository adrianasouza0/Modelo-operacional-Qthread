#ifndef QEVENTLOOP_H
#define QEVENTLOOP_H
#include "qobject.h"
#include "qflags.h"

#define Q_DECLARE_FLAGS()

//typedef QFlags<Enum> Flags;

#define Q_DECLARE_INCOMPATIBLE_FLAGS(Flags)

class QEventLoop
 {
public:
    QEventLoop();
    ~QEventLoop();

    enum ProcessEventsFlag {
        AllEvents = 0x00,
        ExcludeUserInputEvents = 0x01,
        ExcludeSocketNotifiers = 0x02,
        WaitForMoreEvents = 0x04,
        X11ExcludeTimers = 0x08,
        EventLoopExec = 0x20,
        DialogExec = 0x40
    };
    int exec();

    Q_DECLARE_FLAGS()


};

#endif // QEVENTLOOP_H
