#[allow(non_snake_case)]

use std::time;
use sfml::graphics::*;
use sfml::system::*;
use sfml::window::{Key};

use crate::operations;

pub struct Ball<'a>{
    pub property: CircleShape<'a>,
    radius: f32,
    velocity: Vector2f,
    acceleration: Vector2f,
}

impl Ball<'_>{
    pub fn new(radius: f32) -> Self {
        let mut property = CircleShape::new(radius, 30_usize);
        property.set_fill_color(Color::WHITE);
        property.set_origin((radius, radius));
        property.set_position(Vector2f::new(800_f32/2_f32, 600_f32/2_f32));
        Ball {
            property,
            radius,
            velocity: Vector2f::new(1_f32, 1_f32),
            acceleration: Vector2f::new(0_f32, 0_f32),
        }
    }

    //updater and displayer
    pub fn update(&mut self, vector: &Vector2f){
        //....
    }
    pub fn render(&mut self, target: &mut dyn RenderTarget){
        target.draw(&self.property);
    }

    //accessors and mutators
    pub fn getRadius(&self) -> f32{
        return self.radius;
    }
    pub fn getPosition(&self) -> Vector2f{
        return self.property.position();
    }
    pub fn getVelocity(&self) -> Vector2f{
        return self.velocity;
    }
    pub fn getAcceleration(&self) -> Vector2f{
        return self.acceleration;
    }
    pub fn setPosition(&mut self, position: Vector2f){
        self.property.set_position(position);
    }
    pub fn setVelocity(&mut self, velocity: Vector2f){
        self.velocity = velocity;
    }
    pub fn setAcceleration(&mut self, acceleration: Vector2f){
        self.acceleration = acceleration;
    }
}
