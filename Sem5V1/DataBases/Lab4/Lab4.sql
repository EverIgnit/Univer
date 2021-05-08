-- Fill users_chats
INSERT INTO users_chats(account_id,chat_id)
WITH chat_id AS (
	SELECT * FROM GENERATE_SERIES(3, 1000) as ids
)
SELECT (RANDOM()*1000+6)::INT, chat_id.ids+5
FROM chat_id;
-- Fill users
INSERT INTO users(email, password)
WITH emails AS (
	SELECT
	  'user_' || seq || '@' || (
		CASE (RANDOM() * 2)::INT
		  WHEN 0 THEN 'gmail'
		  WHEN 1 THEN 'hotmail'
		  WHEN 2 THEN 'yahoo'
		END
	  ) || '.com' AS email
	FROM GENERATE_SERIES(3, 999999) seq
)
SELECT emails.email, (RANDOM() * 9)::INT
FROM emails;
-- Fill chats
INSERT INTO chats(id)
(
	SELECT seq
	FROM GENERATE_SERIES(2, 999999) seq
);
-- Fill messages
INSERT INTO messages(content, sender_id, chat_id)
WITH msgtext AS (
	SELECT (RANDOM()*1000+6)::INT AS contents
	FROM GENERATE_SERIES(3, 1000) seq
), senders_id AS (
	SELECT (RANDOM()*1000+6)::INT AS ids
	FROM GENERATE_SERIES(3, 1000) seq
)
SELECT msgtext.contents, senders_id.ids, (RANDOM()*1000+6)::INT
FROM msgtext, senders_id;
-- Вывести переписки в беседах с количеством человек больше 5
SELECT
	msgs.chat_id,
	msgs.content
FROM messages msgs
WHERE msgs.chat_id IN (
-- Чаты, в которых есть >5 пользователей
	SELECT chat_users_am.id
	FROM (
		-- Чаты с соответствующим количеством пользователей
		SELECT chats.id, COUNT(*) AS am FROM chats
		JOIN users_chats ON users_chats.chat_id = chats.id
		GROUP BY chats.id
	) AS chat_users_am
	WHERE am > 5
)
ORDER BY msgs.chat_id;