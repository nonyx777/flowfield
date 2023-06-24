use sfml::window::{ContextSettings, Style};
use sfml::graphics::{Color, RenderWindow, RenderTarget};
use sfml::window::Event;

pub struct Engine {
    window: RenderWindow,
}

impl Engine {
    pub fn new(width: u32, height: u32) -> Engine {
        let mut window = RenderWindow::new(
            (width, height),
            "Window",
            Style::DEFAULT,
            &ContextSettings::default(),
        );
        window.set_framerate_limit(60);
        Engine { window }
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
    }

    pub fn render(&mut self) {
        self.window.clear(Color::BLACK);
        self.window.display();
    }
}
