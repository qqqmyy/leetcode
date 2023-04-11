cmake_minimum_required(VERSION 3.15)
project(leetcode_zjy)

set(CMAKE_CXX_STANDARD 17)

add_executable(leetcode_zjy main.cpp test.h test.cpp LongestSubStr.h LongestSubStr.cpp Median.h Median.cpp
        Palindrome.h Palindrome.cpp MaxArea.h MaxArea.cpp ThreeSumSol.h ThreeSumSol.cpp LetterCombinationsSol.h LetterCombinationsSol.cpp
        CMyString.h CMyString.cpp generateParenthesisSol.h generateParenthesisSol.cpp removeNthFromEndSol.h removeNthFromEndSol.cpp
        mergeTwoListsSol.h mergeTwoListsSol.cpp nextPermutationSol.h nextPermutationSol.cpp permuteSol.h permuteSol.cpp climbStairsSol.h
        climbStairsSol.cpp mergeSol.h mergeSol.cpp existSol.h existSol.cpp topKFrequentSol.h topKFrequentSol.cpp myString.h myString.cpp
        ArrayQueue.cpp CallStackOverFlow.cpp LinkListQueue.cpp ListQueue.cpp learnTemplate.cpp VectorPQueue.cpp)