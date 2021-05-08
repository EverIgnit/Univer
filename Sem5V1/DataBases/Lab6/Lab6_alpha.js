'users' = {
    'full_name':String,
    'login':String,
    'pass':String,
    'hobbies':String,
    'role':String
}
'chats' = {
    'msgs_ids': ObjectId[],
    'users_ids': ObjectId[]
}
'msgs' = {
    'text':String,
    'sending_time':Date,
    'sender_id':Object
}