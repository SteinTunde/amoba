#include "cell.hpp"
#include "mainapp.hpp"

using namespace genv;

Cell::Cell(MainApp* parent,
            int x, int y, int w, int h,
            bool hatter) :
                Widget(parent, x, y, w, h), _parent(parent),_hatter(hatter),
                _state("")
{
    //ctor
}

Cell::~Cell()
{
    //dtor
}

void Cell::draw()
{
    gout << color(200,200,200) << move_to(_x, _y) << box(_w, _h)
        << color(255-30*_hatter,255-30*_hatter,255-30*_hatter) << move_to(_x+2, _y+2) << box(_w-4, _h-4)
        << color(0,0,0) << move_to(_x+5,_y+5) << text(_state);
    if (_parent->GetGameOver())
    {
        gout << color(0, 0, 255) << move_to(200, 10) << text(_parent->GetWinner() + "    ESC to exit");
    }
}

void Cell::handle(event ev)
{
    if (ev.type == ev_mouse && !_parent->GetGameOver())
    {
        if (ev.button == btn_left && _state == "")
        {
            x_setter();
            _parent->StepHappened();
        }
    }
}

void Cell::o_setter()
{
    _state = "o";
}
void Cell:: x_setter()
{
    _state = "x";
}


std::string Cell::Get()
{
    return _state;
}
