#include "app.hpp"
#include "widget.hpp"
#include "graphics.hpp"

#include <ctime>

using namespace genv;

App::App(int width, int height) :
    _width(width), _height(height)
{
    gout.open(_width, _height);
    //ctor
}

App::~App()
{
    for (Widget* wg: _widgets){
        delete wg;
    }
}
void App::event_loop()
{
    gout << font("LiberationSans-Regular.ttf",20);
    //gout << text("hello world");
    gout << refresh;
    event ev;

    int kiv_ind = -1;
    while(gin >> ev && ev.keycode != key_escape)
    {
        gout << color(200, 255, 255) << move_to(0,0) << box_to(_width-1, _height-1);
        if (ev.type == ev_mouse && ev.button == btn_left){
            if (kiv_ind != -1){
                _widgets[kiv_ind]->kiv_setter(0);
                kiv_ind = -1;
            }

            for (int i=0; i<_widgets.size(); i++){
                if (_widgets[i]->is_inside(ev.pos_x, ev.pos_y)){
                    kiv_ind = i;
                    break;
                }
            }

        }
        /*else if (ev.type == ev_key && ev.keycode == key_tab){
            if (kiv_ind == wg.size()-1){
                kiv_ind = 0;
            }
            else {kiv_ind++;}
        }*/
        if (kiv_ind != -1){
            _widgets[kiv_ind]->handle(ev);
            _widgets[kiv_ind]->kiv_setter(1);
        }
        for (int i=0; i<_widgets.size(); i++){
            _widgets[i]->draw();
        }
        gout << refresh;


        /*if (ev.type == ev_key && ev.keycode == key_enter){
            ofstream kf("fajl.txt");
            for (int i=0; i<wg.size(); i++){
                kf << wg[i]->Get() << "\n";
            }
        }*/

    }
}
void App::register_w(Widget* w)
{
    _widgets.push_back(w);
}


