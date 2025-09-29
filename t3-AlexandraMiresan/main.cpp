#include "gui.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    std::string filename = "weather.txt";
    Controller controller(filename);
    GUI window{controller};
    window.show();
    return app.exec();
}
