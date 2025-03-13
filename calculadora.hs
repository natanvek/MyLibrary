

(%) :: Integer -> Integer -> Integer
(%) a b = a `mod` b

(//) :: Integer -> Integer -> Integer
(//) a b = a `div` b


ceil :: Integer -> Integer -> Integer
ceil a b = a `div` b + if a % b > 0 then 1 else 0

(/^) :: Integer -> Integer -> Integer
(/^) a b = a `ceil` b




