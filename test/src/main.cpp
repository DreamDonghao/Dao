#include <core/frame/app.hpp>
//
// Created by donghao on 25-11-28.
//
#include <test_page.hpp>

#include "test_page_1.hpp"
#include "little_game/little_game.hpp"

int main(int argc, char *argv[]) {
    /// 创建一个应用
    auto &app = dao::App::getApp();
    /// 创建一个窗口并添加一个页面
    app.createWindow(1600, 1000)
            .addPage(std::make_unique<MainPage>())
            .addPage(std::make_unique<GamePage>())
            .addPage(std::make_unique<LeaderboardPage>())
            .addPage(std::make_unique<RegisterUserPage>());
    /// 启动程序
    app.run();
    return 0;
}
