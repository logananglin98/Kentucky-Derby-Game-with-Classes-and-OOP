# L3: Virtual Pets

## Starter code created by Dr. Jan Pearce to explore interacting classes, arrays, and pseudo-randomness
## Created for CSC 236 Data Structures at Berea College
## Original Author: Jan Pearce, Berea College

### Authors:

- Logan Anglin

1. **HIGH LEVEL DESIGN** and **CRC Cards**
*Complete the high-level design components and the the CRC Cards in the linked Google Doc. Submission is via Moodle.*
*Paste link to completed Google Doc here.*

https://docs.google.com/document/d/1ni0hkkfMJ1aLrCYgo14ZLZZte1p3_xZZkI20qVEdNYE/edit?usp=sharing

2. **CLASSES**
*How much difficulty did you have figuring out how to create classes and get them to interact? Did the diceroll example help?*

Most of this lab wasn't too awful. The diceroll class did give me ideas for implementing the two classes I created, though I had to figure out
how to pass a class as a parameter into methods of another class.

3. **OOP USABILITY**
*Was there anything that you tried that did not work? Explain.*

I was able to have the Jockey class directly interact with the Horse class because I declared it second, but doing the opposite proved to be
a problem becuase of the order the classes were declared. I had to work around this in the main method.

4. **Big O Analysis**
*Analyze the Big O of all components of your program. This means:*
- *Analyze the Big O of all of the methods of your classes, including constructors.*
- *Also analyze the main() function and any auxillary functions.*

As far as I know, the methods in this program are all O(1) or constant. The while loop in the main function I believe is O(n) or linear.


5. **PROCESS SUMMARY**
*Briefly summarize your design and implementation process,
including how much your initial design plan evolved,
the final results you achieved, and the amount of time you spent
as a programmer or programmers in accomplishing these results.
This should be one or at most two paragraphs.*

I had originally planned on the main horse and jockey racing another horse and jockey, but decided to keep it to only one set due to time.
Instead, I imagine this program simulating a jockey taking a horse for something of a test drive to see how fast it can complete a lap 
without giving in to exhaustion.

6. **DESIGN CHALLENGES**
*Describe the primary conceptual challenges that you encountered
in trying to complete this lab and what might have made the
lab easier for you.*

The math for some of the methods ended up not working the way I would like it to. Specifically, the method that controls the exhaustion level
proved to be problematic. I toyed with many multipliers and variations of how it works, but never got an implementation that truly matched 
the idea I had in my head. Instead, I got something that at least kind of does what I want.

7. **ERRORS**
*List in bulleted form of all known errors
and deficiencies with a very brief explanation.*

- There is no code that makes sure the user enters inputs that match the data types the inputs request. They are char and int inputs, 
respectively, and a user could break the program by not entering the right data type.
- It is possible for the user to decrease the speed so much, the speed value goes negative and the horse presumably starts going in reverse.
Kind of funny, and it may be considered erroneos, but I like the idea of the user being able to do this.

8. **LEARNING AND REACTION**
*A paragraph or so of your own comments
on what you learned and your reactions to this lab.*

I will confess some things here. Because of the conference I went to this week and about a dozen other time constraints, I ended up working on
this homework and a lot of other homework for this week during one day. I learned how much more difficult and aggravating programming can be
when not spread out over a few days the way I normally work on homework for this class. Rushing leads to poor quality code, and while my 
code works for the most part, I fully acknowledge it could be better, more efficient, and follow conventions better.

9. **PAIR-PROGRAMMING STATEMENT**
If you worked in a pair of programmers, you are required to use good pair programming practices, always working together and not using a divide and conquer technique in which only one of you does the work and learns. Also, the two programmers roles should be switched frequently--around every 20 minutes or so. If you worked alone, please say so. If you worked in a pair, please describe how you worked together.

I worked alone.

10. **INTEGRITY STATEMENT**
*Please briefly describe ALL help the authors received and
all help the aurthors gave to others in completing this lab.
Also list all other references below.*

Dr. Pearce's starting code made things so much easier.

11. **REFERENCES**
- This repo contains original work by Jan Pearce
- Add additional reference(s) to ALL work that inspired this submission OR state that this is entirely original work.*

https://stackoverflow.com/questions/56954277/c-interaction-between-two-classes-in-a-function
https://www.w3schools.com/cpp/cpp_classes.asp
https://runestone.academy/ns/books/published/bc_cppds_s24/Introduction/ObjectOrientedProgrammingDefiningClasses.html
