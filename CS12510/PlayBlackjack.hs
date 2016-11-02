module Main where 

import CardGames

-- We'll explain the type IO () and the keyword do in a future lecture
main :: IO ()
main = 
  do 
    if play makePack then print "I win" else print "You win" 

play :: Pack -> Bool
play pack = 
  let 
    (myHand,   pack1) = deal 7 pack
    (yourHand, pack2) = deal 7 pack1
  in
    beats (head myHand) (head yourHand)


