#ifndef WEAPON_H
#define WEAPON_H


class Weapon
{
public:
    Weapon();
    Weapon(int power, int prepareTime, int atackTime) :
        m_power(power), m_prepareTime(prepareTime), m_atackTime(atackTime) {}
    virtual ~Weapon();

    int getPower()const
    {
        return m_power;
    }
    void setPower(int val)
    {
        m_power = val;
    }
    int getPrepareTime()const
    {
        return m_prepareTime;
    }
    void setPrepareTime(int val)
    {
        m_prepareTime = val;
    }
    int getAtackTime()const
    {
        return m_atackTime;
    }
    void setAtackTime(int val)
    {
        m_atackTime = val;
    }

    virtual void upgradePower()
    {
        m_power++;
    }

protected:

private:
    int m_power;
    int m_prepareTime;
    int m_atackTime;
};

#endif // WEAPON_H
