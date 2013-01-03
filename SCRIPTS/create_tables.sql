/*
MarkUppApp scripts

author: Scott Fusilier 2012

Note:
run as database root user initially
*/

DROP DATABASE Photos;
DROP TABLE Photo;
DROP TABLE Tag;

CREATE DATABASE Photos;
USE Photos;

CREATE TABLE Photo(
    imageID INT UNSIGNED NOT NULL AUTO_INCREMENT,
    filePath CHAR(255),
    filename CHAR(255),
    PRIMARY KEY(imageID)
);

CREATE TABLE Tag(
    ID INT UNSIGNED NOT NULL,
    name VARCHAR(56),
    xPos INT,
    yPos INT
);

GRANT ALL PRIVILEGES ON Photos.*
TO 'scott'@'localhost'
IDENTIFIED BY 'password' WITH
GRANT OPTION;
