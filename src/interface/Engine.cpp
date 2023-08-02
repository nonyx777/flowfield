#include "../../include/interface/Engine.h"

//defining initializer functions
void Engine::initVariables(){
    this->window = nullptr;

    //assigning min and max spawning positions
    this->min_x = 100.f;
    this->max_x = 400.f;
    this->min_y = 100.f;
    this->max_y = 400.f;


    auto seed = std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::high_resolution_clock::now().time_since_epoch()).count();

    //instantiating agents
    //randomly palcing them between
        //min_x -> max_x
        //min_y -> max_y
    while(this->agents.size() < 10000){
        float random_x = this->min_x + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX/(this->max_x - this->min_x)));
        float random_y = this->min_y + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX/(this->max_y - this->min_y)));
        Agent agent = Agent();
        agent.agent_property.setPosition(sf::Vector2f(random_x, random_y));
        this->agents.push_back(agent);
    }
}
void Engine::initWindow(){
    this->video_mode.width = 600;
    this->video_mode.height = 600;
    this->window = new sf::RenderWindow(this->video_mode, "FindPath", sf::Style::Titlebar | sf::Style::Resize | sf::Style::Close);
    this->window->setFramerateLimit(60);
    //variables related with the grid
    this->size = this->video_mode.width/30;
    this->column = 30;
    this->row = 30;
    //calling grid layout function
    this->configureGridLayout(this->column, this->row);
}

//defining constructor and destructor
Engine::Engine(){
    this->initVariables();
    this->initWindow();
}
Engine::~Engine(){
    delete this->window;
}

//defining accessors
const bool Engine::running() const{
    return this->window->isOpen();
}

//defining window functions
void Engine::pollEvent(){
    while(this->window->pollEvent(this->event)){
        switch(this->event.type){
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::MouseButtonPressed:
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    this->pointLocation(this->mouse_position_view);
                break;
        }
    }
}
void Engine::update(){
    this->pollEvent();
    this->mouse_position = sf::Mouse::getPosition(*this->window);
    this->mouse_position_view = this->window->mapPixelToCoords(this->mouse_position);

    for(Agent &agent : this->agents){
        agent.update(this->grid_vector, this->size);
    }
}
void Engine::render(){
    this->window->clear(sf::Color::Black);

    // for(int i = 0; i < this->grid_vector.size(); i++){
    //      for(int j = 0; j < this->grid_vector[i].size(); j++){
    //          grid_vector[i][j].render(this->window);
    //      }
    // }

    for(Agent &agent : this->agents){
        agent.render(this->window);
    }

    this->window->display();
}

//defining custom functions
void Engine::configureGridLayout(int column, int row){
    //array of angles
    float angles[] = {0, 90};
    int array_size = sizeof(angles)/sizeof(angles[0]);



    for(int i = 0; i < this->row; i++){
        std::vector<Cell> vec_in;
        //get the current time as a duration since the epoch
        auto current_time = std::chrono::high_resolution_clock::now().time_since_epoch();
        //convert the duration to nanoseconds
        long long seed = std::chrono::duration_cast<std::chrono::nanoseconds>(current_time).count();
        //seed the random number generator with the current time
        std::mt19937 rng(static_cast<unsigned int>(seed));
        for(int j = 0; j < this->column; j++){
            //generate a random index within the array bounds
            std::uniform_int_distribution<int> distribution(0, array_size-1);
            int random_index = distribution(rng);
            //access....
            float angle_value = angles[random_index];

            Cell cell = Cell(sf::Vector2f(this->size, this->size), sf::Vector2f(j * this->size, i * this->size), angle_value);
            cell.column = j;
            cell.row = i;
            vec_in.push_back(cell);
        }
        this->grid_vector.push_back(vec_in);
    }
}
void Engine::pointLocation(sf::Vector2f &mouse_position){
    int mouse_row = floor(mouse_position.y/this->size);
    int mouse_column = floor(mouse_position.x/this->size);

    this->grid_vector[this->selected_cell.y][this->selected_cell.x].cell_property.setFillColor(sf::Color::Transparent);

    this->selected_cell = sf::Vector2u(mouse_column, mouse_row);
    this->grid_vector[this->selected_cell.y][this->selected_cell.x].cell_property.setFillColor(sf::Color::Red);
} 