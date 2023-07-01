#[allow(non_snake_case)]

use sfml::graphics::*;
use sfml::system::*;

pub struct Box<'a>{
    pub property: RectangleShape<'a>,
    size: Vector2f,
    position: Vector2f,
    velocity: Vector2f,
    acceleration: Vector2f,
    pub cost: u32,
}

impl Box<'_>{
    pub fn new(size: Vector2f, position: Vector2f) -> Self{
        let mut property = RectangleShape::new();
        property.set_fill_color(Color::TRANSPARENT);
        property.set_outline_color(Color::WHITE);
        property.set_outline_thickness(1_f32);
        property.set_size(size);
        property.set_position(position);

        //defualt cost
        let cost: u32 = 1;

        Box {
            property,
            size,
            position: Vector2f::default(),
            velocity: Vector2f::default(),
            acceleration: Vector2f::default(),
            cost
        }
    }

    pub fn update(&mut self){
        //.....
    }

    pub fn render(&mut self, target: &mut dyn RenderTarget){
        target.draw(&self.property);
    }
}
