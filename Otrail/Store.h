#ifndef STORE_H
#define STORE_H
class Store
{
private:

    int level;

    int oxenPrice;
    int foodPrice;
    int bulletsPrice;
    int wagonPartPrice;
    int medicalKitPrice;

public:

    const static int PRICE_OXEN = 100;
    const static int PRICE_FOOD = 1;
    const static int PRICE_BULLETS = 2;
    const static int PRICE_PART = 20;
    const static int PRICE_MEDICINE = 25;

    Store();
    Store(int level);

    int get_oxenPrice();
    int get_foodPrice();
    int get_bulletsPrice();
    int get_wagonPartPrice();
    int get_medicalKitPrice();

    int purchaseOxen(int amount);
    int purchaseFood(int amount);
    int purchaseBullets(int amount);
    int purchaseWagonPart(int amount);
    int purchaseMedicalKit(int amount);

};
#endif // STORE_H
