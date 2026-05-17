#ifndef CELL_HPP
#define CELL_HPP

#include "widget.hpp"
#include <functional>

class MainApp;

class Cell : public Widget
{
    public:
        Cell(MainApp* parent, int x, int y, int w, int h, bool hatter);
        virtual ~Cell();

        virtual void draw() override;
        virtual void handle(genv::event) override;
        virtual std::string Get() override;
        virtual void o_setter();
        virtual void x_setter();

    protected:
        MainApp* _parent;
        bool _hatter;
        std::string _state;
        std::function<void()> _f;
    private:
};

#endif // CELL_HPP
