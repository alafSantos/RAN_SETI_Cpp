# RAN_SETI_Cpp
Embedded Systems and Information Processing, Institut Polytechnique de Paris Master 2 program.


## TP

### Question 5
It was possible to achieve the following:
- Execution time when using vector: 2 seconds
- Execution time when using list: 0.5 seconds

Basically the reason for the difference between list time execution and vector time execution is the way vectors and lists work. Vectors store the data sequentially while lists do not. Each element of a list has the address of the next and the previous ones so they can "jump" into another position simulating some kind of continuity. On the other hand, vectors are always continuous so when we delete a position, some components of the vector need to be moved in order to keep sequence. And in the code, we got a lot of data retrieving, so the vector keeps being rearranged.


## Exam
