#include <iterator>
#include "Player.h"
#include "Utils.h"
#include "Constants.h"

Player::Player(Renderer &renderingEngine) : GameObject(renderingEngine)
{
    reset();
}

void Player::render()
{
    const auto snakeHead = m_snakePositions.front();
    renderer_.renderSnakeBox(*snakeHead, SnakeBodyPart::Head);

    if (m_snakePositions.size() > 1)
    {
        for (auto point = m_snakePositions.begin() + 1; point != m_snakePositions.end() - 1; ++point)
        {
            renderer_.renderSnakeBox(**point, SnakeBodyPart::Body);
        }
        const auto snakeTail = m_snakePositions.back();
        renderer_.renderSnakeBox(*snakeTail, SnakeBodyPart::Tail);
    }
}

void Player::moveSnake()
{
    moveDirection_ = futureMoveDirection_;
    const auto snakeHead = m_snakePositions.front();
    DirectionalPoint2D newPosition = *snakeHead;
    
    *snakeHead = Utils::getNextPosition(*snakeHead, moveDirection_);
    newPosition.direction.next = snakeHead->direction.prev;

    if (m_snakePositions.size() > 1)
    {
        auto mIter = m_snakePositions.begin();
        for (advance(mIter, 1); mIter != m_snakePositions.end(); ++mIter)
        {
            const DirectionalPoint2D oldPosition = **mIter;
            **mIter = newPosition;
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

void Player::reset()
{
    m_snakePositions.clear();

    futureMoveDirection_ = Direction::right;
    moveDirection_ = futureMoveDirection_;

    DirectionalPoint2D* startPosition = new DirectionalPoint2D(
        Constants::SNAKE_START_POSITION_X,
        Constants::SNAKE_START_POSITION_Y,
        futureMoveDirection_);

    m_snakePositions.push_back(startPosition);

    for (int i = 1; i < Constants::SNAKE_INITIAL_LENGTH; i++)
    {
        m_snakePositions.push_back(
            new DirectionalPoint2D(
                //startPosition->x, startPosition->y + i, futureMoveDirection_));
                startPosition->x - i, startPosition->y, futureMoveDirection_));
    }

    needToIncreaseLength = false;
    isAlive = true;
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

DirectionalPoint2D Player::getHeadPosition() const
{
    return DirectionalPoint2D(*m_snakePositions[0]);
}

Direction Player::getDirection() const
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
        default:
            break;
    }
}

void Player::changeDirection(const Direction& direction)
{
    if (!oppositeDirections(moveDirection_, direction))
    {
        futureMoveDirection_ = direction;
    }
}

bool Player::oppositeDirections(const Direction& direction_one, const Direction& direction_two)
{
    return (direction_one == up && direction_two == down) 
        || (direction_one == down && direction_two == up) 
        || (direction_one == left && direction_two == right) 
        || (direction_one == right && direction_two == left);
}

void Player::moveSnakeHead(Point2D* const snakeHead, const Direction& direction)
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
        default:
            break;
    }
}