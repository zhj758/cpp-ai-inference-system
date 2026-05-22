## 今日学习总结（2026-05-22）

### 完成内容
1. **环境搭建**：在 VMware 虚拟机中安装 Ubuntu 22.04，配置了 Git、CMake、g++、Docker 和 VS Code，掌握了 Linux 基本命令（pwd、ls、cd、mkdir、rm、cp、mv）。
2. **GitHub 仓库**：初始化本地 Git 仓库，创建 README.md，成功推送到 GitHub 远程仓库 `cpp-ai-inference-system`。
3. **C++ 核心容器**：通过编写 demo 程序，深入理解了 vector（动态数组）、unordered_map（哈希表）、string（字符串操作）的使用场景和常用 API。
4. **项目框架搭建**：按照企业标准搭建了分层项目结构（src/include/models/third_party/build），使用 CMake 管理编译，理解了头文件与源文件分离的意义。
5. **Linux 命令练习**：学习了 find、grep、cat、head、tail 等文本处理和文件搜索命令，创建日志文件进行了实操。
6. **算法练习**：在 LeetCode 上完成了"两数之和"和"有效括号"两道题，分别掌握了 unordered_map 实现 O(n) 查找和 stack 实现括号匹配的思路。

### 关键收获
- 虚拟机比双系统更适合学习阶段，无缝切换提高效率
- 企业项目分层的核心是"接口与实现分离"，便于团队协作和代码复用
- Git 三步走（add → commit → push）是日常开发的标准节奏
- C++ 三大容器是 AI 推理部署代码中的高频工具，必须熟练掌握

### 明日计划
- 学习 OpenCV 基础（图像读取、预处理）
- 了解 ONNX Runtime 推理框架
- 尝试加载一个简单的 ONNX 模型
