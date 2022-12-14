#ifndef ACTOR_H
#define ACTOR_H

class Actor
{
public:
    enum State
    {
        EActive,
        EPaused,
        EDead
    };

    Actor(class Game *game);
    virtual ~Actor();

    void update(float delta);
    void updateComponents(float delta);
    virtual void updateActor(float delta);

    void processInput(SDL_Event &event);
    virtual void actorInput(const SDL_Event &event);

    inline void setPosition(const glm::vec2 &pos)
    {
        mPosition = pos;
        glm::vec2 canvasPos = glm::vec2(0.f);

        canvasPos.x = (pos.x + 1.f) / 2;
        canvasPos.y = (pos.y - 1.f) / -2;
        mCanvasPos = canvasPos;

        mRecomputeWorldTransform = true;
    }
    inline const glm::vec2 &getPosition() { return mPosition; }
    inline const glm::vec2 &getCanvasPos() { return mCanvasPos; }
    inline void setScale(float scale)
    {
        mScale = scale;
        mRecomputeWorldTransform = true;
    }
    inline const float getScale() { return mScale; }
    inline void setRotation(float rotation)
    {
        mRotation = rotation;
        mRecomputeWorldTransform = true;
    }
    inline const float getRotation() { return mRotation; }

    void computeWorldTransform();
    inline const glm::mat4 &getWorldTransform() { return mWorldTransform; }

    glm::vec2 getForward() { return glm::vec2(glm::cos(glm::radians(mRotation)), glm::sin(glm::radians(mRotation))); }

    State getState() { return mState; }
    void setState(State state) { mState = state; }

    class Game *getGame() { return mGame; }

    void addComponent(class Component *component);
    void removeComponent(class Component *component);

    class SpriteComponent *getSpriteComponent() { return mSpriteComponent; }
    void setSpriteComponent(class SpriteComponent *spc) { mSpriteComponent = spc; }

private:
    State mState;
    glm::vec2 mPosition;
    glm::vec2 mCanvasPos;
    glm::mat4 mWorldTransform;
    float mScale;
    float mRotation;
    bool mRecomputeWorldTransform;
    class Game *mGame;
    class SpriteComponent *mSpriteComponent;

    std::vector<class Component *> mComponents;
};

#endif