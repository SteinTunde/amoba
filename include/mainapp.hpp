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

    protected:
        std::vector<Cell*> _cells;
    private:
};

#endif // MAINAPP_HPP
