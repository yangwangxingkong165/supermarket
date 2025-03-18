# 超市库存及收银管理系统

## 项目介绍

### 系统架构与核心技术

采用MVC模式分层设计，前端基于Qt框架实现用户交互，后端通过MySQL管理数据，模块间解耦，提升可维护性。
实现自动化库存同步：通过MySQL触发器实时更新商品库存，确保数据一致性，减少人工干预。
设计多表关联视图（如商品详情视图），简化复杂查询逻辑，提升数据检索效率。

### 基本功能

实现

### 功能优化与创新

动态权限管理：支持管理员分级权限（如普通员工仅查询，主管可修改），增强系统安全性。
智能预警机制：库存低于阈值时自动触发补货提醒，避免缺货问题，优化库存周转率。（待实现）

### 用户体验改进

设计响应式UI，支持快捷键操作与多条件筛选（如按仓库/商品类型查询库存），提升操作效率。
实现数据导入/导出功能（Excel/CSV），便于与其他系统对接。（待实现）

## 使用方法

### 1.自行在其他软件（如vscode，workbench等）运行sql.sql文件中的mysq语句，并使用ODBC创建数据库连接

#### ODBC连接数据库

链接数据库的方法参考以下教程[QT通过ODBC连接MYSQL并使用（保姆级）](https://blog.csdn.net/qq_72583325/article/details/133967965)

### 2.将项目clone至本地，在qt中打开Qt/untitled.pro 文件

点击“打开文件或项目”，选择Qt/untitled.pro 文件

![](https://github.com/yangwangxingkong165/supermarket/raw/main/Qt/photo/13.png)

### 3.修改main.cpp中的数据库连接部分内容
![](https://github.com/yangwangxingkong165/supermarket/raw/main/Qt/photo/12.png)

### 4.点击Qt构建并运行
若出现“success”的提示则说明连接数据库成功。
若出现“open failed”则说明连接数据库识别，下方控制台会输出错误原因
