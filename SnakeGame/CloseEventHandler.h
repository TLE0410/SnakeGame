#ifndef CLOSEEVENTHANDLER_H
#define CLOSEEVENTHANDLER_H

class CloseEventHandler
{
public:
    virtual ~CloseEventHandler() = default;
    virtual void handleCloseEvent() = 0;
};

#endif // CLOSEEVENTHANDLER_H
