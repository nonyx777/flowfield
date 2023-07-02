#include "../../../include/dijkstra/Dijkstra.hpp"

//defining constructor
Dijkstra::Dijkstra(){
    //...
}

//defining functions
void Dijkstra::findPath(Cell& cell, Cell& endCell, std::vector<std::vector<Cell>>& grid_vector){
    if((cell.column > 0 && cell.row > 0) && (cell.column < 19 && cell.row < 19)){
        Cell start_cell = cell;
        this->queue.push(cell);
        cell.visited = true;

        while(this->queue.size() != 0){
            cell = this->queue.front();
            if(cell.column == endCell.column && cell.row == endCell.row){
                Cell* currentCell = &cell;
                int p_r = cell.row;
                int p_c = cell.column;
                while(grid_vector[start_cell.row][start_cell.column].type != Cell().PATH){
                    grid_vector[p_r][p_c].type = Cell().PATH;
                    int p_r_r = p_r;
                    p_r = grid_vector[p_r][p_c].parent->row;
                    p_c = grid_vector[p_r_r][p_c].parent->column;
                }
            }

            this->queue.pop();

            for(int i = cell.row-1; i <= cell.row+1; i++){
                for(int j = cell.column-1; j <= cell.column+1; j++){
                    if((i == cell.row+1 && j == cell.column) || (i == cell.row-1 && j == cell.column) || (i == cell.row && j == cell.column+1) || (i == cell.row && j == cell.column-1)){
                        if((j > 0 && i > 0) && (j < 19 && i < 19)){
                            if(grid_vector[i][j].visited == false && grid_vector[i][j].type != Cell().BLOCK){
                                this->queue.push(grid_vector[i][j]);
                                grid_vector[i][j].parent = &grid_vector[cell.row][cell.column];//assigning parent
                                grid_vector[i][j].visited = true;
                            }
                        }
                    }
                }
            }
        }
    }
}