//
// Created by donghao on 25-12-19.
//
#ifndef WINDOW_EVENT_HPP
#define WINDOW_EVENT_HPP
#include <any>
#include <queue>

namespace dao {

    enum class PageCmdType {
        switchPage,
    };

    struct PageCmd {
        PageCmdType type;
        std::any data;
    };

    class PageCmdQueue {
    public:
        PageCmdQueue() = default;

        PageCmdQueue(const PageCmdQueue &) = delete;

        void addSwitchPage(const std::string &title) {
            m_events.push({PageCmdType::switchPage, title});
        }

        [[nodiscard]] bool isPresenceMessage() const {
            return !m_events.empty();
        }

        PageCmd popEvent() {
            auto event = m_events.front();
            m_events.pop();
            return event;
        }

    private:
        std::queue<PageCmd> m_events;
    };
}
#endif //WINDOW_EVENT_HPP
