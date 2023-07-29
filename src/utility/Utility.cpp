#include "../../include/utility/Utility.hpp"

//defining trig functions
float Utility::_sin(float degree){
    float radian = degree * Utility::_deg2Rad();
    double radian_double = static_cast<double> (radian);
    float sin_value = sin(radian_double); 
    return sin_value;
}
float Utility::_cos(float degree){
    float radian = degree * Utility::_deg2Rad();
    double radian_double = static_cast<double> (radian);
    float cos_value = cos(radian_double);
    return cos_value;
}
float Utility::_acos(float point){
    double point_double = point;
    float angle_value = acos(point_double) * Utility::_rad2Deg();
    return angle_value;
}
float Utility::_atan2(float y, float x){
    float atan2_value = atan2(y, x) * Utility::_rad2Deg();
    return atan2_value;
}
//angle conversion functions
float Utility::_rad2Deg(){
    return 180.f/PI;
}
float Utility::_deg2Rad(){
    return PI/180.f;
}

//defining vector functions
float Utility::_magnitude(sf::Vector2f vector){
    return sqrt(pow(vector.x, 2) + pow(vector.y, 2));
}
sf::Vector2f Utility::_displacement(sf::Vector2f target_position, sf::Vector2f self_position){
    sf::Vector2f displacement = sf::Vector2f(
        target_position.x - self_position.x, target_position.y - self_position.y
    );
    return displacement;
}
float Utility::_distance(sf::Vector2f vector){
    float distance = Utility::_magnitude(vector);
    return distance;
}
sf::Vector2f Utility::_unitVector(sf::Vector2f vector){
    float magnitude = Utility::_magnitude(vector);
    sf::Vector2f unit_vector = sf::Vector2f(vector.x, vector.y)/magnitude;
    return unit_vector;
}
sf::Vector2f Utility::_rotate(sf::Vector2f vector, float angle){
    sf::Vector2f a = sf::Vector2f(Utility::_cos(angle), Utility::_sin(angle));
    sf::Vector2f b = sf::Vector2f(-Utility::_sin(angle), Utility::_cos(angle));
    sf::Vector2f rotation = sf::Vector2f(vector.x * a.x - vector.y * b.x, 
    vector.x * a.y + vector.y * b.y);
    return rotation;
}
sf::Vector2f Utility::_rotateBy90(sf::Vector2f vector){
    float x = vector.y;
    float y = -vector.x;
    return sf::Vector2f(x, y);
}
sf::Vector2f Utility::_translate(sf::Vector2f vector_a, sf::Vector2f vector_b, float speed){
    sf::Vector2f distance = Utility::_displacement(vector_b, vector_a);
    return vector_a += distance * speed;
}
sf::Vector2f Utility::_transalte(sf::Vector2f vector_a, sf::Vector2f _Vector_b){
    sf::Vector2f distance = Utility::_displacement(_Vector_b, vector_a);
    return vector_a += distance;
}
float Utility::_dotProduct(sf::Vector2f a, sf::Vector2f b){
    return a.x * b.x + a.y * b.y;
}
bool Utility::_parallelVectors(sf::Vector2f a, sf::Vector2f b){
    sf::Vector2f rotated_vector_a = Utility::_rotateBy90(a);
    float dot_product = Utility::_dotProduct(rotated_vector_a, b);
    cout << round(dot_product) << endl;
    if(round(dot_product) >= -0.f && round(dot_product) <= 0.f)
        return true;
    else
        return false;
}
sf::Vector2f Utility::_vectorProjection(sf::Vector2f a, sf::Vector2f b){
    float p_1 = Utility::_dotProduct(a, b)/pow(Utility::_magnitude(b), 2);
    return b*p_1;
}
float Utility::_angleBetween(sf::Vector2f a, sf::Vector2f b){
    float angle = Utility::_dotProduct(a, b)/Utility::_magnitude(a)*Utility::_magnitude(b);
    return angle;
}

//...
float Utility::_clampOnRange(float x, float min, float max){
    if(x < min)
        return min;
    else if(max < x)
        return max;
    else
        return x;
}
