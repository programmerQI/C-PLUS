#ifndef STORE_CPP
#define STORE_CPP
#include "Store.h"
Store::Store()
{
    level = 1;

    oxenPrice = PRICE_OXEN;
    foodPrice = PRICE_FOOD;
    bulletsPrice = PRICE_BULLETS;
    wagonPartPrice = PRICE_PART;
    medicalKitPrice = PRICE_MEDICINE;

}
Store::Store(int level)
{

    this->level = level + 1;

    oxenPrice = PRICE_OXEN * this->level;
    foodPrice = PRICE_FOOD * this->level;
    bulletsPrice = PRICE_BULLETS * this->level;
    wagonPartPrice = PRICE_PART * this->level;
    medicalKitPrice = PRICE_MEDICINE * this->level;

}
int Store::get_oxenPrice()
{
    return oxenPrice;
}
int Store::get_foodPrice()
{
    return foodPrice;
}
int Store::get_bulletsPrice()
{
    return bulletsPrice;
}
int Store::get_wagonPartPrice()
{
    return wagonPartPrice;
}
int Store::get_medicalKitPrice()
{
    return medicalKitPrice;
}
int Store::purchaseOxen(int amount)
{
    return oxenPrice * amount;
}
int Store::purchaseFood(int amount)
{
    return foodPrice * amount;
}
int Store::purchaseBullets(int amount)
{
    return bulletsPrice * amount;
}
int Store::purchaseWagonPart(int amount)
{
    return wagonPartPrice * amount;
}
int Store::purchaseMedicalKit(int amount)
{
    return medicalKitPrice * amount;
}
#endif // STORE_CPP
