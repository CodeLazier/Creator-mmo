@echo off
cd /d %~dp0
title ���ݿ�-s1-3310
mysqld --defaults-file=..\my.ini --console
pause