#include "widget.hpp"
#include "app.hpp"

Widget::Widget(App* parent, int x, int y, int w, int h): _parent(parent), _x(x), _y(y), _w(w), _h(h)
{
    //ctor
    if (_parent)
    {
        _parent->register_w(this);
    }
}

Widget::~Widget()
{
    //dtor
}

bool Widget::is_inside(int m_x, int m_y)
{
    return _x <= m_x && m_x <= _x+_w && _y <= m_y && m_y <= _y+_h;
}
