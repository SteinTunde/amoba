#include "app.hpp"
#include "widget.hpp"
//#include "szamolo.hpp"
//#include "menu.hpp"
#include "cell.hpp"
#include "mainapp.hpp"


#include <ctime>

using namespace std;
using namespace genv;


int main()
{
    srand(time(0));
    MainApp app(600, 600);
    app.event_loop();
    return 0;
}
