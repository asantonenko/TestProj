#ifndef SWORD_H
#define SWORD_H

#include "Weapon.h"


class Sword : public Weapon
{
public:
    Sword() : Weapon(5,0,1) {}
    Sword (int power, int prepareTime, int atackTime): Weapon(power, prepareTime, atackTime) {}

    void upgradePower() override
    {
        setPower(getPower()+2);
    }

    virtual ~Sword();

protected:

private:
};

#endif // SWORD_H
