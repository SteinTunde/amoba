#ifndef APP_HPP
#define APP_HPP

class Widget;
#include <string>
#include <vector>

class App
{
    public:
        App(int, int);
        virtual ~App();
        void event_loop();
        void register_w(Widget*);
    protected:
        int _width, _height;
        std::vector<Widget*> _widgets;

};

#endif // APP_HPP
