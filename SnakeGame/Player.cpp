#include <iterator>
#include "Player.h"
#include "Utils.h"
#include "Constants.h"

Player::Player(Renderer &renderingEngine) : GameObject(renderingEngine)
{
    futureMoveDirection_ = Direction::up;
    moveDirection_ = futureMoveDirection_;

    Point2D* startPosition = new Point2D;
    startPosition->x = Constants::GAME_FIELD_WIDTH_CELLS / 2;
    startPosition->y = Constants::GAME_FIELD_HEIGHT_CELLS / 2;
    m_snakePositions.push_back(startPosition);

    for (int i = 1; i < Constants::SNAKE_INITIAL_LENGTH; i++)
    {
        m_snakePositions.push_back(new Point2D(startPosition->x, startPosition->y + i));
    }

    needToIncreaseLength = false;
    isAlive = true;
}

void Player::render()
{
    const Color greenColor(0, 255, 0, 200);
    for (Point2D* point : m_snakePositions)
    {
        renderer_.renderBox(point->x, point->y, greenColor);
    }
}

void Player::update()
{
//#define DEBUG_DIRECTION_BUG 
//#ifdef DEBUG_DIRECTION_BUG
//    return;
//#endif

    if (futureMoveDirection_ == Direction::none)
    {
        return;
    }

    if (!isAlive)
    {
        moveDirection_ = Direction::none;
        return;
    }

    moveDirection_ = futureMoveDirection_;

    Point2D newPosition;
    const auto snakeHead = m_snakePositions.front();
    newPosition.x = snakeHead->x;
    newPosition.y = snakeHead->y;

    moveSnakeHead(snakeHead, moveDirection_);

    Point2D oldPosition;
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
    return futureMoveDirection_;
}

void Player::increaseLength()
{
    needToIncreaseLength = true;
}

int Player::getLength() const
{
    return m_snakePositions.size();
}

Player::const_iterator Player::body_begins() const
{
    return m_snakePositions.begin();
}

Player::const_iterator Player::body_ends() const
{
    return m_snakePositions.end();
}

void Player::removeBodyStartingWith(std::vector<Point2D*>::const_iterator positionToRemoveFrom)
{
    m_snakePositions.erase(positionToRemoveFrom, m_snakePositions.end());
}

void printDirection(Direction direction)
{
    switch (direction)
    {
        case up:
            Utils::Log(("up"));
            break;
        case down:
            Utils::Log(("up"));
            break;
        case left:
            Utils::Log(("left"));
            break;
        case right:
            Utils::Log(("right"));
            break;
    }

}

void Player::changeDirection(Direction direction)
{
    printDirection(direction);
    if (!oppositeDirections(moveDirection_, direction))
    {
        futureMoveDirection_ = direction;
    }
}

bool Player::oppositeDirections(Direction direction_one, Direction direction_two)
{
    return (direction_one == up && direction_two == down) 
        || (direction_one == down && direction_two == up) 
        || (direction_one == left && direction_two == right) 
        || (direction_one == right && direction_two == left);
}

void Player::moveSnakeHead(Point2D* const snakeHead, Direction direction)
{
    switch (direction)
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
}
