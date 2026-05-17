#include "mainapp.hpp"

#include <ctime>

int main()
{
    srand(time(0));
    MainApp app(600, 600);
    app.event_loop();
    return 0;
}
