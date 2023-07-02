#include <iostream>
#include <vector>
#include <queue>
#include "../cell/Cell.hpp"

class Dijkstra{
    private:
        std::queue<Cell> queue;
    public:
        Dijkstra();
    public:
        void findPath(Cell& cell, Cell& endCell, std::vector<std::vector<Cell>>& grid_vector);
};