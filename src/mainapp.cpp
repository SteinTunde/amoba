#include "mainapp.hpp"

#include <vector>
#include <ctime>

MainApp::MainApp(int W, int H) : App(W, H)
{
    for (int i=0; i<225; i++)
    {
        _cells.push_back(new Cell(this, 30 +(i%15)*30, 30 +(i/15)*30, 30, 30, i%2));
    }
}

MainApp::~MainApp()
{
    //dtor
}

void MainApp::Player2()
{
    int ures = 0;
    for (Cell* c: _cells){
        if (c->Get() == ""){
            ures++;
        }
    }
    srand(time(0));
    int o_index = rand()%ures;
    for (int i=0; i<_cells.size(); i++){
        if (_cells[i]->Get() != ""){
            o_index ++;
        }
        else if (i == o_index && _cells[i]->Get() == ""){
            _cells[i]->o_setter();
        }
    }
}
