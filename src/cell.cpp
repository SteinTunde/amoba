#include "cell.hpp"


using namespace genv;

Cell::Cell(App* parent,
            int x, int y, int w, int h,
            bool hatter) :
                Widget(parent, x, y, w, h), _hatter(hatter),
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
}

void Cell::handle(event ev)
{
    if (ev.type == ev_mouse)
    {
        if (ev.button == btn_left && _state == "")
        {
            _state = "x";
            //MainApp::Player2();

        }
    }
}

void Cell::o_setter()
{
    _state = "o";
}


std::string Cell::Get()
{
    return _state;
}
