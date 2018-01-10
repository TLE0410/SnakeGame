#include <iterator>
#include "Player.h"
#include "Utils.h"
#include "Constants.h"

Player::Player(Renderer &renderingEngine) : GameObject(renderingEngine)
{
    futureMoveDirection_ = Direction::up;
    moveDirection_ = futureMoveDirection_;

    DirectionalPoint2D* startPosition = new DirectionalPoint2D(
        Constants::GAME_FIELD_WIDTH_CELLS / 2,
        Constants::GAME_FIELD_HEIGHT_CELLS / 2,
        Direction::up);

    m_snakePositions.push_back(startPosition);

    for (int i = 1; i < Constants::SNAKE_INITIAL_LENGTH; i++)
    {
        m_snakePositions.push_back(
            new DirectionalPoint2D(
                startPosition->x, startPosition->y + i, Direction::up));
    }

    needToIncreaseLength = false;
    isAlive = true;
}

void Player::render()
{
    const auto snakeHead = m_snakePositions.front();
    renderer_.renderSnakeBox(*snakeHead, SnakeBodyPart::Head);

    for (auto point = m_snakePositions.begin() + 1;  point != m_snakePositions.end() - 1; ++point )
    {
        renderer_.renderSnakeBox(**point, SnakeBodyPart::Body);
    }

    const auto snakeTail = m_snakePositions.back();
    renderer_.renderSnakeBox(*snakeTail, SnakeBodyPart::Tail);
}

void Player::moveSnake()
{
    moveDirection_ = futureMoveDirection_;
    const auto snakeHead = m_snakePositions.front();
    DirectionalPoint2D newPosition = *snakeHead;
    
    *snakeHead = Utils::getNextPosition(*snakeHead, moveDirection_);
    Direction nextPositionDirection = snakeHead->direction.prev;

    if (m_snakePositions.size() > 1)
    {
        auto mIter = m_snakePositions.begin();
        for (advance(mIter, 1); mIter != m_snakePositions.end(); ++mIter)
        {
            DirectionalPoint2D oldPosition = **mIter;
            **mIter = newPosition;
            (*mIter)->direction.setDirection(nextPositionDirection);

            newPosition = oldPosition;
        }
    }

    if (needToIncreaseLength)
    {
        m_snakePositions.push_back(new DirectionalPoint2D(newPosition));
        needToIncreaseLength = false;
    }
}

void Player::update()
{
    if (futureMoveDirection_ == Direction::none)
    {
        return;
    }

    if (!isAlive)
    {
        moveDirection_ = Direction::none;
        return;
    }

    moveSnake();
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

DirectionalPoint2D Player::getHeadPosition()
{
    return DirectionalPoint2D(*m_snakePositions[0]);
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

void Player::removeBodyStartingWith(const_iterator positionToRemoveFrom)
{
    m_snakePositions.erase(positionToRemoveFrom, m_snakePositions.end());
}

void printDirection(Direction direction)
{
    switch (direction)
    {
        case up:
            break;
        case down:
            break;
        case left:
            break;
        case right:
            break;
    }
}

void Player::changeDirection(Direction direction)
{
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