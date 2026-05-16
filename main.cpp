#include "graphics.hpp"

#include "app.hpp"
#include "widget.hpp"
#include "szamolo.hpp"
#include "menu.hpp"
#include <vector>
#include <fstream>

using namespace std;
using namespace genv;

class MainApp : public App
{
public:
    MainApp(int W, int H) : App(W, H)
    {
        Szamolo*sz1 =new Szamolo(this, 20,30,120,30, 0, 0, 99);
        Szamolo*sz2 =new Szamolo(this, 200,30,120,30, 0, -63, 36);
        //Menu*m1 =new Menu(this, 20,200,100,30, vector<string>{"lakfs", "fhjks", "2hdkjshflksd", "djaklda", "j", "5"}, 4);
        //Menu*m2 =new Menu(this, 20,380,100,30, vector<string>{"jlkfs", "fhjks", "jdlksa"},3);
    }
protected:
    Szamolo *sz1, *sz2;
    //Menu *m1, *m2;
};


int main()
{
    MainApp app(800, 600);
    app.event_loop();
    return 0;
}
