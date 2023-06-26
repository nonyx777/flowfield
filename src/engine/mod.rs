use sfml::window::{ContextSettings, Style};
use sfml::graphics::{Color, RenderWindow, RenderTarget, Transformable, RectangleShape};
use sfml::window::Event;
use sfml::system::*;

use crate::entities::r#box;
use crate::entities::ball;
use crate::operations;

pub struct Engine<'a>{
    window: RenderWindow,
    //grid related variables
    grid: [[Vector2f; 40];40],
    grid_vector: [[Vector2f; 40];40],
    size: u32,
    row: u32,
    col: u32,
    ball: ball::Ball<'a>,
    mouse_position_view: Vector2f,
    box_container: Vec<Vec<r#box::Box<'a>>>
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
        let size: u32 = 20;
        let row: u32 = window.size().y/size;
        let col: u32 = window.size().x/size;
        let mut grid: [[Vector2f; 40];40] = [[Vector2f::default();40];40];
        let grid_vector: [[Vector2f; 40];40] = [[Vector2f::default();40];40];
        
        //instantiating ball
        let ball: ball::Ball = ball::Ball::new(20_f32);
        //initializing mouse position variable
        let mouse_position_view: Vector2f = Vector2f::default();
        //initializing vector
        let mut box_container: Vec<Vec<r#box::Box<'_>>> = Vec::new();
        Self::gridLayout(&mut grid, size, &mut box_container);
        Engine { 
            window,
            grid,
            grid_vector,
            size,
            row,
            col,
            ball,
            mouse_position_view,
            box_container
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
        // for i in 0..40{
        //     for j in 0..40{
        //         self.box_container[i][j].render(&mut self.window);
        //     }
        // }
        self.window.display();
    }

    //custom functions
    pub fn gridLayout(grid: &mut [[Vector2f; 40];40], size: u32, box_container: &mut Vec<Vec<r#box::Box>>){
        for i in 0..40{
            let mut box_vec: Vec<r#box::Box> = Vec::new(); 
            for j in 0..40{
                grid[i][j] = Vector2f::new(j as f32 * size as f32, i as f32 * size as f32);
                let _box: r#box::Box = r#box::Box::new(Vector2f::new(20_f32, 20_f32), Vector2f::new(j as f32 * size as f32, i as f32 * size as f32));
                box_vec.push(_box);
            }
            box_container.push(box_vec);
        }
    }

    pub fn gridAdjustVector(&mut self){
        for i in 0..40{
            for j in 0..40{
                self.grid_vector[i][j] = operations::normalize(self.grid[39][39] - self.grid[i][j]);
                // self.grid_vector[i][j] = Vector2f::new(1_f32, 1_f32);
            }
        }
    }
}
