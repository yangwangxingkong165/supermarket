CREATE DATABASE shop
    DEFAULT CHARACTER SET = 'utf8mb4';
USE shop;
CREATE TABLE user -- 用户表
(
    id VARCHAR(15) NOT NULL,
    user_passsword VARCHAR(15) NOT NULL,
    PRIMARY KEY(id)
);
CREATE TABLE goods -- 商品
(
    goods_id INTEGER NOT NULL,
    goods_name VARCHAR(100) NOT NULL,
    class VARCHAR(100) NOT NULL,
    sale_price DOUBLE NOT NULL, -- 销售单价
    amount INTEGER NOT NULL,    
    PRIMARY KEY (goods_id)
);
CREATE TABLE purchase -- 进货
(
    purchase_id INTEGER NOT NULL,
    goods_id INTEGER NOT NULL,
    amount INTEGER NOT NULL,
    providers INTEGER NOT NULL,
    pur_date DATE NOT NULL,
    storehouse INTEGER NOT NULL,
    PRIMARY KEY(purchase_id)
);
CREATE TABLE storehouse -- 仓库
(
    storehouse_id INTEGER NOT NULL,
    storehouse_name VARCHAR(100) NOT NULL,
    address VARCHAR(100) NOT NULL,
    PRIMARY KEY (storehouse_id)
);
CREATE TABLE inventory -- 库存
(
    storehouse_id INTEGER NOT NULL,
    goods_id INTEGER NOT NULL,
    amount INTEGER NOT NULL,
    PRIMARY KEY (storehouse_id,goods_id)
);
CREATE TABLE orders -- 订单
(
    order_id INTEGER NOT NULL,
    order_date DATE NOT NULL,
    customer_id INTEGER NOT NULL,
    cashier_id INTEGER NOT NULL,
    money_amount INTEGER NOT NULL,
    PRIMARY key (order_id)
);
CREATE TABLE order_detail -- 详单
(
    order_id INTEGER NOT NULL,
    goods_id INTEGER NOT NULL,
    amount INTEGER NOT NULL,
    price DOUBLE NOT NULL,
    sum_price DOUBLE NOT NULL,
    PRIMARY key(order_id,goods_id)
);
CREATE VIEW goods_detail
AS
SELECT g.goods_id,g.goods_name,g.class,i.storehouse_id,s.storehouse_name,s.address,i.amount 
FROM goods g 
INNER JOIN inventory i ON g.goods_id = i.goods_id 
INNER JOIN storehouse s ON i.storehouse_id = s.storehouse_id;
CREATE TRIGGER update_goods_amount
AFTER INSERT ON purchase
FOR EACH ROW
BEGIN
    UPDATE goods
    SET amount = amount + NEW.amount
    WHERE goods_id = NEW.goods_id;
END;
CREATE INDEX idx_goods_class ON goods(class);