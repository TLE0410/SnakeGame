#include <iterator>
#include "Player.h"
#include "Utils.h"

Player::Player()
{
    Point2D* startPosition = new Point2D;
    startPosition->x = 10;
    startPosition->y = 10;
    m_snakePositions.push_back(startPosition);

    needToEraise = false;
    needToIncreaseLength = false;
    isAlive = true;
}

void Player::render()
{
    drawSnakeBody();
    eraiseTailIfMoved();
}

void Player::update()
{
    if (moveDirection == Direction::none)
    {
        return;
    }

    steady_clock::time_point currentTime = steady_clock::now();
    auto duration = currentTime - timeOfLastMove;
    if (duration < milliseconds{200})
    {
        return;
    }
    timeOfLastMove = currentTime;
    
    Point2D newPosition, oldPosition;
    Point2D* snakeHead = m_snakePositions.front();
    newPosition.x = snakeHead->x;
    newPosition.y = snakeHead->y;

    switch (moveDirection)
    {
    case up:
        (snakeHead->y)--;
        break;
    case down:
        (snakeHead->y)++;
        break;
    case left:
        (snakeHead->x)--;
        break;
    case right:
        (snakeHead->x)++;
        break;
    }

    if (m_snakePositions.size() > 1)
    {
        std::vector<Point2D*>::iterator mIter = m_snakePositions.begin();
        for (advance(mIter, 1); mIter != m_snakePositions.end(); ++mIter)
        {
            oldPosition.x = (*mIter)->x;
            oldPosition.y = (*mIter)->y;

            (*mIter)->x = newPosition.x;
            (*mIter)->y = newPosition.y;

            newPosition.x = oldPosition.x;
            newPosition.y = oldPosition.y;
        }
    }

    if (needToIncreaseLength)
    {
        Point2D* newPoint = new Point2D;
        newPoint->x = newPosition.x;
        newPoint->y = newPosition.y;

        m_snakePositions.push_back(newPoint);
        needToIncreaseLength = false;
    }
    else
    {
        pointToEraise.x = newPosition.x;
        pointToEraise.y = newPosition.y;
        needToEraise = true;
    }
}

void Player::die()
{
    isAlive = false;
}

int Player::getHeadX()
{
    return m_snakePositions.front()->x;
}

int Player::getHeadY()
{
    return m_snakePositions.front()->y;
}

Point2D Player::getHeadPosition()
{
    Point2D result;
    result.x = m_snakePositions[0]->x;
    result.y = m_snakePositions[0]->y;
    return result;
}

Direction Player::getDirection()
{
    return moveDirection;
}

void Player::increaseLength()
{
    needToIncreaseLength = true;
}

DWORD Player::getInput(INPUT_RECORD ** eventBuffer)
{
    DWORD numEvents = 0;
    DWORD numEventsRead = 0;

    HANDLE rHnd = GetStdHandle(STD_INPUT_HANDLE);
    GetNumberOfConsoleInputEvents(rHnd, &numEvents);

    if (numEvents)
    {
        *eventBuffer = (INPUT_RECORD *)malloc(sizeof(INPUT_RECORD) * numEvents);
        ReadConsoleInput(rHnd, *eventBuffer, numEvents, &numEventsRead);
    }

    return numEventsRead;
}

void Player::handleInput()
{
    INPUT_RECORD* eventsBuffer;
    int numberOfEvents = getInput(&eventsBuffer);

    if (numberOfEvents > 0)
    {
        for (int i = 0; i < numberOfEvents; i++)
        {
            switch (eventsBuffer[i].EventType)
            {
            case KEY_EVENT:
                if (eventsBuffer[i].Event.KeyEvent.bKeyDown)
                {
                    switch (eventsBuffer[i].Event.KeyEvent.wVirtualKeyCode)
                    {
                    case VK_UP:
                        if (moveDirection != Direction::down)
                        {
                            moveDirection = Direction::up;
                        }
                        break;
                    case VK_DOWN:
                        if (moveDirection != Direction::up)
                        {
                            moveDirection = Direction::down;
                        }
                        break;
                    case VK_LEFT:
                        if (moveDirection != Direction::right)
                        {
                            moveDirection = Direction::left;
                        }
                        break;
                    case VK_RIGHT:
                        if (moveDirection != Direction::left)
                        {
                            moveDirection = Direction::right;
                        }
                        break;
                    }
                }
            }
        }
    }
}

void Player::drawSnakeBody()
{
    for (Point2D* point : m_snakePositions)
    {
        Utils::PrintText(point->x, point->y, "o");
    }
}

void Player::eraiseTailIfMoved()
{
    if (needToEraise)
    {
        Utils::PrintText(pointToEraise.x, pointToEraise.y, " ");
        needToEraise = false;
    }
}

