#ifndef PLAYER_H
#define PLAYER_H
struct Member{
    std::string name;
    int status;
};
class Player
{
private:

    //
    Member leader;
    Member member1;
    Member member2;
    Member member3;
    Member member4;

    //
    int money;
    int oxen;
    int food;
    int bullets;

    //
    int wagonPart;
    int medicalKit;

public:

    const static int ALIVE = 100;
    const static int SICK = 101;
    const static int DEAD = 102;

    const static int SUCCESS = 111;
    const static int NOENOUGH_MONEY = -201;
    const static int NOENOUGH_OXEN = -202;
    const static int NOENOUGH_FOOD = -203;
    const static int NOENOUGH_BULLETS = -204;
    const static int NOENOUGH_WAGONPART = -205;
    const static int NOENOUGH_MEDICALKIT = -206;


    Player();
    Player(std::string leader, std::string member1, std::string member2, std::string member3, std::string member4);
    void init(std::string leader, std::string member1, std::string member2, std::string member3, std::string member4);


    int get_money();
    int add_money(int amount);
    int reduce_money(int amount);

    int get_oxen();
    int add_oxen(int amount);
    int reduce_oxen(int amount);

    int get_food();
    int add_food(int amount);
    int reduce_food(int amount);

    int get_bullets();
    int add_bullets(int amount);
    int reduce_bullets(int amount);

    int get_wangonPart();
    int add_wagonPart(int amount);
    int reduce_wagonPart(int amount);

    int get_medicalKit();
    int add_medicalKit(int amount);
    int reduce_medicalKit(int amount);

    void show_playerStatus();
};
#endif // PLAYER_H

