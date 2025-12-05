[English](../README.md)

# Dao

这是一个跨平台 C++ GUI 程序通用开发框架，可用于开发 GUI 程序以及游戏等应用。

## 使用

由于该项目处于初级阶段，库文件和框架系统正在完善

### 环境要求

一下是经过测试可构建的版本，其他版本可自行尝试

- C++ 23
- Cmake 3.31
- vcpkg :[sdl3 3.2.26] [sdl3-image 3.2.4(png)] 第三方库具体内容可参考 vcpkg.json 文件 

### 快速上手

您可直接编辑项目中 **main.cpp** 与 **test_page.hpp** 中的内容来快速熟悉如何使用

```C++
/// code/main.cpp
#include <app.hpp>
#include <test_page.hpp>

int main(int argc, char *argv[]) {
    /// 创建一个应用
    auto &app = dao::App::getApp();
    /// 创建一个窗口并添加一个页面
    app.createWindow(800, 600)
            .addPage(std::make_unique<dao::TestPage>("test1"));
	/// 启动程序
    app.run();
    return 0;
}
```

```c++
/// code/test/test_page.hpp
#ifndef TESTPAGE_HPP
#define TESTPAGE_HPP
#include "page.hpp"

namespace dao {
    class TestPage final : public Page {
        /// 纹理图集批处理顶点数组构建器
        AtlasVertexBatchBuilder m_atlasVertexBatchBuilder;
        /// 一个苹果图片
        TextureData appleImg{TextureEnum::food_apple, 0, 0, 100, 100};
        /// 一个香蕉图片
        TextureData bananaImg{TextureEnum::food_banana, 100, 0, 200, 100};
    public:
        explicit TestPage(std::string title): Page(std::move(title)) {
        }
		
        /// 将图片提交出去在创建窗口的时候加载到显存
        [[nodiscard]] std::vector<TextureEnum> registerTexture() const override {
            std::vector registerTexture{
                TextureEnum::food_apple,
                TextureEnum::food_banana,
            };
            return registerTexture;
        }
        /// 窗口每帧的更新逻辑
        void update() override {
            m_atlasVertexBatchBuilder.clearDrawBatches();
            for (int i = 0; i < 30; ++i) {
                for (int j = 0; j < 200; ++j) {
                    m_atlasVertexBatchBuilder.addToBatch(appleImg);
                }
                for (int j = 0; j < 200; ++j) {
                    m_atlasVertexBatchBuilder.addToBatch(bananaImg);
                }
            }
        }
		/// 提交顶点数组绘图
        [[nodiscard]] const std::vector<AtlasDrawBatch> &getDrawBatches() const override {
            return m_atlasVertexBatchBuilder.getDrawBatches();
        }
    };
}

#endif //TESTPAGE_HPP

```

