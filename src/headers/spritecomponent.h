#ifndef SPRITE_COMPONENT_H
#define SPRITE_COMPONENT_H

class SpriteComponent : public Component
{

public:
    SpriteComponent(class Actor *owner, int drawOrder = 100);
    virtual ~SpriteComponent();

    virtual void draw(class Shader *shader);
    virtual void setTexture(class Texture *texture);

    void setTint(glm::vec3 tint);

    int getDrawOrder() { return mDrawOrder; }
    int getTexWidth() { return mTexWidth; }
    int getTexHeight() { return mTexHeight; }

private:
    class Texture *mTexture;
    int mDrawOrder;
    int mTexWidth;
    int mTexHeight;

    glm::vec3 mTint;
};

#endif