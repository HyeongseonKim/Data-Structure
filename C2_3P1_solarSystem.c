#include <stdio.h>
#include <stdlib.h>

enum planetField {
    Mercury = 0,
    Venus,
    Earth,
    Mars,
    Jupiter,
    Saturn,
    Uranus,
    Neptune
};

typedef struct SolarSystem{
    enum planetField planetType;

    float distanceFromSun, numOfSatelites;
}solarsystem;

void main(void)
{
    solarsystem planet;    // 열거형 변수 선언

    planet.planetType= Mercury;    // 열거형 값 할당

    printf("%d\n", planet.planetType);   // 2: Tuesday의 값 출력
}
