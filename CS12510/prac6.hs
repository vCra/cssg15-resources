import Data.Char
thrice :: (a -> a) -> a -> a
thrice f = f . f . f 

trimSp :: String -> String
trimSp  =  reverse. dropWhile isSpace .reverse. dropWhile isSpace

diffs :: [Int] -> [Int]
diffs [] = 0
diffs (xs:x) = zipWith difference [xs] x

difference :: Int -> Int -> Int
difference a b =  a-b

-- locations :: Eq a => a -> [a] -> [Int]
-- locations -> x ys =
	-- map ys (filter (zip [0..] ys))
	
-- splitter :: (a->bool) -> [a] -> (a,b)
-- spliter [] 