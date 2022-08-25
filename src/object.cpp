#include "headers/gamepch.h"

unsigned int Object::mLastID = 1;

Object::Object(Game *game, GameLevel *level, glm::vec2 pos, float scale, TYPE type) : Actor(game), mCollider(nullptr)
{
    int value = 0;

    game->addEnvironment(this);
    mID = getNewID();

    auto sc = new SpriteComponent(this, 100);
    setSpriteComponent(sc);

    setScale(scale);
    // setPosition(glm::vec2((pos.x - Game::WIN_WIDTH) / Game::WIN_WIDTH, (pos.y - Game::WIN_HEIGHT) / Game::WIN_HEIGHT));
    setPosition(glm::vec2(pos.x, pos.y));

    std::cout << getCanvasPos().x << ", " << getCanvasPos().y << "   " << getPosition().x << ", " << getPosition().y << std::endl;

    RectangleShapeComponent *rsc = new RectangleShapeComponent(this, static_cast<float>(getScale() * 2),
                                                               static_cast<float>(getScale() * 2));

    mCollider = new CollisionComponent(this, rsc);

    switch (type)
    {
    case TYPE::TYPE_1:
        sc->setTexture(game->getTexture("src/assets/textures/1.png"));
        value = 1;

        break;

    case TYPE::TYPE_2:
        sc->setTexture(game->getTexture("src/assets/textures/2.png"));
        value = 2;

        break;

    case TYPE::TYPE_3:
        sc->setTexture(game->getTexture("src/assets/textures/3.png"));
        value = 3;

        break;

    case TYPE::TYPE_4:
        sc->setTexture(game->getTexture("src/assets/textures/4.png"));
        value = 4;

        break;

    case TYPE::TYPE_5:
        sc->setTexture(game->getTexture("src/assets/textures/5.png"));
        value = 5;

        break;

    case TYPE::TYPE_6:
        sc->setTexture(game->getTexture("src/assets/textures/6.png"));
        value = 6;

        break;

    case TYPE::TYPE_7:
        sc->setTexture(game->getTexture("src/assets/textures/7.png"));
        value = 7;

        break;

    case TYPE::TYPE_8:
        sc->setTexture(game->getTexture("src/assets/textures/8.png"));
        value = 8;

        break;

    case TYPE::TYPE_9:
        sc->setTexture(game->getTexture("src/assets/textures/9.png"));
        value = 9;

        break;

    case TYPE::TYPE_10:
        sc->setTexture(game->getTexture("src/assets/textures/10.png"));
        value = 10;

        break;

    case TYPE::TYPE_11:
        sc->setTexture(game->getTexture("src/assets/textures/11.png"));
        value = 11;

        break;

    case TYPE::TYPE_12:
        sc->setTexture(game->getTexture("src/assets/textures/12.png"));
        value = 12;

        break;
    default:
        break;
    }

    new MouseInComponent(this, value);

    level->addObject(this);
}

Object::~Object()
{
}

void Object::updateActor(float delta)
{
}

unsigned int Object::getNewID()
{
    return mLastID++;
}