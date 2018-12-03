#ifndef MISFORTUNES_H
#define MISFORTUNES_H
#include "Player.h"
#include "Player.cpp"
#include <vector>
namespace event
{
class SickEvent
{

private:

    //int eventId;
    int mumberId;
    int deadChance;

public:

    const static int DEADCHANCE = 70;
    const static int AFTERHEAL_DEADCHANCE = 50;
    const static int AFTERREST_DEADCHANCE = 30;

    SickEvent() {}
    SickEvent(int mumberId)
    {
        this->mumberId = mumberId;
        this->deadChance = DEADCHANCE;
    }
    int getDeadChance()
    {
        return deadChance;
    }
    int getMemberId()
    {
        return mumberId;
    }
    int healing()
    {
        deadChance = AFTERHEAL_DEADCHANCE;
        return 1;
    }
    int resting()
    {
        deadChance = AFTERREST_DEADCHANCE;
        return 1;
    }

};
}
class Misfortunes
{
private:

    Player *player;

    int count_sickEvents;
    std::vector<event::SickEvent> sickEvents;

    const static int DENOMINATOR = 100;
    const static int PROBABILITY = 40;

public:

    const static int NOBODYDEAD = -1;
    const static int HAPPENED = 1;
    const static int NOTHAPPENED = 0;

    const static int EVENT_COUNT = 3;
    const static int EVENT_SOMEBODY_SICK = 0;
    const static int EVENT_OXEN_DEAD = 1;
    const static int EVENT_WAGON_BROKEN = 2;
    const static int EVENT_SOMEBODY_DEAD = 3;

    Misfortunes();
    Misfortunes(Player *player);
    int setPlayer(Player *player);

    int get_misfortunes();
    int get_eventType();
    int continue_sickEvent();
    int generate_sickEvent(int mumberId);

    int eventGenerate_somebodyGetSick();
    int eventGenerate_oxenDead();
    int eventGenerate_wagonBroken();

    int rest();
};
#endif // MISFORTUNES_H
