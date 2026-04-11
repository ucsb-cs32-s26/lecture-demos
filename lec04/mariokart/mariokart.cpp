#include "kart.h"
#include "bike.h"
#include "monsterTruck.h"
using namespace std;

int main() {
    MonsterTruck monsterTruck("bowser");
    Bike bike("peach");

    monsterTruck.displayStats();
    monsterTruck.specialMove();

    bike.displayStats();
    bike.specialMove();

    return 0;
}
