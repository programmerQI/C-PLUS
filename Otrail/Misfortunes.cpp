#ifndef MISFORTUNES_CPP
#define MISFORTUNES_CPP
#include <cstdlib>
#include <ctime>
Misfortunes::Misfortunes()
{
    count_sickEvents = 0;
}
Misfortunes::Misfortunes(Player *player)
{
    this->player = player;
    count_sickEvents = 0;
}
int Misfortunes::setPlayer(Player *player)
{
    this->player = player;
}
int Misfortunes::get_misfortunes()
{
    srand(std::time(NULL));
    if(rand()%DENOMINATOR < PROBABILITY)
    {
        return HAPPENED;
    }
    return NOTHAPPENED;
}
int Misfortunes::get_eventType()
{
    srand(std::time(NULL));
    return rand()%EVENT_COUNT;
}
int Misfortunes::continue_sickEvent()
{
    int mem = -1;
    int id;
    for(int i = 0 ; i < count_sickEvents ; i ++)
    {
        srand(std::time(NULL));
        if(rand()%DENOMINATOR < ((event::SickEvent)sickEvents[i]).getDeadChance())
        {
            mem = i;
            id = sickEvents[i].getMemberId();
            break;
        }
    }
    if(mem = -1)
    {
        return NOBODYDEAD;
    }
    else
    {
        sickEvents.erase(sickEvents.begin()+mem);
        if( id == 0 )
        {
            player->set_leaderStatus(player->DEAD);
        }
        else if( id == 1 )
        {
            player->set_member1Status(player->DEAD);
        }
        else if( id == 2 )
        {
            player->set_member2Status(player->DEAD);
        }
        else if( id == 3 )
        {
            player->set_member3Status(player->DEAD);
        }
        else if( id == 4 )
        {
            player->set_member4Status(player->DEAD);
        }
        return id;
    }
}
int Misfortunes::generate_sickEvent(int mumberId)
{
    event::SickEvent newEvent(mumberId);
    sickEvents.push_back(newEvent);
    return EVENT_SOMEBODY_SICK;
}
int Misfortunes::eventGenerate_somebodyGetSick()
{
    srand(std::time(NULL));
    int who = rand()%5;
    switch(who)
    {
    case 0:
        if(player->get_leaderStatus() == player->ALIVE)
        {
            generate_sickEvent(0);
            player->set_leaderStatus(player->SICK);
        }
        return 0;
        break;
    case 1:
        if(player->get_member1Status() == player->ALIVE)
        {
            generate_sickEvent(1);
            player->set_member1Status(player->SICK);
        }
        return 1;
        break;
    case 2:
        if(player->get_member2Status() == player->ALIVE)
        {
            generate_sickEvent(2);
            player->set_member2Status(player->SICK);
        }
        return 2;
        break;
    case 3:
        if(player->get_member3Status() == player->ALIVE)
        {
            generate_sickEvent(3);
            player->set_member3Status(player->SICK);
        }
        return 3;
        break;
    case 4:
        if(player->get_member4Status() == player->ALIVE)
        {
            generate_sickEvent(4);
            player->set_member4Status(player->ALIVE);
        }
        return 4;
        break;
    default:
        break;
    }
}
int Misfortunes::rest()
{
    for(int i = 0 ; i < count_sickEvents ; i ++ )
    {
        sickEvents[i].resting();
    }
}
#endif // MISFORTUNES_CPP
