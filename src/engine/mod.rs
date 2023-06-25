use sfml::window::{ContextSettings, Style};
use sfml::graphics::{Color, RenderWindow, RenderTarget};
use sfml::window::Event;
use sfml::system::*;

use crate::entities::r#box;
use crate::entities::ball;
use crate::operations;

pub struct Engine<'a>{
    window: RenderWindow,
    //grid related variables
    grid: [[Vector2f; 160];160],
    grid_vector: [[Vector2f; 160];160],
    size: u32,
    row: u32,
    col: u32,
    ball: ball::Ball<'a>,
    mouse_position_view: Vector2f
}

impl Engine<'_>{
    pub fn new(width: u32, height: u32) -> Engine<'static>{
        let mut window = RenderWindow::new(
            (width, height),
            "Window",
            Style::DEFAULT,
            &ContextSettings::default(),
        );
        window.set_framerate_limit(60);

        //initializing grid
        let size: u32 = 5;
        let row: u32 = window.size().y/size;
        let col: u32 = window.size().x/size;
        let mut grid: [[Vector2f; 160];160] = [[Vector2f::default();160];160];
        let grid_vector: [[Vector2f; 160];160] = [[Vector2f::default();160];160];
        Self::gridLayout(&mut grid, size);

        //instantiating ball
        let ball: ball::Ball = ball::Ball::new(10_f32);
        //initializing mouse position variable
        let mouse_position_view: Vector2f = Vector2f::default();
        Engine { 
            window,
            grid,
            grid_vector,
            size,
            row,
            col,
            ball,
            mouse_position_view
        }
    }

    pub fn running(&mut self) -> bool {
        return self.window.is_open();
    }

    pub fn poll_event(&mut self) {
        while let Some(event) = self.window.poll_event() {
            match event {
                Event::Closed => self.window.close(),
                _ => {}
            }
        }
    }

    pub fn update(&mut self) {
        self.poll_event();
        //getting mouse position
        self.mouse_position_view = self.window.map_pixel_to_coords(self.window.mouse_position(), self.window.view());

        //.....
        self.gridAdjustVector();
        self.ball.update(&self.grid_vector);
    }

    pub fn render(&mut self) {
        self.window.clear(Color::BLACK);
        self.ball.render(&mut self.window);
        self.window.display();
    }

    //custom functions
    pub fn gridLayout(grid: &mut [[Vector2f; 160];160], size: u32){
        for i in 0..160{
            for j in 0..160{
                grid[i][j] = Vector2f::new(j as f32 * size as f32, i as f32 * size as f32);
            }
        }
    }

    pub fn gridAdjustVector(&mut self){
        for i in 0..160{
            for j in 0..160{
                self.grid_vector[i][j] = self.mouse_position_view - self.grid[i][j];
                // self.grid_vector[i][j] = Vector2f::new(1_f32, 0_f32);
                // println!("{}, {}", vector.x, vector.y);
            }
        }
    }
}
