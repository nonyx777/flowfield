use std::f64;
use sfml::graphics::*;
use sfml::system::*;


//trig operations
pub fn sin(degree: f32) -> f32{
    let radian = deg2rad(degree);
    return radian.sin();
}
pub fn cos(degree: f32) -> f32{
    let radian = deg2rad(degree);
    return radian.cos();
}
pub fn atan2(y: f32, x: f32) -> f32{
    return y.atan2(x);
}
//angle conversion operations
pub fn deg2rad(degree: f32) -> f32{
    return degree.to_radians();
}
pub fn rad2deg(radian: f32) -> f32{
    return radian.to_degrees();
}
//vector operations
pub fn magnitude(vector: Vector2f) -> f32{
    return (vector.x.powf(2.0) + vector.y.powf(2_f32)).sqrt();
}
pub fn displacement(target_position: Vector2f, self_position: Vector2f) -> Vector2f{
    return target_position - self_position;
}
pub fn normalize(vector: Vector2f) -> Vector2f{
    let magnitude: f32 = magnitude(vector);
    return vector / magnitude;
}
pub fn dotProduct(a: Vector2f, b: Vector2f) -> f32{
    return a.x * b.x + a.y * b.y;
}
pub fn rotateBy90(vector: Vector2f) -> Vector2f{
    let x: f32 = vector.y;
    let y: f32 = -vector.x;
    return Vector2f::new(x, y);
}
pub fn rotate(vector: Vector2f, angle: f32) -> Vector2f{
    let a: Vector2f = Vector2f::new(cos(angle), sin(angle));
    let b: Vector2f = Vector2f::new(-sin(angle), cos(angle));
    let rotated: Vector2f = Vector2f::new(vector.x * a.x - vector.y * b.x, vector.x * a.y + vector.y * b.y);
    return rotated;
}
pub fn vectorProjection(a: Vector2f, b: Vector2f) -> Vector2f{
    let p: f32 = dotProduct(a, b)/magnitude(b).powf(2_f32);
    return b * p;
}
    
//extras
pub fn clampOnRange(x: f32, min: f32, max:f32) -> f32{
    if x < min{
        return min;
    }
    else if x > max{
        return max;
    }
    else{
        return x;
    }
}
