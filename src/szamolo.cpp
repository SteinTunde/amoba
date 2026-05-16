#include "szamolo.hpp"

using namespace genv;
using namespace std;

Szamolo::Szamolo(App* parent,
                 int x, int y, int w, int h,
                 int counter, int also_h, int felso_h) :
                     Widget(parent, x, y, w, h), _counter(counter), _also_h(also_h), _felso_h(felso_h)
{
    //ctor
}
void Szamolo::draw()
{
    int ch_szin = 0;
    int ch_szeg = 0;
    if (_kiv){
        ch_szin = 60;
        ch_szeg = 2;
    }
    gout << color(0,0,0) << move_to(_x-2-ch_szeg, _y-2-ch_szeg) << box(_w+4+ch_szeg*2, _h+4+ch_szeg*2) << color(255-ch_szin ,255,255) << move_to(_x, _y) << box(_w, _h);
    gout << color(0,0,0) << move_to(_x+5, _y+_h-10) << text(to_string(_counter));
    gout << color(255,0,0) << move_to(_x+_w-15, _y+10) << line(5, -5) << line(5, 5) << move_to(_x+_w-15, _y+_h-10) << line(5, 5) << line(5, -5);
}



void Szamolo::handle(genv::event ev)
{
    if (ev.type == ev_key){
        if (ev.keycode == key_up){
            if (_counter +1 <= _felso_h){
                _counter ++;
            }
        }
        else if (ev.keycode == key_down){
            if (_counter -1 >= _also_h){
                _counter --;
            }
        }
        else if (ev.keycode == key_pgup){
            if (_counter +10 <= _felso_h){
                _counter += 10;
            }
            else {_counter = _felso_h;}
        }
        else if (ev.keycode == key_pgdn){
            if (_counter -10 >= _also_h){
                _counter -= 10;
            }
            else {_counter = _also_h;}
        }
    }
     else if (ev.type == ev_mouse){
        if (ev.button == btn_wheelup){
            if (_counter +1 <= _felso_h){
                _counter ++;
            }
        }
        else if (ev.button == btn_wheeldown){
            if (_counter -1 >= _also_h){
                _counter --;
            }
        }
    }
}

string Szamolo::Get()
{
    return(to_string(_counter));
}

Szamolo::~Szamolo()
{
    //dtor
}
