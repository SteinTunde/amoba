#include "mainapp.hpp"

#include <vector>
using namespace std;

MainApp::MainApp(int W, int H) : App(W, H), _game_over(0), _winner("")
{
    for (int i=0; i<15; i++){
        for (int j=0; j<15; j++){
            _cells.push_back(new Cell(this, 75 +j*30, 60 +i*30, 30, 30, (i+j)%2));
        }
    }
}

MainApp::~MainApp()
{
    //dtor
}
void MainApp::StepHappened()
{
    if (_game_over){
        return;
    }
    if (CheckWin("x")){
        _game_over = 1;
        _winner = "you win! (yey)";
        return;
    }
    Player2();
    if (CheckWin("o")){
        _game_over = 1;
        _winner = "defeat :(";
        return;
    }
    bool dontetlen = 1;
    for (int i=0; i<_cells.size(); i++){
        if (_cells[i]->Get() == ""){
            dontetlen = 0;
            break;
        }
    }
    if (dontetlen){
        _game_over = 1;
        _winner = "nyakkendo (tie)";
        return;
    }

}


void MainApp::Player2()
{
    if (_game_over){
        return;
    }
    vector<int> ures;
    int direction[4][2] = {{0,1}, {1,0}, {1,1}, {1,-1}};
    for (int sor=0; sor<15; sor++){
        for (int oszlop=0; oszlop<15; oszlop++){
            if (_cells[sor*15+oszlop]->Get() != ""){
                for (int d=0; d<4; d++){
                    int teszt_sor = sor + direction[d][0];
                    int teszt_oszlop = oszlop + direction[d][1];

                    if (!inside(teszt_sor, teszt_oszlop)){
                        break;
                    }
                    else {
                        int teszt_index = teszt_sor * 15 + teszt_oszlop;
                        if (_cells[teszt_index]->Get() == ""){
                            ures.push_back(teszt_index);
                        }
                    }
                }
            }
        }
    }
    if (ures.empty()){
        return;
    }
    int o_index = rand()%ures.size();
    _cells[ures[o_index]]->o_setter();
}

bool MainApp::CheckWin(std::string player)
{
    int direction[4][2] = {{0,1}, {1,0}, {1,1}, {1,-1}};

    for (int sor=0; sor < 15; sor++)
    {
        for (int oszlop=0; oszlop < 15; oszlop++)
        {
            int index = sor * 15 + oszlop;

            if (_cells[index]->Get() != player)
                continue;

            for (int d=0; d<4; d++)
            {
                int count = 1;
                for (int step=1; step<5; step++){
                    int teszt_sor = sor + direction[d][0]*step;
                    int teszt_oszlop = oszlop + direction[d][1]*step;

                    if (!inside(teszt_sor, teszt_oszlop)){
                        break;
                    }
                    int teszt_index = teszt_sor * 15 + teszt_oszlop;

                    if (_cells[teszt_index]->Get() == player){
                        count++;
                    }
                    else{
                        break;
                    }
                }
                if (count >= 5){
                    return 1;
                }
            }
        }
    }

    return 0;
}

bool MainApp::inside(int sor, int oszlop)
{
    return sor >= 0 && sor < 15 && oszlop >= 0 && oszlop < 15;
}

bool MainApp::GetGameOver()
{
    return _game_over;
}
std::string MainApp::GetWinner()
{
    return _winner;
}

