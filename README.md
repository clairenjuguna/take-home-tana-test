Take-Home Tana Technical Assessment
🛠 Language
All solutions are written in C++17, using STL for clean and efficient code.

📌 Overview
This repo includes my solutions to the Tana take-home coding test. The problems range from string manipulation to array processing and basic algorithmic challenges. Each solution is standalone, well-commented, and includes sample inputs in the main() function.

✅ Summary of Solutions
🧩 Question 1 – Longest Valid String
Finds the longest substring made only of allowed characters with no duplicates.

➕ Question 2 – Unique Sums
Calculates all unique pairwise sums from an input array and returns them sorted.

🔁 Question 3 – Array Reduction
Counts the number of steps needed to reduce all array elements to zero by repeatedly subtracting the smallest non-zero value.

🛒 Question 4 – First Unique Product
Returns the first product in a list that appears only once.

📏 Question 5 – Closest Minimum Distance
Finds the shortest distance between two identical minimum values in an array.

🔤 Question 6 – Top 3 Common Words
Analyzes word frequency in a sentence and returns the top three most common ones, sorted alphabetically in case of ties.

🔄 Question 7 – Rotate List
Rotates a list of string IDs to the right by k positions. It handles any k, even larger than the list size.

▶️ Running the Code
Each solution is in its own .cpp file and can be compiled and run like this:


g++ -std=c++17 filename.cpp -o program
./program
For example, to run the solution for Question 4:


g++ -std=c++17 firstUniqueProduct.cpp -o run
./run