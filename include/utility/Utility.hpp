#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>

#define PI 3.14159265

using namespace std;

class Utility{
    public:
        //trig operations
        static float _sin(float degree);
        static float _cos(float degree);
        static float _acos(float point);
        static float _atan2(float y, float x);

        //angle conversion operations
        static float _rad2Deg();
        static float _deg2Rad();

        //vector operations
        static float _magnitude(sf::Vector2f vector);
        static sf::Vector2f _displacement(sf::Vector2f target_position, sf::Vector2f self_position);
        static float _distance(sf::Vector2f vector);
        static sf::Vector2f _unitVector(sf::Vector2f _displacement);
        static sf::Vector2f _rotate(sf::Vector2f vector, float angle);
        static sf::Vector2f _rotateBy90(sf::Vector2f vector);
        static sf::Vector2f _translate(sf::Vector2f vector_a, sf::Vector2f vector_b, float speed);
        static sf::Vector2f _transalte(sf::Vector2f vector_a, sf::Vector2f vector_b);
        static float _dotProduct(sf::Vector2f a, sf::Vector2f b);
        static bool _parallelVectors(sf::Vector2f a, sf::Vector2f b);
        static sf::Vector2f _vectorProjection(sf::Vector2f a, sf::Vector2f b);
        static float _angleBetween(sf::Vector2f a, sf::Vector2f b);

        //...
        static float _clampOnRange(float x, float min, float max);
};
