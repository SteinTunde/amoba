#ifndef MAINAPP_HPP
#define MAINAPP_HPP

#include "app.hpp"
#include "cell.hpp"

#include <vector>
#include <string>


class MainApp : public App
{
    public:
        MainApp(int, int);
        virtual ~MainApp();
        virtual void Player2();
        virtual void StepHappened();
        virtual bool CheckWin(std::string);
        virtual bool inside(int, int);
        virtual bool GetGameOver();
        virtual std::string GetWinner();

    protected:
        std::vector<Cell*> _cells;
        bool _game_over;
        std::string _winner = "";
    private:
};

#endif // MAINAPP_HPP
