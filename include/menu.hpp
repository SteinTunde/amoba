#ifndef MENU_HPP
#define MENU_HPP

#include "widget.hpp"
#include <vector>
#include "graphics.hpp"
#include "app.hpp"

using namespace std;


class Menu : public Widget
{
    public:
        Menu(App* parent, int x, int y, int w, int h, vector<string>, int hany);
        virtual ~Menu();

        void draw() override;
        void handle(genv::event ev) override;
        string Get() override;

    protected:
        vector<string> _elements;
        int how_long(vector<string>);
        int hany;
        int kiv_index = 0;
        int _first_to_print = 0;
    //private:
};

#endif // MENU_HPP
