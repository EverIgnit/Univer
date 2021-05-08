DROP DATABASE DreamHome
CREATE DATABASE DreamHome
ON PRIMARY (NAME = DreamHome,
FILENAME='D:\Programming\Education\Subd\DreamHome.mdf',
Size = 3Mb,
MaxSize = 15Mb,
FileGrowth = 1Mb)
Log On
(NAME=DreamHome_log,
FILENAME='D:\Programming\Education\Subd\DreamHome.ldf',
Size= 1Mb,
MaxSize = 10Mb,
FileGrowth = 1Mb)