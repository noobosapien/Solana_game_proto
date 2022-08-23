#ifndef MOUSEINCOMP_H
#define MOUSEINCOMP_H

#define PI 3.14159265359

class MouseInComponent : public Component
{
public:
    MouseInComponent(Actor *owner, int updateOrder = 10);
    ~MouseInComponent();

    void update(float delta) override;
    void mouseClicked(float x, float y);
    void mouseUnClicked();
};

#endif