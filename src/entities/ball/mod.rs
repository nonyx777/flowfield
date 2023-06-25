#[allow(non_snake_case)]

use std::f64;
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
    max_speed: f32,
    max_force: f32
}

impl Ball<'_>{
    pub fn new(radius: f32) -> Self {
        let mut property = CircleShape::new(radius, 30_usize);
        property.set_fill_color(Color::WHITE);
        property.set_origin((radius, radius));
        property.set_position(Vector2f::new(800_f32/2_f32, 800_f32/2_f32));

        let max_speed: f32 = 5_f32;
        let max_force: f32 = 0.05_f32;

        Ball {
            property,
            radius,
            velocity: Vector2f::new(1_f32, 1_f32),
            acceleration: Vector2f::new(0_f32, 0_f32),
            max_speed,
            max_force
        }
    }

    //updater and displayer
    pub fn update(&mut self, grid: &[[Vector2f; 40];40]){
        self.seek(grid);
    }
    pub fn render(&mut self, target: &mut dyn RenderTarget){
        target.draw(&self.property);
    }

    pub fn seek(&mut self, grid: &[[Vector2f;40];40]){
        let x: usize = ((self.getPosition().x/20_f32).floor()) as usize;
        let y: usize = ((self.getPosition().y/20_f32).floor()) as usize;
        

        let mut desired: Vector2f = grid[x][y];
        desired *= self.max_speed;

        let steer: Vector2f = desired - self.getVelocity();

        //integration
        self.setAcceleration(steer * self.max_force);
        self.setVelocity(self.getVelocity() + self.getAcceleration());
        self.property.set_position(self.getPosition() + self.getVelocity() * 0.5_f32);

        //revert acceleration
        self.setAcceleration(Vector2f::default());
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
