#include <app.hpp>
#include <testPage.hpp>

int main(int argc, char *argv[]) {
    auto &app = name_::App::getApp();
    app.createWindow(800, 600)
            .addPage(std::make_unique<name_::TestPage>("test1"));

    app.run();
    return 0;
}