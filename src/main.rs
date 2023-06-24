mod engine;

fn main() {
    let mut engine = engine::Engine::new(800, 600);

    while engine.running() {
        engine.update();
        engine.render();
    }
}
