mkdir db1
mkdir db2
mkdir arb
mkdir shard1
mkdir shard2
mkdir config

mongod --dbpath db1 --port 10001 --replSet replica
mongod --dbpath db2 --port 10002 --replSet replica
mongod --dbpath arb --port 10003 --replSet replica
mongo --port 10001
rs.initialize()
replica:SECONDARY> rs.status()
replica:PRIMARY> rs.add("localhost:10002")
replica:PRIMARY> rs.addArb("localhost:10003")
replica:PRIMARY> rs.status()

mongod --shardsvr --port 10005 --replSet shard1 --dbpath shard1 --bind_ip localhost
mongod --shardsvr --port 10006 --replSet shard2 --dbpath shard2 --bind_ip localhost
mongod --configsvr --port 10004 --replSet shard0 --dbpath config --bind_ip localhost
mongos --port 10007 --configdb shard0/localhost:10004
mongo --port 10004
sh.addShard("shard1/localhost:10005,localhost:10006")
sh.enableSharding("test")
sh.status()
sh.shardCollection("test.user",{_id:"hashed"})
use testshow collections
use admin
db.runCommand({shardColletion:"test.user",key:{_id:"hashed"}})
db.pringShardingStatus()
