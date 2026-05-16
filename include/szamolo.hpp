#ifndef SZAMOLO_HPP
#define SZAMOLO_HPP

#include "widget.hpp"
#include "graphics.hpp"

class Szamolo : public Widget
{
    public:
        Szamolo(App* parent, int x, int y, int w, int h, int counter, int also_h, int felso_h);
        virtual ~Szamolo();

        void draw_ifkiv(bool) override;
        void handle(genv::event) override;
        std::string Get() override;

    protected:
        int _counter;
        int _also_h;
        int _felso_h;
    private:
};

#endif // SZAMOLO_HPP
