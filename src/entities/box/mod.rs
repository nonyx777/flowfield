#[allow(non_snake_case)]

use sfml::graphics::*;
use sfml::system::*;

pub struct Box<'a>{
    pub property: RectangleShape<'a>,
    size: Vector2f,
    position: Vector2f,
    velocity: Vector2f,
    acceleration: Vector2f
}

impl Box<'_>{
    pub fn new(size: Vector2f, position: Vector2f) -> Self{
        let mut property = RectangleShape::new();
        property.set_fill_color(Color::WHITE);
        property.set_size(size);
        property.set_position(position);

        Box {
            property,
            size,
            position: Vector2f::default(),
            velocity: Vector2f::default(),
            acceleration: Vector2f::default()
        }
    }

    pub fn update(&mut self){
        //.....
    }

    pub fn render(&mut self, target: &mut dyn RenderTarget){
        target.draw(&self.property);
    }
}
