CREATE DATABASE DreamHome
ON PRIMARY (NAME = DreamHome,
FILENAME='C:\Programfiles\MicrosoftSqlserver\mssql.1\mssql\Data\DreamHome.mdf',
Size = 15Mb,
MaxSize = 30Mb,
FileGrowth = 1Mb)
Log On
(NAME = DreamHome_log,
FILENAME='c:\programfiles\microsoftsqlserver\mssql.1\mssql\data\DreamHome.ldf',
Size= 2Mb,
MaxSize = 7Mb,
FileGrowth = 1Mb)
