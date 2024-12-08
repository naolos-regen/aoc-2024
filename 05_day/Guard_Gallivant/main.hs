import Data.Set (Set)
import qualified Data.Set as Set
import Data.List (elemIndex)
import System.Environment (getArgs)

type Position = (Int, Int)
type Walls = Set Position
type Direction = Int
type Visited = Set Position
type VisitedRotations = Set (Position, Direction)

directions :: [(Int, Int)]
directions = [(0,-1), (1, 0), (0, 1), (-1, 0)]


findLoopInductingPositions :: Int -> Int -> Walls -> Int -> Int -> Set Position
findLoopInductingPositions width height walls startX startY =
  Set.fromList [(x, y) | x <- [0..width-1], y <- [0..height-1],
                not ((x, y) `Set.member` walls),
                (x, y) /= (startX, startY),
                isLoopy width height walls startX startY x y]

main :: IO()
main = do
  args <- getArgs
  if null args then
    putStrLn "Useage: <program> <input_file>"
  else do
     let inputFile = head args
     input <- lines <$> readFile inputFile
     let (walls, startX, startY, width, height) = parseInput input
     let visited = simulatePath width height walls startX startY
     putStrLn $ "Part 1: " ++ show (Set.size visited)
     let loopPositions = findLoopInductingPositions width height walls startX startY
     putStrLn $ "Part 2: " ++ show (Set.size loopPositions)


parseInput :: [String] -> (Walls, Int, Int, Int, Int)
parseInput input =
    let height = length input
        width = length (head input)
        (walls, startX, startY) = foldr parseLine (Set.empty, -1, -1) (zip input [0..])
    in (walls, startX, startY, width, height)
  where
    parseLine (line, y) (walls, startX, startY) =
        foldr (parseChar y) (walls, startX, startY) (zip line [0..])
    parseChar y (c, x) (walls, startX, startY)
        | c == '#'  = (Set.insert (x, y) walls, startX, startY)
        | c == '^'  = (walls, x, y)
        | otherwise = (walls, startX, startY)


simulatePath :: Int -> Int -> Walls -> Int -> Int -> Visited
simulatePath width height walls startX startY =
    go startX startY 0 Set.empty
  where
    go x y d visited
      | nx < 0 || ny < 0 || nx >= width || ny >= height = visited
      | (nx, ny) `Set.member` walls = go x y ((d + 1) `mod` 4) visited
      | otherwise = go nx ny d (Set.insert (x, y) visited)
      where
        (dx, dy) = directions !! d
        nx = x + dx
        ny = y + dy


isLoopy :: Int -> Int -> Walls -> Int -> Int -> Int -> Int -> Bool
isLoopy width height walls startX startY ox oy =
   go startX startY 0 Set.empty
  where
   walls' = Set.insert (ox, oy) walls
   go x y d visited
      | nx < 0 || ny < 0 || nx >= width || ny >= height = False
      | (nx, ny, d) `Set.member` visited = True
      | (nx, ny) `Set.member` walls' = go x y ((d + 1) `mod` 4) (Set.insert (x, y, d) visited)
      | otherwise = go nx ny d (Set.insert (x, y, d) visited)
      where
        (dx, dy) = directions !! d
        nx = x + dx
        ny = y + dy

