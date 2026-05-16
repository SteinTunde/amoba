#ifndef CELL_HPP
#define CELL_HPP

#include "widget.hpp"
#include <functional>


class Cell : public Widget
{
    public:
        Cell(App* parent, int x, int y, int w, int h, bool hatter);
        virtual ~Cell();

        virtual void draw() override;
        virtual void handle(genv::event) override;
        virtual std::string Get() override;
        virtual void o_setter();

    protected:
        bool _hatter;
        std::string _state;
        std::function<void()> _f;
    private:
};

#endif // CELL_HPP
