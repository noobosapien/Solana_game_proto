#ifndef OBJECT_H
#define OBJECT_H

enum class TYPE
{
    TYPE_1,
    TYPE_2,
    TYPE_3,
    TYPE_4,
    TYPE_5,
    TYPE_6,
    TYPE_7,
    TYPE_8,
    TYPE_9,
    TYPE_10,
    TYPE_11,
    TYPE_12,
};

class Object : public Actor
{
public:
    Object(Game *game, GameLevel *level, glm::vec2 pos, float scale, TYPE type);
    ~Object();

    void updateActor(float delta) override;
    class CollisionComponent *getCollider() { return mCollider; }
    unsigned int getID() { return mID; }

private:
    class CollisionComponent *mCollider;
    unsigned int mID;

    static unsigned int getNewID();
    static unsigned int mLastID;
};

#endif