#ifndef HUNT_H
#define HUNT_H
class Hunt
{

private:

    const static int DENOMINATOR = 100;
    const static int CHANCE_ECT_RABBIT = 50;
    const static int CHANCE_ECT_FOX = 25;
    const static int CHANCE_ECT_DEER = 15;
    const static int CHANCE_ECT_BEER = 7;
    const static int CHANCE_ECT_MOOSE = 5;

public:

    const static int ENCOUNTERED = 1;
    const static int NOTENCOUNTERED = 0;

    Hunt();
    int encounter_rabbit();
    int encounter_fox();
    int encounter_deer();
    int encounter_beer();
    int encounter_moose();
};
#endif // HUNT_H
