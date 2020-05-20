module Hw2 where

data ASTResult = ASTError String | ASTJust (String, String, Int) deriving (Show, Read)
data ASTDatum = ASTSimpleDatum String | ASTLetDatum String deriving (Show, Read)
data AST = EmptyAST | ASTNode ASTDatum AST AST deriving (Show, Read)

isNumber :: String -> Bool
eagerEvaluation :: AST -> ASTResult
normalEvaluation :: AST -> ASTResult
-- DO NOT MODIFY OR DELETE THE LINES ABOVE -- 
-- IMPLEMENT isNumber, eagerEvaluation and normalEvaluation FUNCTIONS ACCORDING TO GIVEN SIGNATURES -- 

eagerEvaluation tree = eagerEvaluate tree []

normalEvaluation tree = normalEvaluate tree []

isNumber ('-':rest) = if rest == "" then False else isNumber' rest
isNumber str = isNumber' str

isNumber' "" = True
isNumber' (a:rest) = case a of
                        '0' -> isNumber' rest
                        '1' -> isNumber' rest
                        '2' -> isNumber' rest
                        '3' -> isNumber' rest
                        '4' -> isNumber' rest
                        '5' -> isNumber' rest
                        '6' -> isNumber' rest
                        '7' -> isNumber' rest
                        '8' -> isNumber' rest
                        '9' -> isNumber' rest
                        _ -> False
-- Eager Evaluation Functions
data EagerBinding = EagerValue (String, String, String, Int) | EmptyBinding -- name type value step

getEagerBinding [] _ = EmptyBinding
getEagerBinding (EagerValue(name, valType, val, step) : rest) var = if var == name then EagerValue(name, valType, val, step) else getEagerBinding rest var

getEagerList [] _ = []
getEagerList (EagerValue(name, valType, val, step):rest) var = if var == name then getEagerList rest var else [EagerValue(name, valType, val, step)] ++ getEagerList rest var

addEagerBinding (EagerValue(name, valType, val, step)) bindList = (getEagerList bindList name) ++ [EagerValue(name, valType, val, step)]

eagerGetNum (ASTNode (ASTSimpleDatum num) EmptyAST EmptyAST) = if isNumber num
                                                                    then (ASTJust (num, "num", 0))
                                                                else (ASTError ("the value '" ++ num ++ "' is not a number!"))
                                                    
eagerGetStr (ASTNode (ASTSimpleDatum str) EmptyAST EmptyAST) = ASTJust (str, "str", 0)

eagerEvaluate (ASTNode (ASTSimpleDatum "num") num EmptyAST) _ = eagerGetNum num
eagerEvaluate (ASTNode (ASTSimpleDatum "str") str EmptyAST) _ = eagerGetStr str
                                                                                            
eagerEvaluate (ASTNode (ASTSimpleDatum "plus") op1 op2) bindList = let res1 = eagerEvaluate op1 bindList
                                                                       res2 = eagerEvaluate op2 bindList
                                                                   in case res1 of
                                                                        ASTError _ -> res1
                                                                        ASTJust(_, "str", _) -> case res2 of
                                                                                                    ASTError _ -> res2
                                                                                                    ASTJust (_, "str", _) -> ASTError "plus operation is not defined between str and str!"
                                                                                                    ASTJust (_, "num", _) -> ASTError "plus operation is not defined between str and num!"
                                                                        ASTJust(val1, "num", step1) -> case res2 of
                                                                                                        ASTError _ -> res2
                                                                                                        ASTJust (_, "str", _) -> ASTError "plus operation is not defined between num and str!"
                                                                                                        ASTJust (val2, "num", step2) -> ASTJust (show ((read(val1)::Int) + (read(val2)::Int)), "num", 1 + step1 + step2)
eagerEvaluate (ASTNode (ASTSimpleDatum "times") op1 op2) bindList = let res1 = eagerEvaluate op1 bindList
                                                                        res2 = eagerEvaluate op2 bindList
                                                                    in case res1 of
                                                                        ASTError _ -> res1
                                                                        ASTJust(_, "str", _) -> case res2 of
                                                                                                    ASTError _ -> res2
                                                                                                    ASTJust (_, "str", _) -> ASTError "times operation is not defined between str and str!"
                                                                                                    ASTJust (_, "num", _) -> ASTError "times operation is not defined between str and num!"
                                                                        ASTJust(val1, "num", step1) -> case res2 of
                                                                                                        ASTError _ -> res2
                                                                                                        ASTJust (_, "str", _) -> ASTError "times operation is not defined between num and str!"
                                                                                                        ASTJust (val2, "num", step2) -> ASTJust (show ((read(val1)::Int) * (read(val2)::Int)), "num", 1 + step1 + step2)
eagerEvaluate (ASTNode (ASTSimpleDatum "cat") op1 op2) bindList =   let res1 = eagerEvaluate op1 bindList
                                                                        res2 = eagerEvaluate op2 bindList
                                                                    in case res1 of
                                                                        ASTError _ -> res1
                                                                        ASTJust(_, "num", _) -> case res2 of
                                                                                                    ASTError _ -> res2
                                                                                                    ASTJust (_, "str", _) -> ASTError "cat operation is not defined between num and str!"
                                                                                                    ASTJust (_, "num", _) -> ASTError "cat operation is not defined between num and num!"
                                                                        ASTJust(val1, "str", step1) -> case res2 of
                                                                                                        ASTError _ -> res2
                                                                                                        ASTJust (_, "num", _) -> ASTError "cat operation is not defined between str and num!"
                                                                                                        ASTJust (val2, "str", step2) -> ASTJust (val1 ++ val2, "str", 1 + step1 + step2)
eagerEvaluate (ASTNode (ASTSimpleDatum "negate") num EmptyAST) bindList = let res = eagerEvaluate num bindList
                                                                          in case res of
                                                                             ASTError _ -> res
                                                                             ASTJust(_, "str", _) -> ASTError "negate operation is not defined on str!"
                                                                             ASTJust(val, "num", step) -> ASTJust(show(-1 * (read(val)::Int)), "num", step+1)
eagerEvaluate (ASTNode (ASTSimpleDatum "len") str EmptyAST) bindList = let res = eagerEvaluate str bindList
                                                                          in case res of
                                                                             ASTError _ -> res
                                                                             ASTJust(_, "num", _) -> ASTError "len operation is not defined on num!"
                                                                             ASTJust(val, "str", step) -> ASTJust(show(length val), "num", step+1)
--
eagerEvaluate (ASTNode (ASTSimpleDatum var) EmptyAST EmptyAST) bindList = let binding = getEagerBinding bindList var
                                                                            in case binding of
                                                                                EmptyBinding -> ASTError ("no variable named '" ++ var ++ "'!")
                                                                                EagerValue(_, valType, val, step) -> ASTJust(val, valType, 0)
--
eagerEvaluate (ASTNode (ASTLetDatum var) left right) bindList = let leftVal = eagerEvaluate left bindList
                                                                    in case leftVal of
                                                                        ASTError _ -> leftVal
                                                                        ASTJust(lVal, lValType, lStep) -> let rValue = (eagerEvaluate right (addEagerBinding (EagerValue(var, lValType, lVal, lStep)) bindList))
                                                                                                            in case rValue of
                                                                                                                ASTError _ -> rValue
                                                                                                                ASTJust(rVal, rValType, rStep) -> ASTJust(rVal, rValType, rStep + lStep)
--

-- Normal Evaluation Functions
data NormalBinding = NormalValue (String, AST) | EmptyNormalBinding -- name tree

getNormalBinding [] _ = EmptyNormalBinding
getNormalBinding (NormalValue(name, tree) : rest) var = if var == name then NormalValue(name, tree) else getNormalBinding rest var

getNormalList [] _ = []
getNormalList (NormalValue(name, tree):rest) var = if var == name then getNormalList rest var else [NormalValue(name, tree)] ++ getNormalList rest var

addNormalBinding (NormalValue(name, tree)) bindList = (getNormalList bindList name) ++ [NormalValue(name, tree)]

normalGetNum (ASTNode (ASTSimpleDatum num) EmptyAST EmptyAST) = if isNumber num
                                                                    then (ASTJust (num, "num", 0))
                                                                else (ASTError ("the value '" ++ num ++ "' is not a number!"))
                                                    
normalGetStr (ASTNode (ASTSimpleDatum str) EmptyAST EmptyAST) = ASTJust (str, "str", 0)

normalEvaluate (ASTNode (ASTSimpleDatum "num") num EmptyAST) _ = normalGetNum num
normalEvaluate (ASTNode (ASTSimpleDatum "str") str EmptyAST) _ = normalGetStr str
                                                                                            
normalEvaluate (ASTNode (ASTSimpleDatum "plus") op1 op2) bindList = let res1 = normalEvaluate op1 bindList
                                                                        res2 = normalEvaluate op2 bindList
                                                                   in case res1 of
                                                                        ASTError _ -> res1
                                                                        ASTJust(_, "str", _) -> case res2 of
                                                                                                    ASTError _ -> res2
                                                                                                    ASTJust (_, "str", _) -> ASTError "plus operation is not defined between str and str!"
                                                                                                    ASTJust (_, "num", _) -> ASTError "plus operation is not defined between str and num!"
                                                                        ASTJust(val1, "num", step1) -> case res2 of
                                                                                                        ASTError _ -> res2
                                                                                                        ASTJust (_, "str", _) -> ASTError "plus operation is not defined between num and str!"
                                                                                                        ASTJust (val2, "num", step2) -> ASTJust (show ((read(val1)::Int) + (read(val2)::Int)), "num", 1 + step1 + step2)
normalEvaluate (ASTNode (ASTSimpleDatum "times") op1 op2) bindList = let res1 = normalEvaluate op1 bindList
                                                                         res2 = normalEvaluate op2 bindList
                                                                     in case res1 of
                                                                        ASTError _ -> res1
                                                                        ASTJust(_, "str", _) -> case res2 of
                                                                                                    ASTError _ -> res2
                                                                                                    ASTJust (_, "str", _) -> ASTError "times operation is not defined between str and str!"
                                                                                                    ASTJust (_, "num", _) -> ASTError "times operation is not defined between str and num!"
                                                                        ASTJust(val1, "num", step1) -> case res2 of
                                                                                                        ASTError _ -> res2
                                                                                                        ASTJust (_, "str", _) -> ASTError "times operation is not defined between num and str!"
                                                                                                        ASTJust (val2, "num", step2) -> ASTJust (show ((read(val1)::Int) * (read(val2)::Int)), "num", 1 + step1 + step2)
normalEvaluate (ASTNode (ASTSimpleDatum "cat") op1 op2) bindList =   let res1 = normalEvaluate op1 bindList
                                                                         res2 = normalEvaluate op2 bindList
                                                                     in case res1 of
                                                                        ASTError _ -> res1
                                                                        ASTJust(_, "num", _) -> case res2 of
                                                                                                    ASTError _ -> res2
                                                                                                    ASTJust (_, "str", _) -> ASTError "cat operation is not defined between num and str!"
                                                                                                    ASTJust (_, "num", _) -> ASTError "cat operation is not defined between num and num!"
                                                                        ASTJust(val1, "str", step1) -> case res2 of
                                                                                                        ASTError _ -> res2
                                                                                                        ASTJust (_, "num", _) -> ASTError "cat operation is not defined between str and num!"
                                                                                                        ASTJust (val2, "str", step2) -> ASTJust (val1 ++ val2, "str", 1 + step1 + step2)
normalEvaluate (ASTNode (ASTSimpleDatum "negate") num EmptyAST) bindList = let res = normalEvaluate num bindList
                                                                           in case res of
                                                                             ASTError _ -> res
                                                                             ASTJust(_, "str", _) -> ASTError "negate operation is not defined on str!"
                                                                             ASTJust(val, "num", step) -> ASTJust(show(-1 * (read(val)::Int)), "num", step+1)
normalEvaluate (ASTNode (ASTSimpleDatum "len") str EmptyAST) bindList = let res = normalEvaluate str bindList
                                                                          in case res of
                                                                             ASTError _ -> res
                                                                             ASTJust(_, "num", _) -> ASTError "len operation is not defined on num!"
                                                                             ASTJust(val, "str", step) -> ASTJust(show(length val), "num", step+1)
--
normalEvaluate (ASTNode (ASTSimpleDatum var) EmptyAST EmptyAST) bindList = let binding = getNormalBinding bindList var
                                                                            in case binding of
                                                                                EmptyNormalBinding -> ASTError ("no variable named '" ++ var ++ "'!")
                                                                                NormalValue(_, tree) -> normalEvaluate tree bindList
--
normalEvaluate (ASTNode (ASTLetDatum var) left right) bindList = normalEvaluate right (addNormalBinding (NormalValue(var, left)) bindList)