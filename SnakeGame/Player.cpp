#include <iterator>
#include "Player.h"
#include "Utils.h"

Player::Player(const Renderer &renderingEngine) : GameObject(renderingEngine)
{
    moveDirection = Direction::none;
    Point2D* startPosition = new Point2D;
    startPosition->x = Constants::GAME_FIELD_WIDTH / 2;
    startPosition->y = Constants::GAME_FIELD_HEIGHT / 2;
    m_snakePositions.push_back(startPosition);

    needToIncreaseLength = false;
    isAlive = true;
}

void Player::render()
{
    for (Point2D* point : m_snakePositions)
    {
        renderer_->renderBox(point->x, point->y, 0);
    }
}

void Player::update()
{
    if (moveDirection == Direction::none)
    {
        return;
    }

    if (!isAlive)
    {
        moveDirection = Direction::none;
        return;
    }

    Point2D newPosition{};
    Point2D oldPosition{};
    const auto snakeHead = m_snakePositions.front();
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
    //else
    //{
    //    pointToEraise.x = newPosition.x;
    //    pointToEraise.y = newPosition.y;
    //    needToEraise = true;
    //}
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

void Player::changeDirection(Direction direction)
{
    if (!oppositeDirections(moveDirection, direction))
    {
        moveDirection = direction;
    }
}

bool Player::oppositeDirections(Direction direction_one, Direction direction_two)
{
    return (direction_one == up && direction_two == down) 
        || (direction_one == down && direction_two == up) 
        || (direction_one == left && direction_two == right) 
        || (direction_one == right && direction_two == left);
}