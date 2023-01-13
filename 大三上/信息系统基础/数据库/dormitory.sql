/*
MySQL Data Transfer
Source Host: localhost
Source Database: dormitory
Target Host: localhost
Target Database: dormitory
Date: 2020/4/1 13:44:41
*/

SET FOREIGN_KEY_CHECKS=0;
-- ----------------------------
-- Table structure for asset
-- ----------------------------
CREATE TABLE `asset` (
  `assetid` int(10) NOT NULL AUTO_INCREMENT,
  `bedchamberid` int(11) DEFAULT NULL,
  `createtime` date DEFAULT NULL,
  `categoryid` int(11) DEFAULT NULL,
  `repairstatus` int(11) DEFAULT NULL,
  `scraptime` date DEFAULT NULL,
  `scrapto` varchar(128) DEFAULT NULL,
  `scrapreason` varchar(128) DEFAULT NULL,
  `registrationstatus` int(11) DEFAULT NULL,
  `assetname` varchar(30) DEFAULT NULL,
  `uses` varchar(10) DEFAULT NULL,
  `price` float DEFAULT NULL,
  PRIMARY KEY (`assetid`),
  KEY `fk_b` (`bedchamberid`),
  CONSTRAINT `fk_b` FOREIGN KEY (`bedchamberid`) REFERENCES `dormitory` (`dormitoryId`)
) ENGINE=InnoDB AUTO_INCREMENT=12 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for assetcategory
-- ----------------------------
CREATE TABLE `assetcategory` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `cname` varchar(10) NOT NULL,
  `cyear` int(11) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for assetpropertylist
-- ----------------------------
CREATE TABLE `assetpropertylist` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `ctegoryid` int(11) NOT NULL,
  `pname` varchar(10) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=15 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for authority
-- ----------------------------
CREATE TABLE `authority` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `roleId` int(11) NOT NULL,
  `menuId` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `roleId` (`roleId`),
  KEY `menuId` (`menuId`),
  CONSTRAINT `authority_ibfk_1` FOREIGN KEY (`roleId`) REFERENCES `role` (`id`),
  CONSTRAINT `authority_ibfk_2` FOREIGN KEY (`menuId`) REFERENCES `menu` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=1488 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for c3p0testtable
-- ----------------------------
CREATE TABLE `c3p0testtable` (
  `a` char(1) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for dormitory
-- ----------------------------
CREATE TABLE `dormitory` (
  `dormitoryId` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(100) DEFAULT NULL,
  `address` varchar(128) DEFAULT NULL,
  `teacherId` int(11) DEFAULT NULL,
  `url` varchar(128) DEFAULT NULL,
  `icon` varchar(32) DEFAULT NULL,
  PRIMARY KEY (`dormitoryId`)
) ENGINE=InnoDB AUTO_INCREMENT=13 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for log
-- ----------------------------
CREATE TABLE `log` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `content` varchar(255) NOT NULL,
  `createTime` datetime DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=625 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for menu
-- ----------------------------
CREATE TABLE `menu` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `parentId` int(11) NOT NULL DEFAULT '-1',
  `name` varchar(32) NOT NULL,
  `url` varchar(128) DEFAULT NULL,
  `icon` varchar(32) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=88 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for registration
-- ----------------------------
CREATE TABLE `registration` (
  `teaid` varchar(10) NOT NULL,
  `assetid` int(11) NOT NULL,
  `rstatus` int(11) DEFAULT NULL,
  `rcreatetime` date DEFAULT NULL,
  `rid` int(11) NOT NULL AUTO_INCREMENT,
  PRIMARY KEY (`rid`)
) ENGINE=InnoDB AUTO_INCREMENT=14 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for repairs
-- ----------------------------
CREATE TABLE `repairs` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `stuid` varchar(10) DEFAULT NULL,
  `assetid` int(11) DEFAULT NULL,
  `createtime` date DEFAULT NULL,
  `status` int(11) DEFAULT NULL,
  `brank` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for role
-- ----------------------------
CREATE TABLE `role` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(32) NOT NULL,
  `remark` varchar(128) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for student
-- ----------------------------
CREATE TABLE `student` (
  `username` varchar(40) NOT NULL,
  `id` varchar(40) NOT NULL,
  `class` varchar(255) DEFAULT NULL,
  `year` date DEFAULT NULL,
  `password` varchar(32) DEFAULT NULL,
  `sex` int(11) DEFAULT NULL,
  `age` int(11) DEFAULT NULL,
  `roleId` int(11) DEFAULT NULL,
  `photo` varchar(128) DEFAULT NULL,
  `dormitory_id` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for teacher
-- ----------------------------
CREATE TABLE `teacher` (
  `id` varchar(32) CHARACTER SET utf8mb4 NOT NULL,
  `username` varchar(100) NOT NULL,
  `password` varchar(32) DEFAULT NULL,
  `sex` int(1) DEFAULT NULL,
  `age` int(3) DEFAULT NULL,
  `address` varchar(128) DEFAULT NULL,
  `roleId` int(11) DEFAULT NULL,
  `photo` varchar(128) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for user
-- ----------------------------
CREATE TABLE `user` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `username` varchar(32) NOT NULL,
  `password` varchar(32) NOT NULL,
  `roleId` int(11) NOT NULL,
  `photo` varchar(128) DEFAULT NULL,
  `sex` int(1) NOT NULL DEFAULT '0',
  `age` int(3) NOT NULL DEFAULT '0',
  `address` varchar(128) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `roleId` (`roleId`),
  CONSTRAINT `user_ibfk_1` FOREIGN KEY (`roleId`) REFERENCES `role` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records 
-- ----------------------------
INSERT INTO `asset` VALUES ('3', '11', '2019-12-21', null, null, '2019-12-22', '回收', '年限已到', '-1', '风扇', '192300423', '1');
INSERT INTO `asset` VALUES ('8', '1', '2019-12-24', '3', '1', null, null, null, '1', '桌子', '192300424', '123');
INSERT INTO `asset` VALUES ('9', '10', '2019-12-22', '3', '1', null, null, null, '1', '椅子', '192300422', '13');
INSERT INTO `asset` VALUES ('11', '10', '2019-12-22', '3', null, null, null, null, '1', '桌子', '192300422', '12999');
INSERT INTO `assetcategory` VALUES ('3', '日常设施', '10');
INSERT INTO `assetcategory` VALUES ('6', '电器设施', '8');
INSERT INTO `assetpropertylist` VALUES ('7', '3', '桌子');
INSERT INTO `assetpropertylist` VALUES ('8', '3', '椅子');
INSERT INTO `assetpropertylist` VALUES ('9', '6', '电风扇');
INSERT INTO `assetpropertylist` VALUES ('10', '6', '空凋');
INSERT INTO `assetpropertylist` VALUES ('11', '6', '灯泡');
INSERT INTO `assetpropertylist` VALUES ('12', '6', '开关');
INSERT INTO `assetpropertylist` VALUES ('13', '3', '扫把');
INSERT INTO `assetpropertylist` VALUES ('14', '3', '垃圾桶');
INSERT INTO `authority` VALUES ('1050', '2', '38');
INSERT INTO `authority` VALUES ('1051', '2', '50');
INSERT INTO `authority` VALUES ('1052', '2', '51');
INSERT INTO `authority` VALUES ('1053', '2', '52');
INSERT INTO `authority` VALUES ('1054', '2', '53');
INSERT INTO `authority` VALUES ('1055', '2', '39');
INSERT INTO `authority` VALUES ('1056', '2', '46');
INSERT INTO `authority` VALUES ('1057', '2', '47');
INSERT INTO `authority` VALUES ('1058', '2', '48');
INSERT INTO `authority` VALUES ('1059', '2', '49');
INSERT INTO `authority` VALUES ('1060', '2', '44');
INSERT INTO `authority` VALUES ('1061', '2', '74');
INSERT INTO `authority` VALUES ('1062', '2', '75');
INSERT INTO `authority` VALUES ('1063', '2', '76');
INSERT INTO `authority` VALUES ('1064', '2', '77');
INSERT INTO `authority` VALUES ('1065', '2', '78');
INSERT INTO `authority` VALUES ('1066', '2', '40');
INSERT INTO `authority` VALUES ('1067', '2', '41');
INSERT INTO `authority` VALUES ('1068', '4', '79');
INSERT INTO `authority` VALUES ('1069', '4', '42');
INSERT INTO `authority` VALUES ('1070', '4', '43');
INSERT INTO `authority` VALUES ('1071', '4', '38');
INSERT INTO `authority` VALUES ('1072', '4', '50');
INSERT INTO `authority` VALUES ('1073', '4', '40');
INSERT INTO `authority` VALUES ('1074', '4', '41');
INSERT INTO `authority` VALUES ('1426', '1', '1');
INSERT INTO `authority` VALUES ('1427', '1', '5');
INSERT INTO `authority` VALUES ('1428', '1', '17');
INSERT INTO `authority` VALUES ('1429', '1', '18');
INSERT INTO `authority` VALUES ('1430', '1', '19');
INSERT INTO `authority` VALUES ('1431', '1', '20');
INSERT INTO `authority` VALUES ('1432', '1', '13');
INSERT INTO `authority` VALUES ('1433', '1', '21');
INSERT INTO `authority` VALUES ('1434', '1', '22');
INSERT INTO `authority` VALUES ('1435', '1', '23');
INSERT INTO `authority` VALUES ('1436', '1', '35');
INSERT INTO `authority` VALUES ('1437', '1', '36');
INSERT INTO `authority` VALUES ('1438', '1', '14');
INSERT INTO `authority` VALUES ('1439', '1', '15');
INSERT INTO `authority` VALUES ('1440', '1', '24');
INSERT INTO `authority` VALUES ('1441', '1', '25');
INSERT INTO `authority` VALUES ('1442', '1', '26');
INSERT INTO `authority` VALUES ('1443', '1', '65');
INSERT INTO `authority` VALUES ('1444', '1', '66');
INSERT INTO `authority` VALUES ('1445', '1', '67');
INSERT INTO `authority` VALUES ('1446', '1', '68');
INSERT INTO `authority` VALUES ('1447', '1', '69');
INSERT INTO `authority` VALUES ('1448', '1', '70');
INSERT INTO `authority` VALUES ('1449', '1', '71');
INSERT INTO `authority` VALUES ('1450', '1', '72');
INSERT INTO `authority` VALUES ('1451', '1', '31');
INSERT INTO `authority` VALUES ('1452', '1', '32');
INSERT INTO `authority` VALUES ('1453', '1', '33');
INSERT INTO `authority` VALUES ('1454', '1', '34');
INSERT INTO `authority` VALUES ('1455', '1', '37');
INSERT INTO `authority` VALUES ('1456', '1', '61');
INSERT INTO `authority` VALUES ('1457', '1', '62');
INSERT INTO `authority` VALUES ('1458', '1', '63');
INSERT INTO `authority` VALUES ('1459', '1', '64');
INSERT INTO `authority` VALUES ('1460', '1', '51');
INSERT INTO `authority` VALUES ('1461', '1', '52');
INSERT INTO `authority` VALUES ('1462', '1', '53');
INSERT INTO `authority` VALUES ('1463', '1', '80');
INSERT INTO `authority` VALUES ('1464', '1', '81');
INSERT INTO `authority` VALUES ('1465', '1', '82');
INSERT INTO `authority` VALUES ('1466', '1', '83');
INSERT INTO `authority` VALUES ('1467', '1', '84');
INSERT INTO `authority` VALUES ('1468', '1', '85');
INSERT INTO `authority` VALUES ('1469', '1', '86');
INSERT INTO `authority` VALUES ('1470', '1', '87');
INSERT INTO `authority` VALUES ('1471', '1', '39');
INSERT INTO `authority` VALUES ('1472', '1', '46');
INSERT INTO `authority` VALUES ('1473', '1', '47');
INSERT INTO `authority` VALUES ('1474', '1', '48');
INSERT INTO `authority` VALUES ('1475', '1', '49');
INSERT INTO `authority` VALUES ('1476', '1', '40');
INSERT INTO `authority` VALUES ('1477', '1', '41');
INSERT INTO `authority` VALUES ('1478', '1', '42');
INSERT INTO `authority` VALUES ('1479', '1', '43');
INSERT INTO `authority` VALUES ('1480', '1', '44');
INSERT INTO `authority` VALUES ('1481', '1', '74');
INSERT INTO `authority` VALUES ('1482', '1', '75');
INSERT INTO `authority` VALUES ('1483', '1', '76');
INSERT INTO `authority` VALUES ('1484', '1', '77');
INSERT INTO `authority` VALUES ('1485', '1', '78');
INSERT INTO `authority` VALUES ('1486', '1', '38');
INSERT INTO `authority` VALUES ('1487', '1', '50');
INSERT INTO `dormitory` VALUES ('1', '西二', 'aa', '1903', '123', '123');
INSERT INTO `dormitory` VALUES ('10', '西三', null, '1902', null, null);
INSERT INTO `dormitory` VALUES ('11', '西四', null, '1904', null, null);
INSERT INTO `dormitory` VALUES ('12', '西五', null, '1903', null, null);
INSERT INTO `log` VALUES ('51', '用户名为{1901}，角色为{老师用户}的用户登录成功!', '2019-12-18 11:21:49');
INSERT INTO `log` VALUES ('76', '用户名为{hyh}，角色为{管理员}的用户登录成功!', '2019-12-18 17:43:49');
INSERT INTO `log` VALUES ('104', '用户名为123的用户登录时输入验证码错误!', '2019-12-18 20:44:57');
INSERT INTO `log` VALUES ('105', '用户名为{123}，角色为{老师用户}的用户登录成功!', '2019-12-18 20:45:08');
INSERT INTO `log` VALUES ('106', '用户名为{123}，角色为{老师用户}的用户登录成功!', '2019-12-18 20:50:41');
INSERT INTO `log` VALUES ('107', '用户名为{123}，角色为{老师用户}的用户登录成功!', '2019-12-18 20:58:46');
INSERT INTO `log` VALUES ('113', '用户名为{123}，角色为{老师用户}的用户登录成功!', '2019-12-18 21:29:35');
INSERT INTO `log` VALUES ('115', '用户名为{123}，角色为{老师用户}的用户登录成功!', '2019-12-18 21:40:42');
INSERT INTO `log` VALUES ('116', '用户名为{123}，角色为{老师用户}的用户登录成功!', '2019-12-18 21:41:59');
INSERT INTO `log` VALUES ('126', '用户名为{123}，角色为{老师用户}的用户登录成功!', '2019-12-18 22:38:30');
INSERT INTO `log` VALUES ('129', '用户名为{黄永}，角色为{学生用户}的用户登录成功!', '2019-12-18 22:39:48');
INSERT INTO `log` VALUES ('131', '管理员登录时，用户名为黄永的用户不存在!', '2019-12-18 22:41:57');
INSERT INTO `log` VALUES ('132', '用户名为{黄永}，角色为{学生用户}的用户登录成功!', '2019-12-18 22:42:12');
INSERT INTO `log` VALUES ('136', '用户名为admin的用户登录时输入验证码错误!', '2019-12-19 08:16:53');
INSERT INTO `log` VALUES ('137', '用户名为admin的用户登录时输入验证码错误!', '2019-12-19 08:17:02');
INSERT INTO `log` VALUES ('138', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-19 08:17:08');
INSERT INTO `log` VALUES ('139', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-19 08:21:35');
INSERT INTO `log` VALUES ('140', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-19 08:32:48');
INSERT INTO `log` VALUES ('141', '用户名为{192300423}，角色为{学生用户}的用户登录成功!', '2019-12-19 08:36:42');
INSERT INTO `log` VALUES ('142', '用户名为admin的用户登录时输入验证码错误!', '2019-12-19 08:37:03');
INSERT INTO `log` VALUES ('143', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-19 08:37:08');
INSERT INTO `log` VALUES ('144', '用户名为{192300423}，角色为{学生用户}的用户登录成功!', '2019-12-19 08:39:34');
INSERT INTO `log` VALUES ('145', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-19 08:39:49');
INSERT INTO `log` VALUES ('146', '用户名为admin的用户登录时输入验证码错误!', '2019-12-19 08:41:29');
INSERT INTO `log` VALUES ('147', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-19 08:41:37');
INSERT INTO `log` VALUES ('148', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-19 08:43:30');
INSERT INTO `log` VALUES ('149', '用户名为{192300423}，角色为{学生用户}的用户登录成功!', '2019-12-19 09:04:14');
INSERT INTO `log` VALUES ('150', '用户名为admin的用户登录时输入验证码错误!', '2019-12-19 09:04:31');
INSERT INTO `log` VALUES ('151', '用户名为admin的用户登录时输入验证码错误!', '2019-12-19 09:04:37');
INSERT INTO `log` VALUES ('152', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-19 09:04:45');
INSERT INTO `log` VALUES ('153', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-19 10:10:14');
INSERT INTO `log` VALUES ('154', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-19 10:38:56');
INSERT INTO `log` VALUES ('155', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-19 11:00:53');
INSERT INTO `log` VALUES ('156', '用户名为{123}，角色为{老师用户}的用户登录成功!', '2019-12-19 11:01:21');
INSERT INTO `log` VALUES ('157', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-19 11:01:47');
INSERT INTO `log` VALUES ('158', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-19 11:05:44');
INSERT INTO `log` VALUES ('159', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-19 11:21:15');
INSERT INTO `log` VALUES ('160', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-19 11:23:20');
INSERT INTO `log` VALUES ('161', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-19 11:26:00');
INSERT INTO `log` VALUES ('162', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-19 12:45:16');
INSERT INTO `log` VALUES ('163', '用户名为admin的用户登录时输入验证码错误!', '2019-12-19 13:14:51');
INSERT INTO `log` VALUES ('164', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-19 13:15:02');
INSERT INTO `log` VALUES ('165', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-19 13:18:13');
INSERT INTO `log` VALUES ('166', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-19 14:00:04');
INSERT INTO `log` VALUES ('167', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-19 14:03:19');
INSERT INTO `log` VALUES ('168', '用户名为admin的用户登录时输入验证码错误!', '2019-12-19 14:10:44');
INSERT INTO `log` VALUES ('169', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-19 14:10:55');
INSERT INTO `log` VALUES ('170', '用户名为admin的用户登录时输入验证码错误!', '2019-12-19 14:14:11');
INSERT INTO `log` VALUES ('171', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-19 14:14:19');
INSERT INTO `log` VALUES ('172', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-19 14:17:54');
INSERT INTO `log` VALUES ('173', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-19 14:22:29');
INSERT INTO `log` VALUES ('174', '用户名为admin的用户登录时输入验证码错误!', '2019-12-19 14:26:12');
INSERT INTO `log` VALUES ('175', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-19 14:26:21');
INSERT INTO `log` VALUES ('176', '用户名为admin的用户登录时输入验证码错误!', '2019-12-19 15:03:42');
INSERT INTO `log` VALUES ('177', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-19 15:03:52');
INSERT INTO `log` VALUES ('178', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-19 15:09:25');
INSERT INTO `log` VALUES ('179', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-19 15:15:01');
INSERT INTO `log` VALUES ('180', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-19 15:16:40');
INSERT INTO `log` VALUES ('181', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-19 15:20:51');
INSERT INTO `log` VALUES ('182', '用户名为admin的用户登录时输入验证码错误!', '2019-12-19 15:48:03');
INSERT INTO `log` VALUES ('183', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-19 15:48:12');
INSERT INTO `log` VALUES ('184', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-19 17:10:08');
INSERT INTO `log` VALUES ('185', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-19 18:11:23');
INSERT INTO `log` VALUES ('186', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-19 18:24:33');
INSERT INTO `log` VALUES ('187', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-19 18:27:45');
INSERT INTO `log` VALUES ('188', '用户名为admin的用户登录时输入验证码错误!', '2019-12-19 18:30:52');
INSERT INTO `log` VALUES ('189', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-19 18:31:04');
INSERT INTO `log` VALUES ('190', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-19 18:46:49');
INSERT INTO `log` VALUES ('191', '用户名为admin的用户登录时输入验证码错误!', '2019-12-19 18:51:49');
INSERT INTO `log` VALUES ('192', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-19 18:52:02');
INSERT INTO `log` VALUES ('193', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-19 18:58:53');
INSERT INTO `log` VALUES ('194', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-19 19:05:49');
INSERT INTO `log` VALUES ('195', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-19 19:07:12');
INSERT INTO `log` VALUES ('196', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-19 19:08:34');
INSERT INTO `log` VALUES ('197', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-19 19:13:34');
INSERT INTO `log` VALUES ('198', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-19 19:15:59');
INSERT INTO `log` VALUES ('199', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-19 19:18:53');
INSERT INTO `log` VALUES ('200', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-19 19:36:37');
INSERT INTO `log` VALUES ('201', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-19 19:38:39');
INSERT INTO `log` VALUES ('202', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-19 19:40:06');
INSERT INTO `log` VALUES ('203', '用户名为admin的用户登录时输入验证码错误!', '2019-12-19 19:43:59');
INSERT INTO `log` VALUES ('204', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-19 19:44:16');
INSERT INTO `log` VALUES ('205', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-19 19:50:19');
INSERT INTO `log` VALUES ('206', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-19 19:58:34');
INSERT INTO `log` VALUES ('207', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-19 20:11:53');
INSERT INTO `log` VALUES ('208', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-19 20:13:12');
INSERT INTO `log` VALUES ('209', '用户名为admin的用户登录时输入验证码错误!', '2019-12-19 21:03:50');
INSERT INTO `log` VALUES ('210', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-19 21:04:05');
INSERT INTO `log` VALUES ('211', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-19 22:17:14');
INSERT INTO `log` VALUES ('212', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 00:00:29');
INSERT INTO `log` VALUES ('213', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 00:34:10');
INSERT INTO `log` VALUES ('214', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 00:37:59');
INSERT INTO `log` VALUES ('215', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 08:48:01');
INSERT INTO `log` VALUES ('216', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 08:51:07');
INSERT INTO `log` VALUES ('217', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 09:10:20');
INSERT INTO `log` VALUES ('218', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 09:12:15');
INSERT INTO `log` VALUES ('219', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 09:14:53');
INSERT INTO `log` VALUES ('220', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 09:28:51');
INSERT INTO `log` VALUES ('221', '用户名为admin的用户登录时输入验证码错误!', '2019-12-20 09:32:22');
INSERT INTO `log` VALUES ('222', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 09:32:30');
INSERT INTO `log` VALUES ('223', '用户名为admin的用户登录时输入验证码错误!', '2019-12-20 09:38:16');
INSERT INTO `log` VALUES ('224', '用户名为admin的用户登录时输入验证码错误!', '2019-12-20 09:38:25');
INSERT INTO `log` VALUES ('225', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 09:38:32');
INSERT INTO `log` VALUES ('226', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 09:40:39');
INSERT INTO `log` VALUES ('227', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 10:44:33');
INSERT INTO `log` VALUES ('228', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 10:58:01');
INSERT INTO `log` VALUES ('229', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 11:33:06');
INSERT INTO `log` VALUES ('230', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 11:42:34');
INSERT INTO `log` VALUES ('231', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 11:43:33');
INSERT INTO `log` VALUES ('232', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 14:38:45');
INSERT INTO `log` VALUES ('233', '用户名为admin的用户登录时输入验证码错误!', '2019-12-20 15:07:38');
INSERT INTO `log` VALUES ('234', '用户名为admin的用户登录时输入验证码错误!', '2019-12-20 15:07:47');
INSERT INTO `log` VALUES ('235', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 15:07:54');
INSERT INTO `log` VALUES ('236', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 15:08:52');
INSERT INTO `log` VALUES ('237', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 15:24:51');
INSERT INTO `log` VALUES ('238', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 15:26:27');
INSERT INTO `log` VALUES ('239', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 15:28:25');
INSERT INTO `log` VALUES ('240', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 15:32:50');
INSERT INTO `log` VALUES ('241', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 15:35:00');
INSERT INTO `log` VALUES ('242', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 15:42:13');
INSERT INTO `log` VALUES ('243', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 15:43:10');
INSERT INTO `log` VALUES ('244', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 16:04:00');
INSERT INTO `log` VALUES ('245', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 16:12:58');
INSERT INTO `log` VALUES ('246', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 16:31:32');
INSERT INTO `log` VALUES ('247', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 16:35:40');
INSERT INTO `log` VALUES ('248', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 16:45:18');
INSERT INTO `log` VALUES ('249', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 16:57:59');
INSERT INTO `log` VALUES ('250', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 17:05:46');
INSERT INTO `log` VALUES ('251', '用户名为admin的用户登录时输入验证码错误!', '2019-12-20 17:11:06');
INSERT INTO `log` VALUES ('252', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 17:11:15');
INSERT INTO `log` VALUES ('253', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 17:38:36');
INSERT INTO `log` VALUES ('254', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 17:41:52');
INSERT INTO `log` VALUES ('255', '用户名为admin的用户登录时输入验证码错误!', '2019-12-20 17:45:41');
INSERT INTO `log` VALUES ('256', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 17:45:52');
INSERT INTO `log` VALUES ('257', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 17:59:34');
INSERT INTO `log` VALUES ('258', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 18:03:29');
INSERT INTO `log` VALUES ('259', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 18:12:09');
INSERT INTO `log` VALUES ('260', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 18:14:05');
INSERT INTO `log` VALUES ('261', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 18:20:59');
INSERT INTO `log` VALUES ('262', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 18:30:13');
INSERT INTO `log` VALUES ('263', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 18:32:07');
INSERT INTO `log` VALUES ('264', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 18:46:20');
INSERT INTO `log` VALUES ('265', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 19:24:52');
INSERT INTO `log` VALUES ('266', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 19:33:36');
INSERT INTO `log` VALUES ('267', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 19:37:32');
INSERT INTO `log` VALUES ('268', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 19:46:41');
INSERT INTO `log` VALUES ('269', '用户名为admin的用户登录时输入验证码错误!', '2019-12-20 19:52:31');
INSERT INTO `log` VALUES ('270', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 19:52:38');
INSERT INTO `log` VALUES ('271', '用户名为admin的用户登录时输入验证码错误!', '2019-12-20 20:03:55');
INSERT INTO `log` VALUES ('272', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 20:04:03');
INSERT INTO `log` VALUES ('273', '用户名为{1902}，角色为{老师用户}的用户登录成功!', '2019-12-20 20:05:04');
INSERT INTO `log` VALUES ('274', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 20:14:22');
INSERT INTO `log` VALUES ('275', '用户名为{192300423}，角色为{学生用户}的用户登录成功!', '2019-12-20 20:14:52');
INSERT INTO `log` VALUES ('276', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 20:15:43');
INSERT INTO `log` VALUES ('277', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 20:25:13');
INSERT INTO `log` VALUES ('278', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 21:43:10');
INSERT INTO `log` VALUES ('279', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 21:48:33');
INSERT INTO `log` VALUES ('280', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 22:09:57');
INSERT INTO `log` VALUES ('281', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 22:11:59');
INSERT INTO `log` VALUES ('282', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 22:13:53');
INSERT INTO `log` VALUES ('283', '用户名为admin的用户登录时输入验证码错误!', '2019-12-20 22:15:12');
INSERT INTO `log` VALUES ('284', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 22:15:46');
INSERT INTO `log` VALUES ('285', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 22:18:34');
INSERT INTO `log` VALUES ('286', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 22:37:51');
INSERT INTO `log` VALUES ('287', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 22:44:08');
INSERT INTO `log` VALUES ('288', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 22:51:07');
INSERT INTO `log` VALUES ('289', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 23:05:55');
INSERT INTO `log` VALUES ('290', '用户名为admin的用户登录时输入验证码错误!', '2019-12-20 23:13:41');
INSERT INTO `log` VALUES ('291', '用户名为admin的用户登录时输入验证码错误!', '2019-12-20 23:13:49');
INSERT INTO `log` VALUES ('292', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 23:13:54');
INSERT INTO `log` VALUES ('293', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 23:28:07');
INSERT INTO `log` VALUES ('294', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 23:34:43');
INSERT INTO `log` VALUES ('295', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-20 23:52:08');
INSERT INTO `log` VALUES ('296', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 00:01:51');
INSERT INTO `log` VALUES ('297', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 00:03:45');
INSERT INTO `log` VALUES ('298', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 00:05:19');
INSERT INTO `log` VALUES ('299', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 00:09:49');
INSERT INTO `log` VALUES ('300', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 00:13:01');
INSERT INTO `log` VALUES ('301', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 00:14:58');
INSERT INTO `log` VALUES ('302', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 00:40:15');
INSERT INTO `log` VALUES ('303', '用户名为admin的用户登录时输入验证码错误!', '2019-12-21 00:44:26');
INSERT INTO `log` VALUES ('304', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 00:44:41');
INSERT INTO `log` VALUES ('305', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 00:55:33');
INSERT INTO `log` VALUES ('306', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 01:01:35');
INSERT INTO `log` VALUES ('307', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 01:07:43');
INSERT INTO `log` VALUES ('308', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 01:13:55');
INSERT INTO `log` VALUES ('309', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 01:17:24');
INSERT INTO `log` VALUES ('310', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 08:07:25');
INSERT INTO `log` VALUES ('311', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 08:11:00');
INSERT INTO `log` VALUES ('312', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 08:22:02');
INSERT INTO `log` VALUES ('313', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 08:26:42');
INSERT INTO `log` VALUES ('314', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 08:28:25');
INSERT INTO `log` VALUES ('315', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 08:59:07');
INSERT INTO `log` VALUES ('316', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 09:17:59');
INSERT INTO `log` VALUES ('317', '用户名为admin的用户登录时输入验证码错误!', '2019-12-21 12:22:00');
INSERT INTO `log` VALUES ('318', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 12:22:05');
INSERT INTO `log` VALUES ('319', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 13:00:10');
INSERT INTO `log` VALUES ('320', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 13:59:15');
INSERT INTO `log` VALUES ('321', '用户名为admin的用户登录时输入验证码错误!', '2019-12-21 14:06:40');
INSERT INTO `log` VALUES ('322', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 14:06:49');
INSERT INTO `log` VALUES ('323', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 14:08:58');
INSERT INTO `log` VALUES ('324', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 14:10:24');
INSERT INTO `log` VALUES ('325', '用户名为admin的用户登录时输入验证码错误!', '2019-12-21 14:11:43');
INSERT INTO `log` VALUES ('326', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 14:11:56');
INSERT INTO `log` VALUES ('327', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 14:14:05');
INSERT INTO `log` VALUES ('328', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 14:29:33');
INSERT INTO `log` VALUES ('329', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 14:42:25');
INSERT INTO `log` VALUES ('330', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 15:15:24');
INSERT INTO `log` VALUES ('331', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 15:17:04');
INSERT INTO `log` VALUES ('332', '用户名为admin的用户登录时输入验证码错误!', '2019-12-21 15:23:22');
INSERT INTO `log` VALUES ('333', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 15:23:37');
INSERT INTO `log` VALUES ('334', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 15:25:47');
INSERT INTO `log` VALUES ('335', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 15:28:44');
INSERT INTO `log` VALUES ('336', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 15:35:29');
INSERT INTO `log` VALUES ('337', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 15:49:48');
INSERT INTO `log` VALUES ('338', '用户名为{1903}，角色为{老师用户}的用户登录成功!', '2019-12-21 15:51:16');
INSERT INTO `log` VALUES ('339', '用户名为{1903}，角色为{老师用户}的用户登录成功!', '2019-12-21 15:53:33');
INSERT INTO `log` VALUES ('340', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 15:55:16');
INSERT INTO `log` VALUES ('341', '用户名为1903的用户登录时输入验证码错误!', '2019-12-21 15:55:50');
INSERT INTO `log` VALUES ('342', '用户名为{1903}，角色为{老师用户}的用户登录成功!', '2019-12-21 15:55:56');
INSERT INTO `log` VALUES ('343', '用户名为admin的用户登录时输入验证码错误!', '2019-12-21 15:58:00');
INSERT INTO `log` VALUES ('344', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 15:58:06');
INSERT INTO `log` VALUES ('345', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 16:18:45');
INSERT INTO `log` VALUES ('346', '老师登录时，用户名为admin的用户不存在!', '2019-12-21 16:19:19');
INSERT INTO `log` VALUES ('347', '用户名为{1903}，角色为{老师用户}的用户登录成功!', '2019-12-21 16:19:31');
INSERT INTO `log` VALUES ('348', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 16:21:26');
INSERT INTO `log` VALUES ('349', '用户名为1903的用户登录时输入验证码错误!', '2019-12-21 16:23:03');
INSERT INTO `log` VALUES ('350', '用户名为1903的用户登录时输入验证码错误!', '2019-12-21 16:23:09');
INSERT INTO `log` VALUES ('351', '老师登录时,职工号为1903的用户登录时输入密码错误!', '2019-12-21 16:23:14');
INSERT INTO `log` VALUES ('352', '用户名为1903的用户登录时输入验证码错误!', '2019-12-21 16:23:21');
INSERT INTO `log` VALUES ('353', '用户名为{1903}，角色为{老师用户}的用户登录成功!', '2019-12-21 16:23:27');
INSERT INTO `log` VALUES ('354', '用户名为{1903}，角色为{老师用户}的用户登录成功!', '2019-12-21 16:27:16');
INSERT INTO `log` VALUES ('355', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 17:02:08');
INSERT INTO `log` VALUES ('356', '用户名为admin的用户登录时输入验证码错误!', '2019-12-21 17:54:40');
INSERT INTO `log` VALUES ('357', '用户名为admin的用户登录时输入验证码错误!', '2019-12-21 17:54:52');
INSERT INTO `log` VALUES ('358', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 17:55:00');
INSERT INTO `log` VALUES ('359', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 18:01:09');
INSERT INTO `log` VALUES ('360', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 18:05:36');
INSERT INTO `log` VALUES ('361', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 18:08:51');
INSERT INTO `log` VALUES ('362', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 18:12:36');
INSERT INTO `log` VALUES ('363', '用户名为admin的用户登录时输入验证码错误!', '2019-12-21 18:17:59');
INSERT INTO `log` VALUES ('364', '用户名为admin的用户登录时输入验证码错误!', '2019-12-21 18:18:09');
INSERT INTO `log` VALUES ('365', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 18:18:18');
INSERT INTO `log` VALUES ('366', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 18:19:55');
INSERT INTO `log` VALUES ('367', '用户名为{1902}，角色为{老师用户}的用户登录成功!', '2019-12-21 18:20:25');
INSERT INTO `log` VALUES ('368', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 18:21:34');
INSERT INTO `log` VALUES ('369', '用户名为192300423的用户登录时输入验证码错误!', '2019-12-21 18:23:48');
INSERT INTO `log` VALUES ('370', '用户名为{192300423}，角色为{学生用户}的用户登录成功!', '2019-12-21 18:23:59');
INSERT INTO `log` VALUES ('371', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 18:24:20');
INSERT INTO `log` VALUES ('372', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 19:01:52');
INSERT INTO `log` VALUES ('373', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 19:11:12');
INSERT INTO `log` VALUES ('374', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 19:15:31');
INSERT INTO `log` VALUES ('375', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 19:18:24');
INSERT INTO `log` VALUES ('376', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 19:25:31');
INSERT INTO `log` VALUES ('377', '用户名为1902的用户登录时输入验证码错误!', '2019-12-21 19:28:11');
INSERT INTO `log` VALUES ('378', '用户名为{1902}，角色为{老师用户}的用户登录成功!', '2019-12-21 19:28:16');
INSERT INTO `log` VALUES ('379', '用户名为{1903}，角色为{老师用户}的用户登录成功!', '2019-12-21 19:29:48');
INSERT INTO `log` VALUES ('380', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 19:30:26');
INSERT INTO `log` VALUES ('381', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 19:51:12');
INSERT INTO `log` VALUES ('382', '用户名为admin的用户登录时输入验证码错误!', '2019-12-21 20:00:45');
INSERT INTO `log` VALUES ('383', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 20:00:59');
INSERT INTO `log` VALUES ('384', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 20:04:40');
INSERT INTO `log` VALUES ('385', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 20:12:35');
INSERT INTO `log` VALUES ('386', '用户名为{1902}，角色为{老师用户}的用户登录成功!', '2019-12-21 20:18:16');
INSERT INTO `log` VALUES ('387', '用户名为1903的用户登录时输入验证码错误!', '2019-12-21 20:18:47');
INSERT INTO `log` VALUES ('388', '用户名为{1903}，角色为{老师用户}的用户登录成功!', '2019-12-21 20:18:57');
INSERT INTO `log` VALUES ('389', '用户名为{1903}，角色为{老师用户}的用户登录成功!', '2019-12-21 20:23:14');
INSERT INTO `log` VALUES ('390', '老师登录时，用户名为admin的用户不存在!', '2019-12-21 20:32:03');
INSERT INTO `log` VALUES ('391', '用户名为{1903}，角色为{老师用户}的用户登录成功!', '2019-12-21 20:32:15');
INSERT INTO `log` VALUES ('392', '用户名为{1903}，角色为{老师用户}的用户登录成功!', '2019-12-21 20:40:58');
INSERT INTO `log` VALUES ('393', '老师登录时，用户名为admin的用户不存在!', '2019-12-21 20:43:00');
INSERT INTO `log` VALUES ('394', '用户名为{1903}，角色为{老师用户}的用户登录成功!', '2019-12-21 20:43:12');
INSERT INTO `log` VALUES ('395', '用户名为1903的用户登录时输入验证码错误!', '2019-12-21 20:45:18');
INSERT INTO `log` VALUES ('396', '用户名为{1903}，角色为{老师用户}的用户登录成功!', '2019-12-21 20:45:29');
INSERT INTO `log` VALUES ('397', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 21:17:19');
INSERT INTO `log` VALUES ('398', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 21:22:52');
INSERT INTO `log` VALUES ('399', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 21:23:22');
INSERT INTO `log` VALUES ('400', '老师登录时，用户名为192300423的用户不存在!', '2019-12-21 21:33:01');
INSERT INTO `log` VALUES ('401', '用户名为1903的用户登录时输入验证码错误!', '2019-12-21 21:33:20');
INSERT INTO `log` VALUES ('402', '用户名为{1903}，角色为{老师用户}的用户登录成功!', '2019-12-21 21:33:32');
INSERT INTO `log` VALUES ('403', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 21:34:00');
INSERT INTO `log` VALUES ('404', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 21:49:12');
INSERT INTO `log` VALUES ('405', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 22:00:04');
INSERT INTO `log` VALUES ('406', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 22:17:03');
INSERT INTO `log` VALUES ('407', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 22:18:33');
INSERT INTO `log` VALUES ('408', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 22:20:21');
INSERT INTO `log` VALUES ('409', '用户名为admin的用户登录时输入验证码错误!', '2019-12-21 22:22:45');
INSERT INTO `log` VALUES ('410', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 22:22:54');
INSERT INTO `log` VALUES ('411', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 22:33:32');
INSERT INTO `log` VALUES ('412', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 22:39:01');
INSERT INTO `log` VALUES ('413', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 22:44:55');
INSERT INTO `log` VALUES ('414', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 22:46:26');
INSERT INTO `log` VALUES ('415', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 23:04:07');
INSERT INTO `log` VALUES ('416', '用户名为admin的用户登录时输入验证码错误!', '2019-12-21 23:06:58');
INSERT INTO `log` VALUES ('417', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 23:07:11');
INSERT INTO `log` VALUES ('418', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 23:09:04');
INSERT INTO `log` VALUES ('419', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 23:16:02');
INSERT INTO `log` VALUES ('420', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 23:26:53');
INSERT INTO `log` VALUES ('421', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 23:29:18');
INSERT INTO `log` VALUES ('422', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 23:40:17');
INSERT INTO `log` VALUES ('423', '用户名为admin的用户登录时输入验证码错误!', '2019-12-21 23:46:17');
INSERT INTO `log` VALUES ('424', '老师登录时，用户名为admin的用户不存在!', '2019-12-21 23:46:28');
INSERT INTO `log` VALUES ('425', '用户名为{1903}，角色为{老师用户}的用户登录成功!', '2019-12-21 23:46:38');
INSERT INTO `log` VALUES ('426', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 23:49:24');
INSERT INTO `log` VALUES ('427', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-21 23:52:03');
INSERT INTO `log` VALUES ('428', '老师登录时，用户名为admin的用户不存在!', '2019-12-21 23:56:45');
INSERT INTO `log` VALUES ('429', '老师登录时，用户名为192300423的用户不存在!', '2019-12-21 23:57:03');
INSERT INTO `log` VALUES ('430', '用户名为{1903}，角色为{老师用户}的用户登录成功!', '2019-12-21 23:57:19');
INSERT INTO `log` VALUES ('431', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-22 00:07:58');
INSERT INTO `log` VALUES ('432', '用户名为admin的用户登录时输入验证码错误!', '2019-12-22 00:16:22');
INSERT INTO `log` VALUES ('433', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-22 00:16:35');
INSERT INTO `log` VALUES ('434', '用户名为admin的用户登录时输入验证码错误!', '2019-12-22 00:18:52');
INSERT INTO `log` VALUES ('435', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-22 00:19:18');
INSERT INTO `log` VALUES ('436', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-22 00:22:14');
INSERT INTO `log` VALUES ('437', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-22 00:26:38');
INSERT INTO `log` VALUES ('438', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-22 00:28:58');
INSERT INTO `log` VALUES ('439', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-22 01:07:52');
INSERT INTO `log` VALUES ('440', '用户名为admin的用户登录时输入验证码错误!', '2019-12-22 01:10:37');
INSERT INTO `log` VALUES ('441', '用户名为admin的用户登录时输入验证码错误!', '2019-12-22 01:10:55');
INSERT INTO `log` VALUES ('442', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-22 01:11:02');
INSERT INTO `log` VALUES ('443', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-22 01:18:11');
INSERT INTO `log` VALUES ('444', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-22 09:30:26');
INSERT INTO `log` VALUES ('445', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-22 09:35:42');
INSERT INTO `log` VALUES ('446', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-22 09:38:21');
INSERT INTO `log` VALUES ('447', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-22 09:41:31');
INSERT INTO `log` VALUES ('448', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-22 09:55:07');
INSERT INTO `log` VALUES ('449', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-22 10:07:46');
INSERT INTO `log` VALUES ('450', '用户名为{1902}，角色为{老师用户}的用户登录成功!', '2019-12-22 10:08:26');
INSERT INTO `log` VALUES ('451', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-22 10:09:11');
INSERT INTO `log` VALUES ('452', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-22 10:40:17');
INSERT INTO `log` VALUES ('453', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-22 10:42:12');
INSERT INTO `log` VALUES ('454', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-22 10:43:40');
INSERT INTO `log` VALUES ('455', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-22 10:49:48');
INSERT INTO `log` VALUES ('456', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-22 11:13:06');
INSERT INTO `log` VALUES ('457', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-22 11:16:29');
INSERT INTO `log` VALUES ('458', '用户名为192300423的用户登录时输入验证码错误!', '2019-12-22 11:18:31');
INSERT INTO `log` VALUES ('459', '用户名为{192300423}，角色为{学生用户}的用户登录成功!', '2019-12-22 11:18:38');
INSERT INTO `log` VALUES ('460', '用户名为{192300423}，角色为{学生用户}的用户登录成功!', '2019-12-22 11:28:22');
INSERT INTO `log` VALUES ('461', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-22 11:29:42');
INSERT INTO `log` VALUES ('462', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-22 11:44:24');
INSERT INTO `log` VALUES ('463', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-22 11:55:23');
INSERT INTO `log` VALUES ('464', '用户名为{192300423}，角色为{学生用户}的用户登录成功!', '2019-12-22 11:56:50');
INSERT INTO `log` VALUES ('465', '用户名为admin的用户登录时输入验证码错误!', '2019-12-22 12:02:23');
INSERT INTO `log` VALUES ('466', '用户名为admin的用户登录时输入验证码错误!', '2019-12-22 12:02:50');
INSERT INTO `log` VALUES ('467', '用户名为admin的用户登录时输入验证码错误!', '2019-12-22 12:02:59');
INSERT INTO `log` VALUES ('468', '学生登录时，学号为admin的用户不存在!', '2019-12-22 12:03:08');
INSERT INTO `log` VALUES ('469', '用户名为{192300423}，角色为{学生用户}的用户登录成功!', '2019-12-22 12:03:21');
INSERT INTO `log` VALUES ('470', '用户名为{192300423}，角色为{学生用户}的用户登录成功!', '2019-12-22 12:17:57');
INSERT INTO `log` VALUES ('471', '用户名为{192300423}，角色为{学生用户}的用户登录成功!', '2019-12-22 12:22:33');
INSERT INTO `log` VALUES ('472', '用户名为{192300423}，角色为{学生用户}的用户登录成功!', '2019-12-22 12:29:18');
INSERT INTO `log` VALUES ('473', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-22 13:02:31');
INSERT INTO `log` VALUES ('474', '用户名为192300423的用户登录时输入验证码错误!', '2019-12-22 13:03:28');
INSERT INTO `log` VALUES ('475', '用户名为{192300423}，角色为{学生用户}的用户登录成功!', '2019-12-22 13:03:34');
INSERT INTO `log` VALUES ('476', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-22 13:04:07');
INSERT INTO `log` VALUES ('477', '用户名为192300423的用户登录时输入验证码错误!', '2019-12-22 13:04:59');
INSERT INTO `log` VALUES ('478', '用户名为{192300423}，角色为{学生用户}的用户登录成功!', '2019-12-22 13:05:04');
INSERT INTO `log` VALUES ('479', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-22 13:05:38');
INSERT INTO `log` VALUES ('480', '用户名为1903的用户登录时输入验证码错误!', '2019-12-22 13:06:29');
INSERT INTO `log` VALUES ('481', '用户名为{1903}，角色为{老师用户}的用户登录成功!', '2019-12-22 13:06:35');
INSERT INTO `log` VALUES ('482', '用户名为{192300423}，角色为{学生用户}的用户登录成功!', '2019-12-22 13:07:29');
INSERT INTO `log` VALUES ('483', '用户名为{1903}，角色为{老师用户}的用户登录成功!', '2019-12-22 13:09:58');
INSERT INTO `log` VALUES ('484', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-22 13:48:25');
INSERT INTO `log` VALUES ('485', '用户名为{1903}，角色为{老师用户}的用户登录成功!', '2019-12-22 13:49:02');
INSERT INTO `log` VALUES ('486', '用户名为{1903}，角色为{老师用户}的用户登录成功!', '2019-12-22 14:03:07');
INSERT INTO `log` VALUES ('487', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-22 14:03:46');
INSERT INTO `log` VALUES ('488', '用户名为{1903}，角色为{老师用户}的用户登录成功!', '2019-12-22 14:04:20');
INSERT INTO `log` VALUES ('489', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-22 14:05:02');
INSERT INTO `log` VALUES ('490', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-22 14:08:27');
INSERT INTO `log` VALUES ('491', '用户名为{1903}，角色为{老师用户}的用户登录成功!', '2019-12-22 14:08:57');
INSERT INTO `log` VALUES ('492', '用户名为1902的用户登录时输入验证码错误!', '2019-12-22 14:09:38');
INSERT INTO `log` VALUES ('493', '用户名为{1902}，角色为{老师用户}的用户登录成功!', '2019-12-22 14:09:45');
INSERT INTO `log` VALUES ('494', '用户名为admin的用户登录时输入验证码错误!', '2019-12-22 14:10:24');
INSERT INTO `log` VALUES ('495', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-22 14:10:56');
INSERT INTO `log` VALUES ('496', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-22 14:14:39');
INSERT INTO `log` VALUES ('497', '用户名为{1903}，角色为{老师用户}的用户登录成功!', '2019-12-22 14:15:02');
INSERT INTO `log` VALUES ('498', '用户名为{1903}，角色为{老师用户}的用户登录成功!', '2019-12-22 14:17:50');
INSERT INTO `log` VALUES ('499', '用户名为{1902}，角色为{老师用户}的用户登录成功!', '2019-12-22 14:18:47');
INSERT INTO `log` VALUES ('500', '用户名为{192300423}，角色为{学生用户}的用户登录成功!', '2019-12-22 14:19:14');
INSERT INTO `log` VALUES ('501', '用户名为{192300423}，角色为{学生用户}的用户登录成功!', '2019-12-22 14:23:16');
INSERT INTO `log` VALUES ('502', '学生登录时，学号为1902的用户不存在!', '2019-12-22 14:25:48');
INSERT INTO `log` VALUES ('503', '用户名为{192300423}，角色为{学生用户}的用户登录成功!', '2019-12-22 14:26:07');
INSERT INTO `log` VALUES ('504', '用户名为{192300423}，角色为{学生用户}的用户登录成功!', '2019-12-22 14:27:28');
INSERT INTO `log` VALUES ('505', '用户名为1903的用户登录时输入验证码错误!', '2019-12-22 14:28:12');
INSERT INTO `log` VALUES ('506', '用户名为{1903}，角色为{老师用户}的用户登录成功!', '2019-12-22 14:28:17');
INSERT INTO `log` VALUES ('507', '用户名为{192300423}，角色为{学生用户}的用户登录成功!', '2019-12-22 14:29:10');
INSERT INTO `log` VALUES ('508', '用户名为{192300423}，角色为{学生用户}的用户登录成功!', '2019-12-22 14:33:40');
INSERT INTO `log` VALUES ('509', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-22 14:34:31');
INSERT INTO `log` VALUES ('510', '用户名为admin的用户登录时输入验证码错误!', '2019-12-22 14:44:53');
INSERT INTO `log` VALUES ('511', '用户名为admin的用户登录时输入验证码错误!', '2019-12-22 14:45:33');
INSERT INTO `log` VALUES ('512', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-22 14:45:45');
INSERT INTO `log` VALUES ('513', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-22 22:40:48');
INSERT INTO `log` VALUES ('514', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-22 23:10:21');
INSERT INTO `log` VALUES ('515', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-22 23:13:08');
INSERT INTO `log` VALUES ('516', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-22 23:20:18');
INSERT INTO `log` VALUES ('517', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-22 23:29:58');
INSERT INTO `log` VALUES ('518', '用户名为{192300423}，角色为{学生用户}的用户登录成功!', '2019-12-22 23:35:02');
INSERT INTO `log` VALUES ('519', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-22 23:35:51');
INSERT INTO `log` VALUES ('520', '用户名为{192300423}，角色为{学生用户}的用户登录成功!', '2019-12-22 23:38:44');
INSERT INTO `log` VALUES ('521', '用户名为{192300423}，角色为{学生用户}的用户登录成功!', '2019-12-22 23:43:31');
INSERT INTO `log` VALUES ('522', '用户名为{192300424}，角色为{学生用户}的用户登录成功!', '2019-12-22 23:44:35');
INSERT INTO `log` VALUES ('523', '用户名为{192300423}，角色为{学生用户}的用户登录成功!', '2019-12-22 23:46:38');
INSERT INTO `log` VALUES ('524', '用户名为{192300423}，角色为{学生用户}的用户登录成功!', '2019-12-22 23:48:55');
INSERT INTO `log` VALUES ('525', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-22 23:50:20');
INSERT INTO `log` VALUES ('526', '用户名为{192300424}，角色为{学生用户}的用户登录成功!', '2019-12-22 23:51:08');
INSERT INTO `log` VALUES ('527', '用户名为{192300423}，角色为{学生用户}的用户登录成功!', '2019-12-22 23:54:30');
INSERT INTO `log` VALUES ('528', '用户名为192300423的用户登录时输入验证码错误!', '2019-12-22 23:56:40');
INSERT INTO `log` VALUES ('529', '用户名为{192300423}，角色为{学生用户}的用户登录成功!', '2019-12-22 23:56:48');
INSERT INTO `log` VALUES ('530', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-22 23:57:28');
INSERT INTO `log` VALUES ('531', '用户名为1903的用户登录时输入验证码错误!', '2019-12-23 00:05:19');
INSERT INTO `log` VALUES ('532', '用户名为{1903}，角色为{老师用户}的用户登录成功!', '2019-12-23 00:05:26');
INSERT INTO `log` VALUES ('533', '用户名为{192300423}，角色为{学生用户}的用户登录成功!', '2019-12-23 00:06:34');
INSERT INTO `log` VALUES ('534', '用户名为admin的用户登录时输入验证码错误!', '2019-12-23 00:07:47');
INSERT INTO `log` VALUES ('535', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-23 00:07:59');
INSERT INTO `log` VALUES ('536', '用户名为{192300423}，角色为{学生用户}的用户登录成功!', '2019-12-23 00:10:01');
INSERT INTO `log` VALUES ('537', '用户名为{192300423}，角色为{学生用户}的用户登录成功!', '2019-12-23 00:12:16');
INSERT INTO `log` VALUES ('538', '用户名为{192300423}，角色为{学生用户}的用户登录成功!', '2019-12-23 00:13:44');
INSERT INTO `log` VALUES ('539', '用户名为192300423的用户登录时输入验证码错误!', '2019-12-23 00:16:29');
INSERT INTO `log` VALUES ('540', '用户名为{192300423}，角色为{学生用户}的用户登录成功!', '2019-12-23 00:16:49');
INSERT INTO `log` VALUES ('541', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-23 00:17:17');
INSERT INTO `log` VALUES ('542', '用户名为{1903}，角色为{老师用户}的用户登录成功!', '2019-12-23 00:17:52');
INSERT INTO `log` VALUES ('543', '用户名为admin的用户登录时输入验证码错误!', '2019-12-23 10:06:01');
INSERT INTO `log` VALUES ('544', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-23 10:06:11');
INSERT INTO `log` VALUES ('545', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-23 10:08:53');
INSERT INTO `log` VALUES ('546', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-23 10:10:55');
INSERT INTO `log` VALUES ('547', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-23 10:11:30');
INSERT INTO `log` VALUES ('548', '用户名为{1903}，角色为{老师用户}的用户登录成功!', '2019-12-23 10:12:38');
INSERT INTO `log` VALUES ('549', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-23 10:13:28');
INSERT INTO `log` VALUES ('550', '管理员登录时,用户名为admin的用户登录时输入密码错误!', '2019-12-23 10:20:10');
INSERT INTO `log` VALUES ('551', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-23 10:20:24');
INSERT INTO `log` VALUES ('552', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-23 10:29:01');
INSERT INTO `log` VALUES ('553', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-23 10:34:43');
INSERT INTO `log` VALUES ('554', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-23 10:45:10');
INSERT INTO `log` VALUES ('555', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-23 10:48:37');
INSERT INTO `log` VALUES ('556', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-23 11:07:42');
INSERT INTO `log` VALUES ('557', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-23 11:10:16');
INSERT INTO `log` VALUES ('558', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-23 11:15:08');
INSERT INTO `log` VALUES ('559', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-23 11:21:19');
INSERT INTO `log` VALUES ('560', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-23 13:07:25');
INSERT INTO `log` VALUES ('561', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-23 13:18:08');
INSERT INTO `log` VALUES ('562', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-23 13:20:42');
INSERT INTO `log` VALUES ('563', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-23 13:49:41');
INSERT INTO `log` VALUES ('564', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-23 13:55:36');
INSERT INTO `log` VALUES ('565', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-23 13:59:08');
INSERT INTO `log` VALUES ('566', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-23 14:07:38');
INSERT INTO `log` VALUES ('567', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-23 14:11:48');
INSERT INTO `log` VALUES ('568', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-23 14:15:08');
INSERT INTO `log` VALUES ('569', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-23 14:27:56');
INSERT INTO `log` VALUES ('570', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-23 14:41:28');
INSERT INTO `log` VALUES ('571', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-23 14:46:47');
INSERT INTO `log` VALUES ('572', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-23 15:07:14');
INSERT INTO `log` VALUES ('573', '用户名为admin的用户登录时输入验证码错误!', '2019-12-23 15:11:17');
INSERT INTO `log` VALUES ('574', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-23 15:11:26');
INSERT INTO `log` VALUES ('575', '用户名为{1903}，角色为{老师用户}的用户登录成功!', '2019-12-23 15:25:21');
INSERT INTO `log` VALUES ('576', '用户名为admin的用户登录时输入验证码错误!', '2019-12-23 15:26:08');
INSERT INTO `log` VALUES ('577', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-23 15:26:13');
INSERT INTO `log` VALUES ('578', '用户名为{1903}，角色为{老师用户}的用户登录成功!', '2019-12-23 15:29:18');
INSERT INTO `log` VALUES ('579', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-23 15:33:39');
INSERT INTO `log` VALUES ('580', '用户名为admin的用户登录时输入验证码错误!', '2019-12-23 16:14:29');
INSERT INTO `log` VALUES ('581', '用户名为admin的用户登录时输入验证码错误!', '2019-12-23 16:14:38');
INSERT INTO `log` VALUES ('582', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-23 16:14:48');
INSERT INTO `log` VALUES ('583', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-23 16:19:53');
INSERT INTO `log` VALUES ('584', '用户名为admin的用户登录时输入验证码错误!', '2019-12-23 16:36:13');
INSERT INTO `log` VALUES ('585', '管理员登录时,用户名为admin的用户登录时输入密码错误!', '2019-12-23 16:36:25');
INSERT INTO `log` VALUES ('586', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-23 16:38:46');
INSERT INTO `log` VALUES ('587', '用户名为admin的用户登录时输入验证码错误!', '2019-12-24 13:57:39');
INSERT INTO `log` VALUES ('588', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-24 13:57:50');
INSERT INTO `log` VALUES ('589', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-24 13:58:16');
INSERT INTO `log` VALUES ('590', '用户名为{192300423}，角色为{学生用户}的用户登录成功!', '2019-12-24 13:58:52');
INSERT INTO `log` VALUES ('591', '用户名为{192300422}，角色为{学生用户}的用户登录成功!', '2019-12-24 13:59:15');
INSERT INTO `log` VALUES ('592', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-24 13:59:54');
INSERT INTO `log` VALUES ('593', '用户名为{192300422}，角色为{学生用户}的用户登录成功!', '2019-12-24 14:00:48');
INSERT INTO `log` VALUES ('594', '用户名为{192300423}，角色为{学生用户}的用户登录成功!', '2019-12-24 14:01:19');
INSERT INTO `log` VALUES ('595', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-24 14:01:44');
INSERT INTO `log` VALUES ('596', '用户名为{1903}，角色为{老师用户}的用户登录成功!', '2019-12-24 14:03:03');
INSERT INTO `log` VALUES ('597', '用户名为{192300424}，角色为{学生用户}的用户登录成功!', '2019-12-24 14:03:41');
INSERT INTO `log` VALUES ('598', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-24 14:06:33');
INSERT INTO `log` VALUES ('599', '用户名为1903的用户登录时输入验证码错误!', '2019-12-24 14:07:06');
INSERT INTO `log` VALUES ('600', '用户名为1903的用户登录时输入验证码错误!', '2019-12-24 14:07:14');
INSERT INTO `log` VALUES ('601', '用户名为{1903}，角色为{老师用户}的用户登录成功!', '2019-12-24 14:07:22');
INSERT INTO `log` VALUES ('602', '用户名为{192300423}，角色为{学生用户}的用户登录成功!', '2019-12-24 14:07:58');
INSERT INTO `log` VALUES ('603', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-24 14:11:30');
INSERT INTO `log` VALUES ('604', '用户名为{1903}，角色为{老师用户}的用户登录成功!', '2019-12-24 14:12:12');
INSERT INTO `log` VALUES ('605', '用户名为{192300423}，角色为{学生用户}的用户登录成功!', '2019-12-24 14:12:43');
INSERT INTO `log` VALUES ('606', '用户名为192300423的用户登录时输入验证码错误!', '2019-12-24 14:15:10');
INSERT INTO `log` VALUES ('607', '用户名为{192300423}，角色为{学生用户}的用户登录成功!', '2019-12-24 14:15:21');
INSERT INTO `log` VALUES ('608', '用户名为{192300423}，角色为{学生用户}的用户登录成功!', '2019-12-24 14:17:14');
INSERT INTO `log` VALUES ('609', '用户名为{192300423}，角色为{学生用户}的用户登录成功!', '2019-12-24 14:19:57');
INSERT INTO `log` VALUES ('610', '用户名为192300422的用户登录时输入验证码错误!', '2019-12-24 14:20:32');
INSERT INTO `log` VALUES ('611', '用户名为{192300422}，角色为{学生用户}的用户登录成功!', '2019-12-24 14:20:40');
INSERT INTO `log` VALUES ('612', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-24 14:21:35');
INSERT INTO `log` VALUES ('613', '用户名为{192300422}，角色为{学生用户}的用户登录成功!', '2019-12-24 14:22:23');
INSERT INTO `log` VALUES ('614', '用户名为admin的用户登录时输入验证码错误!', '2019-12-24 14:23:18');
INSERT INTO `log` VALUES ('615', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-24 14:23:24');
INSERT INTO `log` VALUES ('616', '用户名为{192300422}，角色为{学生用户}的用户登录成功!', '2019-12-24 14:28:30');
INSERT INTO `log` VALUES ('617', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-24 14:46:05');
INSERT INTO `log` VALUES ('618', '用户名为{192300423}，角色为{学生用户}的用户登录成功!', '2019-12-24 14:48:20');
INSERT INTO `log` VALUES ('619', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-24 14:49:14');
INSERT INTO `log` VALUES ('620', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-24 14:50:22');
INSERT INTO `log` VALUES ('621', '用户名为1903的用户登录时输入验证码错误!', '2019-12-24 14:51:12');
INSERT INTO `log` VALUES ('622', '用户名为1903的用户登录时输入验证码错误!', '2019-12-24 14:51:19');
INSERT INTO `log` VALUES ('623', '用户名为{1903}，角色为{老师用户}的用户登录成功!', '2019-12-24 14:51:25');
INSERT INTO `log` VALUES ('624', '用户名为{admin}，角色为{管理员}的用户登录成功!', '2019-12-24 15:01:09');
INSERT INTO `menu` VALUES ('1', '0', '系统设置', '', 'icon-advancedsettings');
INSERT INTO `menu` VALUES ('5', '1', '菜单管理', '../admin/menu/list', 'icon-chart-organisation');
INSERT INTO `menu` VALUES ('13', '1', '角色管理', '../admin/role/list', 'icon-group-key');
INSERT INTO `menu` VALUES ('14', '0', '用户管理', '', 'icon-group-gear');
INSERT INTO `menu` VALUES ('15', '14', '老师列表', '../admin/teach/list', 'icon-group');
INSERT INTO `menu` VALUES ('17', '5', '添加', 'openAdd()', 'icon-add');
INSERT INTO `menu` VALUES ('18', '5', '编辑', 'openEdit()', 'icon-bullet-edit');
INSERT INTO `menu` VALUES ('19', '5', '删除', 'remove()', 'icon-cross');
INSERT INTO `menu` VALUES ('20', '5', '添加按钮', 'openAddMenu()', 'icon-add');
INSERT INTO `menu` VALUES ('21', '13', '添加', 'openAdd()', 'icon-add');
INSERT INTO `menu` VALUES ('22', '13', '编辑', 'openEdit()', 'icon-bullet-edit');
INSERT INTO `menu` VALUES ('23', '13', '删除', 'remove()', 'icon-cross');
INSERT INTO `menu` VALUES ('24', '15', '添加', 'openAdd()', 'icon-add');
INSERT INTO `menu` VALUES ('25', '15', '编辑', 'openEdit()', 'icon-bullet-edit');
INSERT INTO `menu` VALUES ('26', '15', '删除', 'remove()', 'icon-cross');
INSERT INTO `menu` VALUES ('31', '0', '系统日志', '', 'icon-table-cell');
INSERT INTO `menu` VALUES ('32', '31', '日志列表', '../admin/log/list', 'icon-page-white-text');
INSERT INTO `menu` VALUES ('33', '32', '添加日志', 'openAdd()', 'icon-add1');
INSERT INTO `menu` VALUES ('34', '32', '删除', 'remove()', 'icon-cancel');
INSERT INTO `menu` VALUES ('35', '1', '修改密码', 'edit_password', 'icon-lock-edit');
INSERT INTO `menu` VALUES ('36', '35', '修改密码', 'openAdd()', 'icon-lock-edit');
INSERT INTO `menu` VALUES ('37', '0', '宿舍楼管理', '', 'icon-server-add');
INSERT INTO `menu` VALUES ('38', '0', '财产管理', '', 'icon-asterisk-orange');
INSERT INTO `menu` VALUES ('39', '0', '财产盘点管理', '', 'icon-asterisk-red');
INSERT INTO `menu` VALUES ('40', '0', '财产报修管理', '', 'icon-application-osx-terminal');
INSERT INTO `menu` VALUES ('41', '40', '财产报修列表', '../admin/fix/list', 'icon-advancedsettings2');
INSERT INTO `menu` VALUES ('42', '41', '添加', 'openAdd()', 'icon-add');
INSERT INTO `menu` VALUES ('43', '41', '删除', 'remove()', 'icon-cross-octagon');
INSERT INTO `menu` VALUES ('44', '41', '修改', 'openEdit()', 'icon-arrow-undo');
INSERT INTO `menu` VALUES ('46', '39', '财产盘点列表', '../admin/check/list', 'icon-advancedsettings2');
INSERT INTO `menu` VALUES ('47', '46', '修改', 'openEdit()', 'icon-arrow-undo');
INSERT INTO `menu` VALUES ('48', '46', '添加', 'openAdd()', 'icon-add');
INSERT INTO `menu` VALUES ('49', '46', '删除', 'remove()', 'icon-cross-octagon');
INSERT INTO `menu` VALUES ('50', '38', '财产列表', '../admin/asset/list', 'icon-disk');
INSERT INTO `menu` VALUES ('51', '50', '添加', 'openAdd()', 'icon-add');
INSERT INTO `menu` VALUES ('52', '50', '删除', 'remove()', 'icon-cross-octagon');
INSERT INTO `menu` VALUES ('53', '50', '修改', 'openEdit()', 'icon-arrow-undo');
INSERT INTO `menu` VALUES ('61', '37', '宿舍楼列表', '../admin/dormitory/list', 'icon-advancedsettings2');
INSERT INTO `menu` VALUES ('62', '61', '修改', 'openEdit()', 'icon-arrow-undo');
INSERT INTO `menu` VALUES ('63', '61', '删除', 'remove()', 'icon-cross-octagon');
INSERT INTO `menu` VALUES ('64', '61', '添加', 'openAdd()', 'icon-add');
INSERT INTO `menu` VALUES ('65', '14', '学生列表', '../admin/student/list', 'icon-group');
INSERT INTO `menu` VALUES ('66', '65', '添加', 'openAdd()', 'icon-add');
INSERT INTO `menu` VALUES ('67', '65', '编辑', 'openEdit()', 'icon-bullet-edit');
INSERT INTO `menu` VALUES ('68', '65', '删除', 'remove()', 'icon-cross');
INSERT INTO `menu` VALUES ('69', '14', '管理员列表', '../admin/user/list', 'icon-group');
INSERT INTO `menu` VALUES ('70', '69', '添加', 'openAdd()', 'icon-add');
INSERT INTO `menu` VALUES ('71', '69', '编辑', 'openEdit()', 'icon-bullet-edit');
INSERT INTO `menu` VALUES ('72', '69', '删除', 'remove()', 'icon-cross');
INSERT INTO `menu` VALUES ('74', '0', '报废处理', '', 'icon-build');
INSERT INTO `menu` VALUES ('75', '74', '报废列表', '../admin/bf/list', 'icon-bug-magnify');
INSERT INTO `menu` VALUES ('76', '75', '添加', 'openAdd()', 'icon-build');
INSERT INTO `menu` VALUES ('77', '75', '删除', 'remove()', 'icon-cross-octagon');
INSERT INTO `menu` VALUES ('78', '75', '删除', 'openEtid()', 'icon-arrow-undo');
INSERT INTO `menu` VALUES ('79', '50', '查询', '', 'icon-accept');
INSERT INTO `menu` VALUES ('80', '38', '财产分类列表', '../admin/assetcategory/list', 'icon-advancedsettings2');
INSERT INTO `menu` VALUES ('81', '80', '添加', 'openAdd()', 'icon-add1');
INSERT INTO `menu` VALUES ('82', '80', '修改', 'openEdit()', 'icon-arrow-undo');
INSERT INTO `menu` VALUES ('83', '80', '删除', 'remove()', 'icon-cross-octagon');
INSERT INTO `menu` VALUES ('84', '38', '财产条目列表', '../admin/assetpropertylist/list', 'icon-search');
INSERT INTO `menu` VALUES ('85', '84', '添加', 'openAdd()', 'icon-add');
INSERT INTO `menu` VALUES ('86', '84', '修改', 'openEdit()', 'icon-arrow-undo');
INSERT INTO `menu` VALUES ('87', '84', '删除', 'remove()', 'icon-cross-octagon');
INSERT INTO `registration` VALUES ('1903', '8', '0', '2019-12-23', '13');
INSERT INTO `repairs` VALUES ('6', '192300422', '9', '2019-12-24', '1', '123123');
INSERT INTO `role` VALUES ('1', '管理员', '管理员拥有一切权限！');
INSERT INTO `role` VALUES ('2', '老师用户', '老师用户,注意授权');
INSERT INTO `role` VALUES ('4', '学生用户', '学生用户,注意授权');
INSERT INTO `student` VALUES ('黄旭', '192300422', null, null, '123', '1', '1', '4', '/Dormitory/resources/upload/1577089406126.jpg', '10');
INSERT INTO `student` VALUES ('黄永华', '192300423', null, null, '123', '1', '1', '4', '/Dormitory/resources/upload/1577089432987.jpg', '11');
INSERT INTO `student` VALUES ('罗斯为', '192300424', null, null, '123', '1', '1', '4', '/Dormitory/resources/upload/1577089819471.jpg', '1');
INSERT INTO `teacher` VALUES ('1902', '张老师', '123', '1', '1', '湖南涉外经济学院', '2', '/Dormitory/resources/upload/1577089836555.jpg');
INSERT INTO `teacher` VALUES ('1903', '黄老师', '123', '1', '1', '湖南涉外经济学院', '2', '/Dormitory/resources/upload/1577089913724.jpg');
INSERT INTO `teacher` VALUES ('1904', '李老师', '123', '1', '1', '湖南涉外经济学院', '2', '/Dormitory/resources/upload/1577089386788.jpg');
INSERT INTO `user` VALUES ('1', 'admin', 'admin', '1', '/Dormitory/resources/upload/1577089740427.jpg', '1', '1', '搞事情');
