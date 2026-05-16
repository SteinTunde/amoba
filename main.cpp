#include "app.hpp"
#include "widget.hpp"
//#include "szamolo.hpp"
//#include "menu.hpp"
#include "cell.hpp"
#include "mainapp.hpp"

using namespace std;
using namespace genv;


int main()
{
    MainApp app(800, 600);
    app.event_loop();
    return 0;
}
