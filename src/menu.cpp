#include "menu.hpp"
#include "graphics.hpp"
#include "app.hpp"

using namespace genv;
Menu::Menu(App* parent,
           int x, int y, int w, int h,
           vector<std::string>elements, int mennyi) :
               Widget(parent,x,y,w,h), _elements(elements), hany(mennyi)
{

    //fej tor potroh :)
}
void Menu::draw_ifkiv(bool kiv)
{
    int ch_szin = 0;
    int ch_szeg = 0;
    if (kiv){
        ch_szin = 60;
        ch_szeg = 2;
    }
    if (_w < how_long(_elements)+10){
        _w = how_long(_elements)+10;
    }
    int visible = hany;
    if (_elements.size() < visible || visible <= 0){
        visible = _elements.size();
    }
    gout << color(0,0,0) << move_to(_x-2-ch_szeg, _y-2-ch_szeg) << box(_w+4+ch_szeg*2, _h*hany+4+ch_szeg*2);
    for (int i=0; i<visible; i++){

        int index = i+_first_to_print;
        int ch_szin_forfun = (i % 2)*30;
        if (index == kiv_index){
            gout << color(255,100-ch_szin_forfun,100-ch_szin_forfun) << move_to(_x, _y +_h*i) << box(_w, _h);
            gout << color(255,255,255) << move_to(_x+5, _y+5+_h*i) << text(_elements[index]);
        }
        else {
            gout << color(255-ch_szin-ch_szin_forfun,255-ch_szin_forfun,255-ch_szin_forfun) << move_to(_x, _y +_h*i) << box(_w, _h);
            gout << color(0,0,0) << move_to(_x+5, _y+5+_h*i) << text(_elements[index]);
        }

    }
}


/*bool Menu::is_inside(int mx, int my)
{
    bool inside_one = 0;
    for (int i=0; i<hany; i++){
        if (_x <= mx && mx <= _x+_w && _y+_h*i <= my && my <= _y+_h*(i+1)){
            inside_one = 1;
            kiv_index = i;
        }
    }
    return inside_one;
}*/

void Menu::handle(genv::event ev)
{
    if (ev.type == ev_key){
        if (ev.keycode == key_up){
            if (kiv_index - 1 >= 0){
                kiv_index --;
            }
        }
        else if (ev.keycode == key_down){
            if (kiv_index + 1 < _elements.size()){
                kiv_index ++;
            }
        }
        else if (ev.keycode == key_pgup){
            kiv_index = 0;
        }
        else if (ev.keycode == key_pgdn){
            kiv_index = _elements.size()-1;
        }
    }
    else if (ev.type == ev_mouse){
        if (ev.button == btn_wheelup){
            if (kiv_index - 1 >= 0){
                kiv_index --;
            }
        }
        else if (ev.button == btn_wheeldown){
            if (kiv_index + 1 < _elements.size()){
                kiv_index ++;
            }
        }
    }
    if (hany+_first_to_print <= kiv_index){
        _first_to_print = kiv_index-hany+1;
    }
    else if (kiv_index<_first_to_print){
        _first_to_print = kiv_index;
    }

}

int Menu::how_long(vector<string>_elem)
{
    int longes = 0;
    for (string elem: _elem){
        if (gout.twidth(elem) > longes){
            longes = gout.twidth(elem);
        }
    }
    return longes;
}
string Menu::Get()
{
    return (_elements[kiv_index]);
}

Menu::~Menu()
{
    //dtor
}
