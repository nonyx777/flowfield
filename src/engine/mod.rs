use sfml::window::{ContextSettings, Style, mouse};
use sfml::graphics::{Color, RenderWindow, RenderTarget, Transformable, RectangleShape, Shape};
use sfml::window::Event;
use sfml::system::*;

use crate::entities::r#box;
use crate::entities::ball;
use crate::operations;

pub struct Engine<'a>{
    window: RenderWindow,
    //grid related variables
    size: u32,
    row: usize,
    col: usize,
    ball: ball::Ball<'a>,
    mouse_position_view: Vector2f,
    grid: Vec<Vec<r#box::Box<'a>>>,
    selected_cell: Vector2i
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
        let row: usize = 0;
        let col: usize = 0;
        
        //instantiating ball
        let ball: ball::Ball = ball::Ball::new(20_f32);
        //initializing mouse position variable
        let mouse_position_view: Vector2f = Vector2f::default();
        //initializing vector
        let mut grid: Vec<Vec<r#box::Box<'_>>> = Vec::new();
        Self::gridLayout(size, &mut grid);
        //initialize variable
        let selected_cell: Vector2i = Vector2i::default();
        Engine { 
            window,
            size,
            row,
            col,
            ball,
            mouse_position_view,
            grid,
            selected_cell
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

        self.destSelection();

        //.....
        //self.ball.update(&self.grid);
    }

    pub fn render(&mut self) {
        self.window.clear(Color::BLACK);
        self.ball.render(&mut self.window);
         for i in 0..40{
             for j in 0..40{
                 self.grid[i][j].render(&mut self.window);
             }
         }
        self.window.display();
    }

    //custom functions
    pub fn gridLayout(size: u32, grid: &mut Vec<Vec<r#box::Box>>){
        for i in 0..40{
            let mut box_vec: Vec<r#box::Box> = Vec::new(); 
            for j in 0..40{
                let _box: r#box::Box = r#box::Box::new(Vector2f::new(20_f32, 20_f32), Vector2f::new(j as f32 * size as f32, i as f32 * size as f32));
                box_vec.push(_box);
            }
            grid.push(box_vec);
        }
    }

    pub fn gridAdjustVector(&mut self){
        //...
    }

    pub fn destSelection(&mut self){
        if mouse::Button::Left.is_pressed(){
            //reverting the previous selected cell
            self.grid[self.selected_cell.y as usize][self.selected_cell.x as usize].property.set_fill_color(Color::TRANSPARENT);
            self.grid[self.selected_cell.y as usize][self.selected_cell.x as usize].cost = 1;

            //getting the new selected cell
            self.col = ((self.mouse_position_view.x/self.size as f32).floor()) as usize;
            self.row = ((self.mouse_position_view.y/self.size as f32).floor()) as usize;
            self.grid[self.row][self.col].property.set_fill_color(Color::RED);
            self.grid[self.row][self.col].cost = 0;
            //saving selected cell
            self.selected_cell = Vector2i::new(self.col as i32, self.row as i32);
        }

    }
}
