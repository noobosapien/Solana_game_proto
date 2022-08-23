#include "headers/gamepch.h"

MouseInComponent::MouseInComponent(Actor *owner, int updateOrder) : Component(owner, updateOrder)
{
    mOwner->getGame()->addMouseInComp(this);
}

MouseInComponent::~MouseInComponent()
{
}

void MouseInComponent::update(float delta)
{
}

void MouseInComponent::mouseClicked(float x, float y)
{

    if (mOwner->getCanvasPos().x + 0.05 > x && mOwner->getCanvasPos().x - 0.05 < x && mOwner->getCanvasPos().y + 0.05 > y && mOwner->getCanvasPos().y - 0.05 < y)
    {
        std::cout << x << ", " << y << "   " << mOwner->getCanvasPos().x << ", " << mOwner->getCanvasPos().y
                  << "  " << mOwner->getScale() << std::endl;

        mOwner->getSpriteComponent()->setTint(glm::vec3(0.f, 1.f, 0.f));
        mOwner->getGame()->changeMouseClicked(this);
    }
}

void MouseInComponent::mouseUnClicked()
{
    mOwner->getSpriteComponent()->setTint(glm::vec3(1.f, 1.f, 1.f));
}