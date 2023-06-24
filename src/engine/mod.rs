use sfml::window::{ContextSettings, Style};
use sfml::graphics::{Color, RenderWindow, RenderTarget};
use sfml::window::Event;
use sfml::system::*;

use crate::entities::r#box;

pub struct Engine{
    window: RenderWindow,
    //grid related variables
    grid: [[Vector2f; 40];40],
    size: u32,
    row: u32,
    col: u32
}

impl Engine{
    pub fn new(width: u32, height: u32) -> Engine{
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
        Self::gridLayout(&mut grid, size);
        Engine { 
            window,
            grid,
            size,
            row,
            col
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

        for i in 0..40{
            for j in 0..40{
                println!("{}, {}", self.grid[i][j].y, self.grid[i][j].x);
            }
        }
    }

    pub fn render(&mut self) {
        self.window.clear(Color::BLACK);
        self.window.display();
    }

    //custom functions
    pub fn gridLayout(grid: &mut [[Vector2f; 40];40], size: u32){
        for i in 0..40{
            for j in 0..40{
                grid[i][j] = Vector2f::new(j as f32 * size as f32, i as f32* size as f32);
            }
        }
    }
}
