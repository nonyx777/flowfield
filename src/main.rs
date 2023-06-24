mod engine;
mod entities{
    pub mod ball;
    pub mod r#box;
}
mod operations;

fn main() {
    let mut engine = engine::Engine::new(800, 600);

    while engine.running() {
        engine.update();
        engine.render();
    }
}
