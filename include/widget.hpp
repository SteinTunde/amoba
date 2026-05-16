#ifndef WIDGET_HPP
#define WIDGET_HPP

#include "app.hpp"
#include "graphics.hpp"

class Widget
{
    public:
        Widget(App* parent, int x, int y, int w, int h);
        virtual ~Widget();

        virtual void draw_ifkiv(bool) = 0;
        virtual bool is_inside(int m_x, int m_y);
        virtual void handle(genv::event ev) = 0;
        virtual std::string Get() = 0;

    protected:
        App *_parent;
        int _x, _y, _w, _h;
};

#endif // WIDGET_HPP
