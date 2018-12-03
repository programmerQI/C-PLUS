#ifndef HUNT_CPP
#define HUNT_CPP
#include <cstdlib>
#include <ctime>
Hunt::Hunt()
{

}
int Hunt::encounter_rabbit()
{
    srand(time(NULL));
    if(rand()%DENOMINATOR < CHANCE_ECT_RABBIT)
    {
        return ENCOUNTERED;
    }
    return NOTENCOUNTERED;
}
int Hunt::encounter_fox()
{
    srand(time(NULL));
    if(rand()%DENOMINATOR < CHANCE_ECT_FOX)
    {
        return ENCOUNTERED;
    }
    return NOTENCOUNTERED;
}
int Hunt::encounter_deer()
{
    srand(time(NULL));
    if(rand()%DENOMINATOR < CHANCE_ECT_DEER)
    {
        return ENCOUNTERED;
    }
    return NOTENCOUNTERED;
}
int Hunt::encounter_beer()
{
    srand(time(NULL));
    if(rand()%DENOMINATOR < CHANCE_ECT_BEER)
    {
        return ENCOUNTERED;
    }
    return NOTENCOUNTERED;
}
int Hunt::encounter_moose()
{
    srand(time(NULL));
    if(rand()%DENOMINATOR < CHANCE_ECT_MOOSE)
    {
        return ENCOUNTERED;
    }
    return NOTENCOUNTERED;
}
#endif // HUNT_CPP
