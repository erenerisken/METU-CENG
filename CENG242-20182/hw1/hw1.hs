module Hw1 where

type Mapping = [(String, String, String)]
data AST = EmptyAST | ASTNode String AST AST deriving (Show, Read)

writeExpression :: (AST, Mapping) -> String
evaluateAST :: (AST, Mapping) -> (AST, String)
-- DO NOT MODIFY OR DELETE THE LINES ABOVE -- 
-- IMPLEMENT writeExpression and evaluateAST FUNCTION ACCORDING TO GIVEN SIGNATURES -- 

getStr (ASTNode str n1 n2) = str

getNth (a,b,c) n = case n of
                    1 -> a
                    2 -> b
                    3 -> c

checkSC lst = if lst == [] then ""
                else ";"

addMapping (a:rest) = let s1 = getNth a 1; s2 = getNth a 2; s3 = getNth a 3 in
                        case s2 of
                            "str" -> s1 ++ "=\"" ++ s3 ++ "\"" ++ checkSC rest ++ addMapping rest
                            "num" -> s1 ++ "=" ++ s3 ++ checkSC rest ++ addMapping rest
addMapping [] = ""

writeExpression (ASTNode str n1 n2, m) = if m /= [] then "let " ++ addMapping m ++ " in " ++ writeExpression' (ASTNode str n1 n2)
                                            else writeExpression' (ASTNode str n1 n2)
writeExpression (EmptyAST , _) = ""

writeExpression' (ASTNode "str" n1 _) = "\"" ++ (getStr n1) ++ "\""
writeExpression' (ASTNode "num" n1 _) = getStr n1
writeExpression' (ASTNode "plus" n1 n2) = "(" ++ (writeExpression' n1) ++ "+" ++ (writeExpression' n2) ++ ")"
writeExpression' (ASTNode "times" n1 n2) = "(" ++ (writeExpression' n1) ++ "*" ++ (writeExpression' n2) ++ ")"
writeExpression' (ASTNode "negate" n1 _) = "(-" ++ (writeExpression' n1) ++ ")"
writeExpression' (ASTNode "cat" n1 n2) = "(" ++ (writeExpression' n1) ++ "++" ++ (writeExpression' n2) ++ ")"
writeExpression' (ASTNode "len" n1 _) = "(length " ++ (writeExpression' n1) ++ ")"
writeExpression' (ASTNode a EmptyAST EmptyAST) = a


findVariable [] _ = ("error!", "notfound!", "")
findVariable (a:rest) var = if (getNth a 1) == var then (getNth a 2, getNth a 3, "")
                                else findVariable rest var

insertVar (EmptyAST, _) = EmptyAST
insertVar (ASTNode "str" n1 _ , _) = ASTNode "str" n1 EmptyAST
insertVar (ASTNode "num" n1 _ , _) = ASTNode "num" n1 EmptyAST
insertVar (ASTNode "plus" n1 n2, m) = ASTNode "plus" (insertVar (n1, m)) (insertVar (n2, m))
insertVar (ASTNode "times" n1 n2, m) = ASTNode "times" (insertVar (n1, m)) (insertVar (n2, m))
insertVar (ASTNode "cat" n1 n2, m) = ASTNode "cat" (insertVar (n1, m)) (insertVar (n2, m))
insertVar (ASTNode "negate" n1 _ , m) = ASTNode "negate" (insertVar(n1, m)) EmptyAST
insertVar (ASTNode "len" n1 _ , m) = ASTNode "len" (insertVar(n1, m)) EmptyAST
insertVar (ASTNode a EmptyAST EmptyAST, m) = let varType = getNth (findVariable m a) 1
                                                 varValue = getNth (findVariable m a) 2
                                             in ASTNode varType (ASTNode varValue EmptyAST EmptyAST) EmptyAST

calcASTNum :: AST -> Int
calcASTStr :: AST -> String

calcASTStr (ASTNode "str" n1 EmptyAST) = getStr n1
calcASTStr (ASTNode "cat" n1 n2) = calcASTStr n1 ++ calcASTStr n2
calcASTNum (ASTNode "num" n1 EmptyAST) = read (getStr n1) :: Int
calcASTNum (ASTNode "plus" n1 n2) = calcASTNum n1 + calcASTNum n2
calcASTNum (ASTNode "times" n1 n2) = calcASTNum n1 * calcASTNum n2
calcASTNum (ASTNode "negate" n1 EmptyAST) = - (calcASTNum n1)
calcASTNum (ASTNode "len" n1 EmptyAST) = length(calcASTStr n1)

calcAST EmptyAST = ""
calcAST n@(ASTNode s1 n1 n2) = case s1 of
                                "str" -> calcASTStr n
                                "cat" -> calcASTStr n
                                _ -> show (calcASTNum n)

evaluateAST (ast, m) = (edited, calcAST edited) where edited = insertVar (ast, m)