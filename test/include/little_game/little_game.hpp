//
// Created by donghao on 25-12-21.
//
#ifndef LITTLE_GAME_HPP
#define LITTLE_GAME_HPP
#include "interface/general_page.hpp"
#include <component/button/simple_button.hpp>
#include "component/button/simple_texture_button_style.hpp"
#include <texture_id.hpp>

class LittleGame {
public:
    LittleGame() = default;

private:
    std::u32string userName{U"访客"};
    int32 userId{-1};
};

class MainPage final : public dao::GeneralPage {
    dao::SimpleButton beginGame;
    dao::SimpleTextureButtonStyle beginGameStyle;
    dao::SimpleButton leaderboard;
    dao::SimpleTextureButtonStyle leaderboardStyle;
    dao::SimpleButton registerUser;
    dao::SimpleTextureButtonStyle registerUserStyle;

public:
    MainPage()
        : GeneralPage("MainPage"),
          beginGame(550, 100, 500, 200, [this]() {
              m_event.addSwitchPage("GamePage");
          }),
          beginGameStyle(beginGame, texture::little_game_begin_game, texture::little_game_begin_game,
                         texture::little_game_begin_game),
          leaderboard(550, 400, 500, 200, [this]() {
              m_event.addSwitchPage("leaderboardPage");
          }),
          leaderboardStyle(leaderboard, texture::little_game_leaderboard, texture::little_game_leaderboard,
                           texture::little_game_leaderboard),
          registerUser(550, 700, 500, 200, [this]() {
              m_event.addSwitchPage("RegisterUserPage");
          }),
          registerUserStyle(registerUser, texture::little_game_register, texture::little_game_register,
                            texture::little_game_register) {
    }

    /// @brief 获取加载图集
    [[nodiscard]] std::vector<uint32> getRegisterTexture() const override {
        return {texture::little_game_begin_game};
    }

    void init() override {
    }

    void close() override {
    }

    void update() override {
        m_vertexBatch.clearDrawBatches();
        beginGameStyle.writeToBatch(m_vertexBatch);
        leaderboardStyle.writeToBatch(m_vertexBatch);
        registerUserStyle.writeToBatch(m_vertexBatch);
    }

    void handleMessage(const SDL_Event &event) override {
        beginGame.handleEvent(event);
        leaderboard.handleEvent(event);
        registerUser.handleEvent(event);
    }

private:
};

struct Kard {
};

class GamePage final : public dao::GeneralPage {
    dao::SimpleButton quit;
    dao::SimpleTextureButtonStyle quitStyle;
    dao::SimpleButton beginGame;
    dao::SimpleTextureButtonStyle beginGameStyle;
    bool isbeginGame{false};
    std::queue<int> c;

public:
    GamePage()
        : GeneralPage("GamePage"),
          quit(20, 20, 100, 40, [this]() { m_event.addSwitchPage("MainPage"); }),
          quitStyle(quit, texture::little_game_quit, texture::little_game_quit, texture::little_game_quit),
          beginGame(550, 400, 200, 100, [this]() {
              beginGame.setStatus(ButtonStatus::Disabled);
              isbeginGame = true;
          }),
          beginGameStyle(beginGame, texture::little_game_begin_game, texture::little_game_begin_game,
                         texture::little_game_begin_game) {
    }

    [[nodiscard]] std::vector<uint32> getRegisterTexture() const override {
        return {};
    }

    void init() override {
    }

    void close() override {
    }

    void update() override {
        m_vertexBatch.clearDrawBatches();
        quitStyle.writeToBatch(m_vertexBatch);
        beginGameStyle.writeToBatch(m_vertexBatch);
        if (isbeginGame) {
        }
    }

    void handleMessage(const SDL_Event &event) override {
        quit.handleEvent(event);
        beginGame.handleEvent(event);
    }

private:
};

class LeaderboardPage final : public dao::GeneralPage {
public:
    LeaderboardPage(): GeneralPage("leaderboardPage") {
    }

    [[nodiscard]] std::vector<uint32> getRegisterTexture() const override {
        return {};
    }

    void init() override {
    }

    void close() override {
    }

    void update() override {
    }

    void handleMessage(const SDL_Event &event) override {
    }

private:
};

class RegisterUserPage final : public dao::GeneralPage {
public:
    RegisterUserPage(): GeneralPage("RegisterUserPage") {
    }

    [[nodiscard]] std::vector<uint32> getRegisterTexture() const override {
        return {};
    }

    void init() override {
    }

    void close() override {
    }

    void update() override {
    }

    void handleMessage(const SDL_Event &event) override {
    }

private:
};

#endif //LITTLE_GAME_HPP
