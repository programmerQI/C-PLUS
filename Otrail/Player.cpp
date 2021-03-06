#ifndef PLAYER_CPP
#define PLAYER_CPP
#include <iostream>
Player::Player()
{

}
Player::Player(std::string leader, std::string member1, std::string member2, std::string member3, std::string member4)
{

    this->leader.name = leader;
    this->leader.status = ALIVE;

    this->member1.name = member1;
    this->member1.status = ALIVE;

    this->member2.name = member2;
    this->member2.status = ALIVE;

    this->member3.name = member3;
    this->member3.status = ALIVE;

    this->member4.name = member4;
    this->member4.status = ALIVE;

    money = 1400;
    oxen = 0;
    food = 0;
    bullets = 0;
    wagonPart = 0;
    medicalKit = 0;

}
void Player::init(std::string leader, std::string member1, std::string member2, std::string member3, std::string member4)
{

    this->leader.name = leader;
    this->leader.status = ALIVE;

    this->member1.name = member1;
    this->member1.status = ALIVE;

    this->member2.name = member2;
    this->member2.status = ALIVE;

    this->member3.name = member3;
    this->member3.status = ALIVE;

    this->member4.name = member4;
    this->member4.status = ALIVE;

    money = 1400;
    oxen = 0;
    food = 0;
    bullets = 0;
    wagonPart = 0;
    medicalKit = 0;

}

std::string Player::get_leaderName()
{
    return leader.name;
}

std::string Player::get_member1Name()
{
    return member1.name;
}

std::string Player::get_member2Name()
{
    return member2.name;
}

std::string Player::get_member3Name()
{
    return member3.name;
}

std::string Player::get_member4Name()
{
    return member4.name;
}

int Player::get_leaderStatus()
{
    return leader.status;
}
void Player::set_leaderStatus(int status)
{
    this->leader.status = status;
}

int Player::get_member1Status()
{
    return member1.status;
}
void Player::set_member1Status(int status)
{
    this->leader.status = status;
}

int Player::get_member2Status()
{
    return member2.status;
}
void Player::set_member2Status(int status)
{
    this->member2.status = status;
}

int Player::get_member3Status()
{
    return member3.status;
}
void Player::set_member3Status(int status)
{
    this->member3.status = status;
}

int Player::get_member4Status()
{
    return member4.status;
}
void Player::set_member4Status(int status)
{
    this->member4.status = status;
}

int Player::Player::get_money()
{
    return money;
}
int Player::add_money(int amount)
{
    money += amount;
    return SUCCESS;
}
int Player::reduce_money(int amount)
{
    if(amount > money)
    {
        return NOENOUGH_MONEY;
    }
    money -= amount;
    return SUCCESS;
}

int Player::get_oxen()
{
    return oxen;
}
int Player::add_oxen(int amount)
{
    oxen += amount;
    return SUCCESS;
}
int Player::reduce_oxen(int amount)
{
    oxen -= amount;
    if(amount > oxen)
    {
        return NOENOUGH_OXEN;
    }
    return SUCCESS;
}

int Player::get_food()
{
    return food;
}
int Player::add_food(int amount)
{
    food += amount;
    return SUCCESS;
}
int Player::reduce_food(int amount)
{
    food -= amount;
    if(amount > food)
    {
        return NOENOUGH_FOOD;
    }
    return SUCCESS;
}

int Player::get_bullets()
{
    return bullets;
}
int Player::add_bullets(int amount)
{
    bullets += amount * 20;
    return SUCCESS;
}
int Player::reduce_bullets(int amount)
{
    if(amount > bullets)
    {
        return NOENOUGH_BULLETS;
    }
    return SUCCESS;
}

int Player::get_wangonPart()
{
    return wagonPart;
}
int Player::add_wagonPart(int amount)
{
    wagonPart += amount;
    return SUCCESS;
}
int Player::reduce_wagonPart(int amount)
{
    if(amount > wagonPart)
    {
        return NOENOUGH_WAGONPART;
    }
    wagonPart -= amount;
    return SUCCESS;
}

int Player::get_medicalKit()
{
    return medicalKit;
}
int Player::add_medicalKit(int amount)
{
    medicalKit += amount;
    return SUCCESS;
}
int Player::reduce_medicalKit(int amount)
{
    if(amount > medicalKit)
    {
        return  NOENOUGH_MEDICALKIT;
    }
    medicalKit -= amount;
    return SUCCESS;
}

void Player::show_playerStatus()
{
    std::cout << "leader: " << leader.name << std::endl;
    std::cout << "member1: " << member1.name << std::endl;
    std::cout << "member2: " << member2.name << std::endl;
    std::cout << "member3: " << member3.name << std::endl;
    std::cout << "member4: " << member4.name << std::endl;
    std::cout << "money: " << money << std::endl;
    std::cout << "oxen: " << oxen << std::endl;
    std::cout << "food: " << food << std::endl;
    std::cout << "bullets: " << bullets << std::endl;
    std::cout << "wagonPart: " << wagonPart << std::endl;
    std::cout << "medicalKit: " << medicalKit << std::endl;
    return;
}
#endif // PLAYER_CPP
