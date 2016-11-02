greetEnglish :: String -> String
greetEnglish name = 
	"Hello " ++ name
	
greetFrench :: String -> String
greetFrench name = 
	"Bonjour " ++ name
	
greet1 :: String -> Char -> String
greet1 name lang = 
	if lang == 'e'
		then greetEnglish name
		else greetFrench name
		
greet2 :: String -> Char -> String
greet2 name lang = 
	case lang of
		'e' -> greetEnglish name
		'f' -> greetFrench name
		
circumAndArea1 :: Float -> (Float, Float)
circumAndArea1 radius = 
	(circum,area)
	where
		circum = 2 * pi * radius
		area = pi * radius ^ 2
		
circumAndArea2 :: Float -> (Float, Float)
circumAndArea2 radius = 
	let
		circum = 2 * pi * radius
		area = pi * radius ^ 2
	in
	   (circum,area)			
	   
makeReview :: String -> String
makeReview artist = 
	case artist of
		"Lady Gaga" -> "Amazing"
		"Justin Bieber" -> "Out of this world"
		"Rebecca Black" -> "Best singer ever"
		"One Direction" -> "So fit"
		
birthdayMessage :: Int -> String
birthdayMessage age 
	| age < 20 =  "Happy Birthday - you are " ++ show age ++ "!"
	| age > 100 = "Happy Birthday from the queen"
	| otherwise = "Happy Birthday, another year older"
	
-- largest :: Int -> Int -> Int
-- largest one two
	-- | one > two = one
	-- | one < two = two
	-- | otherwise = 0
	
pairTeams teams =
	[ (x,y) | x <- teams, y <- teams, x /= y ]
	
square :: Int -> Int
square number =
	number^2
double :: Int -> Int
double number = 
	number * 2
triple :: Int -> Int
triple number =
	number * 3
	
lessThanTen :: Int -> Bool
lessThanTen x = 
	if x < 10
		then True
		else False	
	
isPositive :: Int -> Bool
isPositive x = 
	if x > 0
		then True
		else False	

startsWithA :: String -> Bool
startsWithA x =
	if (head(x) == 'A')
		then True
		else False
		
squaresLessThanTen :: [Int] -> [Int]
squaresLessThanTen xs = filter lessThanTen(map square xs)

triplePos :: [Int] -> [Int]
triplePos xs = filter isPositive(map triple xs)

-- largest :: [Int] -> int
-- largest [] = []
-- largest x = x
-- largest (x:xs) = 
	-- if x > b
	-- then xs
	-- else b
	-- where b = largest x

isY :: Int -> Int -> Bool
isY x y = 
	if (x == y)
		then True
		else False
		
member :: Int -> [Int] -> Bool 
member y [] = False
member y (x:xs) = 
	if x == y
	then True
	else member y xs

beginning :: [a] -> [a]
beginning [] = error "empty list"
beginning [x] = []
beginning xs = 
	last [] xs
	
last :: [list] -> [list] -> [list]
	
	



	
	
	