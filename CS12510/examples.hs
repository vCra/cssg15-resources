module Main where
import Data.Char (isSpace)

-- The function to square an integer

square   :: Int -> Int
square x = x * x


-- The function to double an integer

double   :: Int -> Int
double x = x + x 

-- Some type synonyms

type Grade = Char
type Username = String

type ExamResult = (Username,Grade)

incSeven :: Int -> Int
incSeven x = x + 7

type TeamScore = (String, Int)
type MatchOutcome = (TeamScore, TeamScore)
-- e.g. (("Aber", 2), ("Swansea", 1))

winningTeam :: MatchOutcome -> String
winningTeam ((t1, s1), (t2, s2)) =
	if s1 > s2 then t1 else t2
	
goalDifference :: MatchOutcome -> Int
goalDifference ((t1, s1), (t2, s2)) =
	s1 - s2
	
-- showTeamResult :: TeamScore -> String
-- showTeamResult score = 
	-- fst(score) ++ " " ++ snd(score)
	
plusThree :: Int -> Int -> Int -> Int
plusThree num1 num2 num3 =
	num1 + num2+ num3

perimeter :: Int -> Int -> Int
perimeter length side = 
	(length*2) + (side*2)
	
greetEnglish :: String -> String
greetEnglish name = 
	"Hello" + name
	
greetFrench :: String -> String
greetFrench name = 
	"Bonjour" + name
	
doubleTriple :: Int -> (Int, Int)
doubleTriple number = 
	(number*2,number*3)

--higherScore :: ExamResult -> ExamResult -> Username
--higherScore Result1 Result2 = 
--	if snd (Result1) > snd (Result2)
--		then fst(Result1)
--  	else fst(Result2)
--
--	{-	
-- LECTURE 4	
	
birthdayMessage :: Int -> String
birthdayMessage age = 
	 if age < 20	
		then "Happy Birthday - you are " ++ show age ++ "!"
		else if age > 100
			then "Happy Birthday from the queen"
			else "Happy Birthday, another year older"
			
sumDiff :: Int -> Int -> Int
sumDiff num1 num2 = 
	d^2 + s^2 
	where
		s = num1+num2
		d = num1-num2
--	let 
--		s = num1+num2
--		d = num1-num2
--	in 
--		d^2 + s^2 
	

-- makeMenuChoice = 
		-- case keypress of
			-- '1' -> showFlights
			-- '2' -> ShowHolidays
			-- '3' -> showcCurrency
			-- '4' -> quit
			
		-- is Origin point =
			-- case point of 
				-- (0,0) 	-> True
						-- -> False
				-- -
 
-- makeReview :: String -> String
-- makeReview = 
	-- case artist of
		-- "Lady Gaga" -> "Amazing"
		-- "Justin Bieber" -> "Out of this world"
		-- "Rebecca Black" -> "Best singer ever"
		-- "One Direction" -> "So fit"
		-- "Miley Cyrus" -> "I would lick her any day"


-- Practical 1

greet :: String -> Char -> String
greet name lang = 
	if lang == 'e'
		then greetEnglish name
		else greetFrench name
		
pairTeams teams =
	[ (x,y) | x <- teams, y <- teams, x /= y ]
	
largest :: [Int] -> int
largest []     = []
largest x      = x
largest (x:xs) = 
	if x > b
	then xs
	else b
	where b = largest xs
	
isLarger :: int -> int -> Bool
isLarger a b =
	if a > b
	then True
	else False
	
thrice :: (a -> a) -> a -> a
thrice f = f . f . f 

trimSp :: String -> String
trimSp  =  reverse. dropWhile isSpace .reverse. dropWhile isSpace
		
