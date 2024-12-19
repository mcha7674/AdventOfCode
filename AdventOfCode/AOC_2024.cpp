#include "AOC.h"

bool AOC_2024::Day3()
{
    /*
    --- Day 3: Mull It Over ---

    "Our computers are having issues, so I have no idea if we have any 
    Chief Historians in stock! You're welcome to check the warehouse, 
    though," says the mildly flustered shopkeeper at the North Pole 
    Toboggan Rental Shop. The Historians head out to take a look.

    The shopkeeper turns to you. "Any chance you can see why our
    computers are having issues again?"

    The computer appears to be trying to run a program, but its memory
    (your puzzle input) is corrupted. All of the instructions have been jumbled up!

    It seems like the goal of the program is just to multiply some numbers.
    It does that with instructions like mul(X,Y), where X and Y are each
    1-3 digit numbers. For instance, mul(44,46) multiplies 44 by 46 to get 
    a result of 2024. Similarly, mul(123,4) would multiply 123 by 4.

    However, because the program's memory has been corrupted, there are 
    also many invalid characters that should be ignored, even if they look
    like part of a mul instruction. Sequences like mul(4*, mul(6,9!, ?(12,34), 
    or mul ( 2 , 4 ) do nothing.

    For example, consider the following section of corrupted memory:

    xmul(2,4)%&mul[3,7]!@^do_not_mul(5,5)+mul(32,64]then(mul(11,8)mul(8,5))

    Only the four highlighted sections are real mul instructions. Adding up
    the result of each instruction produces 161 (2*4 + 5*5 + 11*8 + 8*5).

    Scan the corrupted memory for uncorrupted mul instructions. What do you 
    get if you add up all of the results of the multiplications?

    */

    // Breakdown - Grab each line from the file (Very large strings, may have to break 
    // this up). Read it into a string stream. Then, Call a get() function to go 
    // Character by character until I get to an "m". for each m found, check to make sure
    // it is also followed by "mul(". Once this is found, then
    std::vector<char> input;
    Load_Input("Input/2024/Day3.txt", input, 3);
    //Helpers::PrintVector(input, true);

    bool currToggle = true; // part 2 toggle
    long long int result = 0;
    vector<char>::const_iterator ci_start = input.begin();
    vector<char>::const_iterator ci_end = input.end();
    // Iterate through the array of characters
    for (auto c = ci_start;c != ci_end; ++c )
    {
        // parse do() and dont() functions
        if (*c == 'd' && *(++c) == 'o' &&
           *(++c) == '(' && *(++c) == ')')
        {
            currToggle = true;
            continue;
        }
        // For don't() only check for n't since we already checked for 'd' and 'o' above.
        if (*c == 'n' && *(++c) == '\'' && *(++c) == 't')
        {
            currToggle = false;
            continue;
        }
        // Parse mul() function
        if (*c == 'm' && *(++c) == 'u' &&
            *(++c) == 'l' && *(++c) == '(')
        {
            if (currToggle)
            {
                // These vars hold function arguments
                std::string num_str = "";
                int num1;
                int num2;
                // Extract the first number in the function
                // (Extract until I reach a comma)
                // NOTE: a d
                while (*(++c) != ',')
                {
                    // Only add to num_str if the char is an ASCII Digit
                    if ((*c >= '0' && *c <= '9'))
                    {
                        num_str += *c;
                    }
                    else { // If any other (non-digit) char was encountered before the delimitter ',' then the func is invalid.
                        num_str = "";
                        break;
                    }
                }
                // If nothing was added, the mul() function has been corrupted. 
                // Go back to iterating the sstream
                if (num_str == "") continue;
                num1 = std::stoi(num_str);
                num_str = ""; // reset num tring
                // Extract the second number in the function
                // (Extract until I reach a parenthesis)
                while (*(++c) != ')')
                {
                    if ((*c >= '0' && *c <= '9'))
                    {
                        num_str += *c;
                    }
                    else {
                        num_str = "";
                        break;
                    }
                }

                if (num_str == "") continue;
                num2 = std::stoi(num_str);
                num_str = "";
                result += (num1 * num2);
                std::cout << "mult: " << num1 * num2 << std::endl;
                std::cout << "Sum Result: " << result << std::endl;
            }
        }
    }

    std::cout << "\nDay3 Part 1 Answer: " << result << std::endl;
    std::cout << "\nDay3 Part 2 Answer: " << result << std::endl;

    /*
        --- Part Two ---

    As you scan through the corrupted memory, you notice that some of the conditional 
    statements are also still intact. If you handle some of the uncorrupted conditional
    statements in the program, you might be able to get an even more accurate result.

    There are two new instructions you'll need to handle:

        The do() instruction enables future mul instructions.
        The don't() instruction disables future mul instructions.

    Only the most recent do() or don't() instruction applies. At the beginning of the
    program, mul instructions are enabled.

    For example:

    xmul(2,4)&mul[3,7]!^don't()_mul(5,5)+mul(32,64](mul(11,8)undo()?mul(8,5))

    This corrupted memory is similar to the example from before, but this time the 
    mul(5,5) and mul(11,8) instructions are disabled because there is a don't() 
    instruction before them. The other mul instructions function normally, 
    including the one at the end that gets re-enabled by a do() instruction.

    This time, the sum of the results is 48 (2*4 + 8*5).

    Handle the new instructions; what do you get if you add up all of the results of 
    just the enabled multiplications?

    */
    return false;
}

bool AOC_2024::Day2()
{
    /*
    --- Day 2: Red-Nosed Reports ---

    Fortunately, the first location The Historians want to search isn't a long walk from the Chief Historian's office.

    While the Red-Nosed Reindeer nuclear fusion/fission plant appears to contain no sign of the Chief Historian,
    the engineers there run up to you as soon as they see you. Apparently, they still talk about the time 
    Rudolph was saved through molecular synthesis from a single electron.

    They're quick to add that - since you're already here - they'd really appreciate your help analyzing 
    some unusual data from the Red-Nosed reactor. You turn to check if The Historians are waiting for you, 
    but they seem to have already divided into groups that are currently searching every corner of the facility.
    You offer to help with the unusual data.

    The unusual data (your puzzle input) consists of many reports, one report per line. Each report is a list of
    numbers called levels that are separated by spaces. For example:

    7 6 4 2 1
    1 2 7 8 9
    9 7 6 2 1
    1 3 2 4 5
    8 6 4 4 1
    1 3 6 7 9

    This example data contains six reports each containing five levels.

    The engineers are trying to figure out which reports are safe. The Red-Nosed reactor safety systems 
    can only tolerate levels that are either gradually increasing or gradually decreasing. So, a report 
    only counts as safe if both of the following are true:

        The levels are either all increasing or all decreasing.
        Any two adjacent levels differ by at least one and at most three.

    In the example above, the reports can be found safe or unsafe by checking those rules:

        7 6 4 2 1: Safe because the levels are all decreasing by 1 or 2.
        1 2 7 8 9: Unsafe because 2 7 is an increase of 5.
        9 7 6 2 1: Unsafe because 6 2 is a decrease of 4.
        1 3 2 4 5: Unsafe because 1 3 is increasing but 3 2 is decreasing.
        8 6 4 4 1: Unsafe because 4 4 is neither an increase or a decrease.
        1 3 6 7 9: Safe because the levels are all increasing by 1, 2, or 3.

    So, in this example, 2 reports are safe.

    Analyze the unusual data from the engineers. How many reports are safe?

    */

    // Breakdown - Each line is a report. A report is safe if it is gradually increasing/decreasing. "Gradual" is defined
    // as a delta of [1, 3]. Fact: The direction of the delta is defined by the first 2 digits, if it changes from that at 
    // any point, it is marked unsafe. If ADJACENT values differ by more than 3, it is unsafe. If there are any duplicates
    // (Change of 0) it is also unsafe. Count the number of safe reports (Number of valid lines).

    // IMPLEMENTATION

    // Load the reports
    vector<vector<int>> reports; // a report is a vector integers
    Load_Input("Input/2024/Day2.txt", reports, 2);
    // Iterate through every report and increment a safe or unsafe report
    int unsafeCount = (int)reports.size(); // assume all reports are unsafe at first
    int safeCount = 0;
    int safeCount_with_dampener = 0;
    for (int r = 0; r < reports.size(); r++)
    {
        // Iterate through data within a report
        vector<int>& report = reports[r];
        int decCount = 0;
        int incCount = 0;
        for (int d = 0; d < report.size() - 1; d++)
        {
            if ((report[d] > report[d + 1]) && (report[d] - report[d + 1] <= 3)) // gradually decreasing. Second condition handles [1,3] diff
            {
                if (incCount != 0) break;
                decCount += 1;
            }
            else if ((report[d] < report[d + 1]) && (report[d + 1] - report[d] <= 3)) // gradually increasing
            {
                if (decCount != 0) break;
                incCount += 1;
            }
            else break;
        }

        if (decCount == report.size() - 1 || incCount == report.size() - 1)
        {
            safeCount++;
            unsafeCount--;
        }
        else // report is unsafce, remove one and reanalyze
        {
            // Report was deemed unsafe...remove a value and reanalyze
            // Removing the ith level and check the remaining list. if it now 
            // passes, it is safe. If it fails, re-institute the ith digit and 
            // try again, I dont have to remove it, just skip it.
            // 
            int currExaminedLvl = 0;
            //std::cout << " ===Analyzing Unsafe Report for Dampening===" << std::endl;
            //Helpers::PrintVector(report);
            while (true) // Skip each level once and verify that it can be safe now
            {
                /*std::cout << "Current Examined Level: "<< currExaminedLvl << 
                    "(" << report[currExaminedLvl] << ")" << std::endl;*/
                int decCount_damp = 0;
                int incCount_damp = 0;
                for (int j = 0; j < report.size() - 1; j++)
                {
                    if (j == currExaminedLvl) continue; // Skip currently examined level
                    // if j+1 is == to currLevel (the "removed" level) AND the next level does not 
                    // cause an overflow, then set the next level to be the next level + 1th level.
                    int next = 1;
                    if ((j+ next) == currExaminedLvl && ((j+ next+1) < report.size()))  next = 2;
                    if ((report[j] > report[j + next]) && (report[j] - report[j + next] <= 3)) // gradually decreasing. Second condition handles [1,3] diff
                    {
                        if (incCount_damp != 0)
                        {
                            break;
                        }
                        decCount_damp += 1;
                    }
                    else if ((report[j] < report[j + next]) && (report[j + next] - report[j] <= 3)) // gradually increasing
                    {
                        if (decCount_damp != 0)
                        {
                            break;
                        }
                        incCount_damp += 1;
                    } 
                    else
                    {
                        break;
                    }
                }
                // If this is true, then the report is now valid, break.
                if (decCount_damp == report.size() - 2 || incCount_damp == report.size() - 2)
                {
                    //std::cout << "REPORT IS NOW SAFE" << std::endl;
                    safeCount_with_dampener++;
                    unsafeCount--;
                    break;
                }
                else // Report still unsafe, increment level to "skip"
                {
                    //std::cout << "REPORT IS STILL UNSAFE" << std::endl;
                    currExaminedLvl++;
                }

                if (currExaminedLvl == report.size()) break;
            }
            
        }
        

    }
    int dampenedResult = safeCount + safeCount_with_dampener;
    std::cout << "Reports: " << reports.size() << std::endl;
    std::cout << "\nDay2 Part 1 Answer: " << safeCount << " safe reports" << std::endl;
    std::cout << "\nDay2 Part 2 Answer: " << dampenedResult << " safe reports with Dampener" << std::endl;

    /*
    --- Part Two ---

    The engineers are surprised by the low number of safe reports until they realize they forgot 
    to tell you about the Problem Dampener.

    The Problem Dampener is a reactor-mounted module that lets the reactor safety systems tolerate a 
    single bad level in what would otherwise be a safe report. It's like the bad level never happened!

    Now, the same rules apply as before, except if removing a single level from an unsafe report would 
    make it safe, the report instead counts as safe.

    More of the above example's reports are now safe:

        7 6 4 2 1: Safe without removing any level.
        1 2 7 8 9: Unsafe regardless of which level is removed.
        9 7 6 2 1: Unsafe regardless of which level is removed.
        1 3 2 4 5: Safe by removing the second level, 3.
        8 6 4 4 1: Safe by removing the third level, 4.
        1 3 6 7 9: Safe without removing any level.

    Thanks to the Problem Dampener, 4 reports are actually safe!

    Update your analysis by handling situations where the Problem Dampener can remove a single level 
    from unsafe reports. How many reports are now safe?

    */

    // Breakdown - This is solved above

    
    return true;
}


bool AOC_2024::Day1()
{
	/* PROMPT - HistorianHysteria

	The Chief Historian is always present for the big Christmas sleigh launch, but nobody has seen him in months! 
    Last anyone heard, he was visiting locations that are historically significant to the North Pole; a group of 
    Senior Historians has asked you to accompany them as they check the places they think he was most likely to visit.

    As each location is checked, they will mark it on their list with a star. They figure the Chief Historian must 
    be in one of the first fifty places they'll look, so in order to save Christmas, you need to help them get fifty 
    stars on their list before Santa takes off on December 25th.
    
    Collect stars by solving puzzles. Two puzzles will be made available on each day in the Advent calendar; the 
    second puzzle is unlocked when you complete the first. Each puzzle grants one star. Good luck!
    
    You haven't even left yet and the group of Elvish Senior Historians has already hit a problem: their list of 
    locations to check is currently empty. Eventually, someone decides that the best place to check first would be the Chief Historian's office.
    
    Upon pouring into the office, everyone confirms that the Chief Historian is indeed nowhere to be found. 
    Instead, the Elves discover an assortment of notes and lists of historically significant locations! This seems 
    to be the planning the Chief Historian was doing before he left. Perhaps these notes can be used to determine which locations to search?
    
    Throughout the Chief's office, the historically significant locations are listed not by name but by a unique 
    number called the location ID. To make sure they don't miss anything, The Historians split into two groups, 
    each searching the office and trying to create their own complete list of location IDs.
    
    There's just one problem: by holding the two lists up side by side (your puzzle input), it quickly becomes 
    clear that the lists aren't very similar. Maybe you can help The Historians reconcile their lists?
    
    For example:
    
    3   4
    4   3
    2   5
    1   3
    3   9
    3   3
    
    Maybe the lists are only off by a small amount! To find out, pair up the numbers and measure how far apart they are. Pair up the smallest number in the left list with the smallest number in the right list, then the second-smallest left number with the second-smallest right number, and so on.
    
    Within each pair, figure out how far apart the two numbers are; you'll need to add up all of those distances. For example, if you pair up a 3 from the left list with a 7 from the right list, the distance apart is 4; if you pair up a 9 with a 3, the distance apart is 6.
    
    In the example list above, the pairs and distances would be as follows:
    
        The smallest number in the left list is 1, and the smallest number in the right list is 3. The distance between them is 2.
        The second-smallest number in the left list is 2, and the second-smallest number in the right list is another 3. The distance between them is 1.
        The third-smallest number in both lists is 3, so the distance between them is 0.
        The next numbers to pair up are 3 and 4, a distance of 1.
        The fifth-smallest numbers in each list are 3 and 5, a distance of 2.
        Finally, the largest number in the left list is 4, while the largest number in the right list is 9; these are a distance 5 apart.
    
    To find the total distance between the left list and the right list, add up the distances between all of the pairs you found. 
    In the example above, this is 2 + 1 + 0 + 1 + 2 + 5, a total distance of 11!
    
    Your actual left and right lists contain many location IDs. What is the total distance between your lists?
	*/

    // Load the Input
    vector<int> location_ids;
    Load_Input("Input/2024/Day1.txt", location_ids, 1);

    // Process the input
    vector<int> left_col;
    vector<int> right_col;
    int i = 0;
    for (auto location_id : location_ids)
    {
        // 0 + even numbers are the left column of the input, odd numbers are the right column
        if (i == 0 || i % 2 == 0) // Left Column
        {
            left_col.push_back(location_id);
        }
        else // Right Column
        {
            right_col.push_back(location_id);
        }

        i++;
    }

    // Sort Left column vector
    Helpers::HeapSort_Vect(left_col);
    //Helpers::PrintVector(left_col);

    // Sort Right column vector
    Helpers::HeapSort_Vect(right_col);

    // Find the distance between each of the sorted arrays and sum them up!
    int sum = 0;
    for (int i = 0; i < left_col.size(); i++)
    {
        int leftVal = left_col[i];
        int rightVal = right_col[i];
        int dist = 0;
        if (rightVal > leftVal)
        {
            dist = rightVal - leftVal;
        }
        else {
            dist = leftVal - rightVal;
        }
        sum += dist;
    }

    std::cout << "\nDay1 Part 1 Answer: " << sum << std::endl;

    /*
        --- Part Two ---

    Your analysis only confirmed what everyone feared: the two lists of location IDs are indeed very different.

    Or are they?

    The Historians can't agree on which group made the mistakes or how to read most of the Chief's handwriting,
    but in the commotion you notice an interesting detail: a lot of location IDs appear in both lists! Maybe 
    the other numbers aren't location IDs at all but rather misinterpreted handwriting.

    This time, you'll need to figure out exactly how often each number from the left list 
    appears in the right list. Calculate a total similarity score by adding up each number
    in the left list after multiplying it by the number of times that number appears in the right list.

    Here are the same example lists again:

    3   4
    4   3
    2   5
    1   3
    3   9
    3   3

    For these example lists, here is the process of finding the similarity score:

        The first number in the left list is 3. It appears in the right list three times, so the similarity score increases by 3 * 3 = 9.
        The second number in the left list is 4. It appears in the right list once, so the similarity score increases by 4 * 1 = 4.
        The third number in the left list is 2. It does not appear in the right list, 
        so the similarity score does not increase (2 * 0 = 0).
        The fourth number, 1, also does not appear in the right list.
        The fifth number, 3, appears in the right list three times; the similarity score increases by 9.
        The last number, 3, appears in the right list three times; the similarity score again increases by 9.

    So, for these example lists, the similarity score at the end of this process is 31 (9 + 4 + 0 + 0 + 9 + 9).

    Once again consider your left and right lists. What is their similarity score?
    
    */

    // What's an efficient way to search my sorted lists and count how much 1 number on the left shows up on the right?
    // Sorted example:
    // 1 3 3 6 7 8 (LEFT)
    // 2 3 3 4 5 9 (RIGHT)
    // Maybe, start with the smallest element on the left  we much search the right array and count how many there are. Each time 
    // I find a match, I can efficiently make it negative (Do this on a copy of the array).
    vector<int> right_col_original = right_col;
    int finalSimilarityScore = 0;
    for (int i = 0; i < left_col.size(); i++)
    {
        int currentSimilarityScore = 0;
        int leftVal = left_col[i];
        int rightVal = right_col[i];
        // WHen searching the right array, Only search on the segment of the 
        // array that is either left or right of the left value
        int low = 0;
        int high = right_col.size();
        if (leftVal < rightVal) high = i;
        else if (leftVal > rightVal) low = i;
        // in the case where leftVal == rightVal, search the whole right array
        int matchCount = 0;
        int index = 0;
        
        while (Helpers::BinarySearch_Vect(right_col, low, high, leftVal, index))
        {
            right_col.erase(right_col.begin() + index); // so that I don't find that particular one again
            matchCount++;
        }
        // Calculate Score
        currentSimilarityScore = leftVal * matchCount;
        finalSimilarityScore += currentSimilarityScore;
        // Reset right Col
        right_col = right_col_original;

    }

    std::cout << "\nDay1 Part 2 Answer: " << finalSimilarityScore << std::endl;


    // Is Problem Solved?
    return true;
}




