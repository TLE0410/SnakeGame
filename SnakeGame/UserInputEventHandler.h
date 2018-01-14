#ifndef CLOSEEVENTHANDLER_H
#define CLOSEEVENTHANDLER_H

class UserInputEventHandler
{
public:
    virtual ~UserInputEventHandler() = default;
    virtual void handleCloseEvent() = 0;
    virtual void handleNewGameEvent() = 0;
};

#endif // CLOSEEVENTHANDLER_H
