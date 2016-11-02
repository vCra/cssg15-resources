data Day = Mon | Tues | Weds | Thur | Fri | Sat | Sun deriving (Eq,Show)

isPayDay :: Day-> Bool
isPayDay day
	| day == Fri = True
	| otherwise = False
	
-- intToDay :: Int -> Maybe Day
-- intToDay day
	-- | day == 1 = Mon
	-- | day == 2 = Tues
	-- | day == 3 = Weds
	-- | day == 4 = Thur
	-- | day == 5 = Fri
	-- | day == 6 = Sat
	-- | day == 7 = Sun
	-- | otherwise = Nothing
	
data Triangle = NotATriangle | Equilateral | Isoceles | Scalene deriving (Show)

sidesToTriangle :: (Int,Int,Int) -> Triangle
sidesToTriangle (a,b,c) =
	if a == b
		then if b == c
			then Equilateral
		else Isoceles
	else if b == c
		then Isoceles
	else if c == a
		then Isoceles
	else Scalene